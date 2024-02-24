#include <stdio.h>

int main()
{
    int n, i, menornum = 1000, pos = 0;

    scanf("%d", &n);
    int vetor[n];

    for(i = 0; i < n ; i++)
    {
        scanf("%d", &vetor[i]);
        if (vetor[i] < menornum)
        {
            menornum = vetor[i];
            pos = i;
        }
    }
    printf("Menor valor: %d\nPosicao: %d\n", menornum, pos);
    return 0;
}