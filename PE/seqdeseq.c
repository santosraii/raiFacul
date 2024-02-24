#include <stdio.h>

int somatorio(int a)
{
    int resultado = 0, i;
    for(i = 1; i <= a; i++)
    {
        if(a == 1)
        {
            return 1;
        }
        return a + somatorio(a - 1);
    }
}

int main()
{
    int x, n, i, j, k;

    scanf("%d", &x);

    for(i = 1; i <= x; i++)
    {
        scanf("%d", &n);
        if(n == 0)
        {
            printf("Caso %d: 1 numero\n", i);
        }
        else
        {
            printf("Caso %d: %d numeros\n", i, somatorio(n) + 1);
        }
        printf("0 ");

        for(j = 1; j <= n; j++)
        {
            for(k = 0; k < j; k++)
            {
                printf("%d ", j);
            }
        }
        printf("\n");
    }

    return 0;
}