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

    j = vetor[n - 1];
    
    for(i = n; i > 0 ; i--)
    {
        vetor[i] = vetor[i - 1];        
    }
    
    vetor[0] = j;

    for(i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }

    return 0;
}