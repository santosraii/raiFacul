#include <stdio.h>
#include <math.h>

int potencia(int base, int expoente)
{
    int resultado, i;

    resultado = base;

    for(i = 0; i < expoente; i++)
    {
        resultado = resultado * base;
    }

    return resultado;
}

int converter_bin_dec(char base)
{
    int k, a, b, c, d, valor[4], i, j, result, quant = 0;



    int vetor[4] = {d, c, b, a};

    for(j = 0; j < 4; j++)
    {
        i = 4;
        valor[i] = vetor[j] * potencia(2, j);
        i--;
    }

    for(k = 0; k < 4; k++)
    {
        printf("%d", vetor[j]);
    }
}

int main()
{
    int i, x, casos;
    char casos[100];

    scanf(" %[^\n]", casos);

    /*for(i = 0; base[i] != '\0'; i++)
    {
        if(base[i] == "d")
        {
            
        }
    }*/


}