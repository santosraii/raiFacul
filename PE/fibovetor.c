#include <stdio.h>

int main()
{
    int testes, i, n_esimo;
    int fibo[70];
    
    scanf("%d", &testes);
    
    for (i = 1; i <= 65; i++)
    {
        fibo[0] = 0;
        fibo[1] = 1;
        fibo[i] = fibo[i-2] + fibo[i-1];
    }
    for (i = 0; i < testes; i++)
    {
        scanf("%d", &n_esimo);
        printf("Fib(%d) = %d\n", n_esimo, fibo[n_esimo]);
    }
    return 0;
}