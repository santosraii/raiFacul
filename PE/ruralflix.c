#include <stdio.h>

int maior = 0;
typedef struct
{
    int id_videos;
    int usuarios[1000];
    int tam_usuarios;
}RURALFLIX;

void avaliar(int id_usuario, RURALFLIX *video)
{
    for(int i = 0; i < video->tam_usuarios; i++)
    {
        if(video->usuarios[i] == id_usuario)
        {
            return;
        }
    }
    video->usuarios[id_usuario - 1] = id_usuario;

    video->tam_usuarios++;
    if(video->tam_usuarios > maior)
    {
        maior = video->tam_usuarios;
    }
}

int main()
{
    char arquivo[16];

    scanf("%s", arquivo);

    FILE *document;

    document = fopen(arquivo, "r");

    if(document == NULL)
    {
        printf("Não é possível abrir o arquivo");
        return 1;
    }

    int i, j, usuarios, videos, aval, id_usuario, id_video, vetor_a[1000] = {0}, nota, q_videos = 0;
    RURALFLIX v[1000];

    fscanf(document, "%d %d %d", &usuarios, &videos, &aval);
    
    for(i = 0; i < aval; i++)
    {
        fscanf(document, "%d %d %d", id_usuario, id_video, nota);
        if(vetor_a[id_video - 1] == 0)
        {
            vetor_a[id_video - 1] = 1;
            v[id_video - 1].id_videos = id_video;
            v[id_video - 1].tam_usuarios = 0;
        }
        avaliar(id_usuario, &v[id_video - 1]);
        if(id_video > q_videos)
        {
            q_videos = id_video;
        }
    }

    for(j = 0; j < q_videos; j++)
    {
        if(v[j].tam_usuarios == maior)
        {
            printf("%d", v[j].id_videos);
        }
    }

    return 0;
}