#include <stdio.h>

int main()
{
    int n, i, d = 0;

    scanf("%d", &n);

    for (i = 2; i <= n; i++)
        if (n % i == 0)
        {
            d++;
        }
    if (d == 1)
    {
        printf("primo\n");
    }

    else
    {
        printf("nao\n");
    }
    return 0;
}