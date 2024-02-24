#include <stdio.h>

int main()
{
    int n, j, i, aux, a;
    char frase[100];

    scanf("%d", &n);

    
    for(i = 0; i < n; i++)
    {
        scanf("%s", frase);
        
        for(j = 0; frase[j] != '\0'; j++)
        {
            if(frase[j] >= 'a' && frase[j] <= 'z' || frase[j] >= 'A' && frase[j] <= 'Z')
            {
                frase[j] = frase[j] + 3;
            }

        }
        aux = j;
        
        for(j = 0; j < aux / 2; j++)
        {
            a = frase[j];
            frase[j] = frase[aux - 1 - j];
            frase[aux - 1 - j] = a;
        }

        for(j = aux / 2; frase[j] != '\0'; j++)
        {
            frase[j] = frase[j] - 1;
        } 

        printf("%s\n", frase);
    }

    return 0;
}