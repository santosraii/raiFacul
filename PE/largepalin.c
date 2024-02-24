#include <stdio.h>

int main(void)
{
    int i, j, palin, maior = 0, copia, result, resto; 

    for(i = 999; i >= 100; i--)
    {
        for(j = 999; j >= 100; j--)
        {
            result = i * j;
            copia = result;
            palin = 0;

            while(copia > 0)
            {
                resto = copia % 10;
                copia = copia / 10;

                palin = (palin * 10) + resto;
            }

            if(palin == result)
            {
                if(palin > maior)
                {
                    maior = palin;
                }
            }
        }
    }
}