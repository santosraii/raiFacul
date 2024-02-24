#include <stdio.h>

int main()
{
    int x, i, soma = 0;

    scanf("%d", &x);

    for (i = 0; i < x; i++)
    {
        if ( i % 3 == 0 || i % 5 == 0)
        {
            soma = soma + i;
        }
    }
    printf("%d\n", soma);

    return 0;
}