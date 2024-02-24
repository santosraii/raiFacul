#include <stdio.h>

int main()
{
    FILE *document;


    document = fopen("arquivo.txt", "r");
    char nome[51];
    int i, testes;
    float n1, n2, media; 
    
    fscanf(document, "%d", &testes);
    for(i = 0; i < testes; i++)
    {
        fscanf(document, " %[^\n] %f %f", nome, &n1, &n2);
        media = (n1 + n2)/2;
        if(media >= 7.0)
        {
            printf("%s\n", nome);
        }
    }

    fclose(document);
    return 0;
}
