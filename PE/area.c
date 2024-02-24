#include <stdio.h>
#define n 3.14159

int main()
{
    double area, raio;
    scanf("%lf", &raio);
    area = raio * raio * n;
    printf("A = %.4lf", area);
    
    return 0;
}