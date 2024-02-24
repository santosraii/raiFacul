#include <stdio.h>

int main()
{
    double a, b, c;
    
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);
    
    if (a >= b && a >= c)
    {
        if (a >= b + c)
            printf("NAO FORMA TRIANGULO\n");
    
        else if ((a*a) == (b*b) + (c*c))
                printf("TRIANGULO RETANGULO\n");
                
        else if ((a*a) > (b*b) + (c*c))
            printf("TRIANGULO OBTUSANGULO\n");
            
        else if ((a*a) < (b*b) + (c*c))
            printf("TRIANGULO ACUTANGULO\n");
    }
    
    else if (b >= a && b >= c)
    {
        if (b >= a + c)
            printf("NAO FORMA TRIANGULO\n");
            
        else if ((b*b) == (a*a) + (c*c))
                printf("TRIANGULO RETANGULO\n");
                
        else if ((b*b) > (a*a) + (c*c))
            printf("TRIANGULO OBTUSANGULO\n");
            
        else if ((b*b) < (a*a) + (c*c))
            printf("TRIANGULO ACUTANGULO\n");
    }
    
    else if (c >= a && c >= b)
    {
        if (c >= a + b)
            printf("NAO FORMA TRIANGULO\n");
            
        else if ((c*c) == (a*a) + (b*b))
                printf("TRIANGULO RETANGULO\n");
                
        else if ((c*c) > (a*a) + (b*b))
            printf("TRIANGULO OBTUSANGULO\n");
            
        else if ((c*c) < (a*a) + (b*b))
            printf("TRIANGULO ACUTANGULO\n");
    }
    
    if (a == b && a == c && b == c)
    {
        printf("TRIANGULO EQUILATERO\n");
    }   

    if (a == b && a != c )
        printf("TRIANGULO ISOSCELES\n");
    if (a == c && a != b )
        printf("TRIANGULO ISOSCELES\n");
    if (b == c && b != a )
        printf("TRIANGULO ISOSCELES\n");

    return 0;
}
