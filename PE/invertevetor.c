#include <stdio.h>

int main()
{
    int n, i, j;

    scanf("%d", &n);

    int vetor[n];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < n / 2; i++)
    {
        j = vetor[i];
        vetor[i] = vetor[n - 1 - i];
        vetor[n - 1 - i] = j;
    }
    for(i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }

    return 0;
}