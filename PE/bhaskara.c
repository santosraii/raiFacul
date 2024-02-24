#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, c, delta, r1, r2;
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    
    if (a == 0)
    {
        printf("Impossivel calcular");
        return 0;
    }
    delta = ((b*b) - (4 * a * c));
    
    if (delta < 0)
    {
        printf("Impossivel calcular");
        return 0;
    }
    r1 = (- b + sqrt(delta))/(2 * a);
    r2 = (- b - sqrt(delta))/(2 * a);
    
    printf("R1 = %.5lf\n", r1);
    printf("R2 = %.5lf", r2);
    return 0;
}