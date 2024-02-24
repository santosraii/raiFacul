#include <stdio.h>

int main()
{
    int n, notas[50], i, menorn = 10, segundamenorn = 10;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &notas[i]);
        if (notas[i] >= 0 && notas[i] <= 10 && notas[i] <= menorn)
        {
            menorn = notas[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (notas[i] < segundamenorn && notas[i] > menorn)
        {
            segundamenorn = notas[i];
        }
    }
    printf("%d\n", segundamenorn);
    return 0;
}