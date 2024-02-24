#include <stdio.h>

int main()
{
    int x, y, soma, i;

    soma = 0;

    scanf("%d", &x);
    scanf("%d", &y);
    
    if (y < x)
    {
        int a = x;
        x = y;
        y = a;
    }
    for (i = x + 1; i < y; i++)
    {
        if (i % 2 != 0)
        {
            soma = soma + i;
        }
    }
    printf("%d\n", soma);
    return 0;
}