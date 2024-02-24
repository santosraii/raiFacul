#include <stdio.h>

int main()
{

    char vetor[201];
    int n, i, j, k;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        int maior = 0, vetor_alf[26] = {0}; // vetor de letras do alfabeto
        scanf(" %[^\n]", vetor);
        for (j = 0; vetor[j] != '\0'; j++)
        {
            if(vetor[j] >= 'A' && vetor[j] <= 'Z') // verificar se uma letra do vetor é maiuscula
            {
                vetor_alf[vetor[j] - 'A']++; // somando no vetor_alf na posição da letra
                if(vetor_alf[vetor[j] - 'A'] > maior)
                {
                    maior = vetor_alf[vetor[j] - 'A'];
                }
            }
            else if(vetor[j] >= 'a' && vetor[j] <= 'z')
            {
                vetor_alf[vetor[j] - 'a']++;
                if(vetor_alf[vetor[j] - 'a'] > maior)
                {
                    maior = vetor_alf[vetor[j] - 'a'];
                }
            }  
        }

        // A B C D E
        // 0 1 2 3 4

        for(k = 0; k < 26; k++)
        {
            if(vetor_alf[k] == maior)
            {
                printf("%c", k + 'a');
            }
        }
    }
}