#include <stdio.h>

int main()
{
    int n, i, quadrado;

    scanf("%d", &n);

    for (i = 2; i <= n; i++)
    {
        if(i % 2 == 0)
        {
            quadrado = i*i;
            printf("%d^2 = %d\n", i, quadrado);
        }
    }
    return 0;
}