#include <stdio.h>

int main()
{
    int n, i, j, nota;
    scanf("%d", &n);

    int frequencia[20] = {0};

    for (i = 0; i < n; i++)
    {
        scanf("%d", &nota);
        if (nota >= 0 && nota <= 10)
        {
            frequencia[nota]++;
        }
    }
    for (i = 0; i < 11; i++)
    {
        printf("%d ", frequencia[i]);
    }
    return 0;
}