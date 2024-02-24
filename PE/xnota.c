#include <stdio.h>

void bubble_sort (int vetor[], int n)
{
    int k, j, aux;

    for (k = 1; k < n; k++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (vetor[j] > vetor[j + 1])
            {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main()
{
    int n, x, i, num, a, j;

    scanf("%d\n%d", &n, &x);

    int vetor[1000];

    for(i = 0; i < n; i++)
    {
        scanf("%d", &num);
        a = 0;
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
        }
        else
        {
            i--;
            n--;
        }
    }
    
    bubble_sort(vetor, n);

    printf("%d", vetor[x - 1]);

    return 0;
}