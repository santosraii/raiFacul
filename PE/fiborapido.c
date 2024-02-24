#include <stdio.h>
#include <math.h>

/*float fiborapido(float n)
{
    float fibo = pow( ( (1 + sqrt(5)) / 2), n) - pow( ( (1 - sqrt(5)) / 2), n) / sqrt(5);
    return fibo;
}*/
int main()
{
    float n;

    scanf("%f", &n);
    float fibo = (pow((1+sqrt(5))/2,(float)n)-pow((1-sqrt(5))/2,(float)n))/sqrt(5);
    printf("%f", fibo);

    return 0;
}