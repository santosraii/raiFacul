#include<stdio.h>
#include<string.h>


int main(void)
{
    int j, tam = 0;
    char frase[101], arq[31];

    FILE *arquivo;

    scanf("%s", arq);

    arquivo = fopen(arq, "r");

    if(arquivo == NULL)
    {
        printf("Não é possível abrir o arquivo");
        return 1;
    }

    while(!feof(arquivo))
    {
        fgets(frase, 100, arquivo);

        while(frase[tam] != '\0')
        {
        for(j = tam; j >= 0; j--)
        {
            printf("%c", frase[j]);
        }
            tam++;
        }
        printf("\n");
        fclose(arquivo);
    }
    return 0;
}