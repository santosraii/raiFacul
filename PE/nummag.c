#include <stdio.h>

int fat (int n)
{
    if (n == 0 || n == 1){
        return 1;
    }
    int result = n * fat(n - 1);
    return result;
}

float expo(float b, int e)
{
    float resultado = 1;
    int i = 0;

    if(e > 0)
    {
        while(i < e)
        {
            resultado = resultado * b; 
            i++;
        }
    }

    if(e < 0)
    {
        while(i > e)
        {
            resultado = resultado / b;
            i--;
        }
    }
    return resultado;
}

float magico(float x, int n)
{
    float somatorio = 0;
    int i;
    for(i = 0; i <= n; i++)
    {
        somatorio = somatorio + (expo(-1, i) * expo(x, ((2*i) + 1)) / fat((i + 1)));
    }
    return somatorio;
}

//int main()
//{
  //  int n;
    //float x, result = 0;

    //scanf("%f", &x);
    //scanf("%d", &n);

    //result = magico(x, n);

    //printf("%f", result);

    //return 0;
//}