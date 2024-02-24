#include <stdio.h>

int main()
{
    double n;
    scanf("%lf", &n);
    
    if(0 <= n && n <= 25.0000)
    {
        printf("Intervalo [0,25]");
        return 0;
    }
    else if(25.0000 < n && n <= 50.0000)
    {
        printf("Intervalo (25,50]");
        return 0;
    }
    else if(50.0000 < n && n <= 75.0000)
    {
        printf("Intervalo (50,75]");
        return 0;
    }
    else if(75.0000 < n && n <= 100.0000)
    {
        printf("Intervalo (75,100]");
        return 0;
    }
    else 
        printf("Fora de intervalo");
    
    return 0;       
}