#include <stdio.h>
#include <math.h>

int main()
{
    long long int n = 600851475143 , i, j, p = 0, fatorp = 0, primo = 0;

    for (i = 2; i <= sqrt(n); i++)
    {

        if (n % i == 0)
        {
            primo = i;
            p = 0;
            for (j = 2; j <= primo/2; j++)
            {
                if (primo % j == 0)
                {
                    p++;
                }
            }
            if (p == 0)
            {
                fatorp = primo;
            }
        }
        
    }
    printf("%lld\n", fatorp);

    return 0;
}