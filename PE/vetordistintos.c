#include <stdio.h>

int main()
{
    int n, i, j;

    scanf("%d", &n);

    int vetor[1000], tam = 0;

    for(i = 0; i < n; i++)
    {
        int num;
        scanf("%d", &num);
        int a = 0;

        for(j = i - 1; j >= 0; j--)
        {
            if(vetor[j] == num)
            {
                a = 1;
                break;
            }
        }
        if(a == 0)
        {
            vetor[i] = num;
            tam++;
        }
        else
        {
            i--;
        }

    }

    for(i = 0; i < tam; i++)
    {
        printf("%d ", vetor[i]);
    }

    return 0;
}