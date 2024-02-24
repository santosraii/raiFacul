#include<stdio.h>

int main(void) {
    
    char arquivo[16];
    int usuarios, videos, aval, i = 0;

    FILE *document;
    scanf("%s", arquivo);

    document = fopen(arquivo, "r");
    if(document == NULL)
    {
        printf("Não é possível abrir o arquivo");
        return 1;
    }

    fscanf(document,"%d %d %d", &usuarios, &videos, &aval);

    int id_usuario, id_video, vetor_a[1000] = {0}; 
    float nota, soma[1000] = {0}, media, maiornota = 0;

    while(i < aval)
    {
        fscanf(document, "%d %d %f", id_usuario, id_video, nota);
        soma[id_video] = soma[id_video] + nota; //mandar pra vista de prova
        i++;
        vetor_a[id_video]++; //mandar pra vista de prova
    }
    
    for(int j = 0; j < 1000; j++)
    {
        media = soma[j] / vetor_a[j];
        if(vetor_a[j] >= 0.1 * usuarios)
        {
            if(maiornota < media)
            {
                maiornota = media;
                id_video = j;
            }
            media = 0;
        }
    }
    
    printf("%d", id_video);

    fclose(document);

    return 0;
}