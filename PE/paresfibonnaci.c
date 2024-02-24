#include <stdio.h>

int main()
{
    int x, i, fibo = 0, fibo1 = 0, fibo2 = 1, somapar = 0;

    scanf("%d", &x);

    fibo = fibo1 + fibo2;
    while(fibo < x)
    {
        fibo1 = fibo2;
        fibo2 = fibo;
        if (fibo % 2 == 0)
        {
            somapar = somapar + fibo;
        }
        fibo = fibo1 + fibo2;
    }
    printf("%d\n", somapar);

    return 0;
}