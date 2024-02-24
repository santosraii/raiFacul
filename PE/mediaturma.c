#include <stdio.h>

int main()
{
    int n, i, soma = 0, esquece = 0, notas[100];
    float media;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &notas[i]);
        if (notas[i] > 10 || notas[i] < 0)
        {
            esquece = esquece + 1;
        }
        else
        {
            soma += notas[i];
        }
    }
    media = (float)soma/(n - esquece);
    printf("%.1f\n", media);
    return 0;
}