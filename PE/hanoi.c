#include <stdio.h>

void hanoi(int pino1, int pino2, int pino3, int n)
{
    if(n > 0)
    {
        hanoi(pino1, pino3, pino2, n - 1);
        printf("%d %d\n", pino1, pino2);
        hanoi(pino3, pino2, pino1, n - 1);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    hanoi(1, 3, 2, n);

    return 0;
}