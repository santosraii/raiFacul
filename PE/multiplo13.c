#include <stdio.h>

int main()
{
    int x, y, i, soma = 0, troca;

    scanf("%d\n%d", &x, &y);

    if (x > y)
    {
        troca = x;
        x = y;
        y = troca;
    }
    for (i = x; i <= y; i++)
    {
        if (i % 13 != 0)
        {
            soma = soma + i;
        }
    }
    printf("%d\n", soma);

    return 0;
}