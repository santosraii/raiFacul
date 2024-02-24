#include <stdio.h>

int main()
{
    int i, v, hexa[100], quociente, resto; //Declarando um contador e um vetor que vai receber o numero
   
        scanf("%d", &v);
        quociente = v;
        
        for(i = 0; quociente != 0; i++)
        {
            resto = quociente % 16;
            if(resto < 10)
            {
                hexa[i] = 48 + resto;
            }
            else
            {
                hexa[i] = 55 + resto;
            }
            quociente = quociente / 16;

                    }
        
    for(; i >= 0; i--)
    {
        printf("%c", hexa[i]);
    }
    return 0;
}