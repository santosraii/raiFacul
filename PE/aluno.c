#include <stdio.h>

int main()
{
    FILE *document;


    document = fopen("arquivo.txt", "r");
    char nome[51];
    float n1, n2, media;
  
    while(fscanf(document, " %[^;]%*c %f; %f;", nome, &n1, &n2) == 3)
    {
        media = (n1 + n2)/2;
        printf("%s %.1f %.1f %.1f ", nome, n1, n2, media);
        if(media >= 7.0)
        {
            printf("aprovado");
        }
        printf("\n");
    }
    fclose(document);

    return 0;
}