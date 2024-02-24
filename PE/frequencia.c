#include <stdio.h>

int main()
{
    int n, i, aprov = 0, nota = 5;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        int notas[n];
        scanf("%d", &notas[i]);
        if(notas[i] >= 0 && notas[i] <= 10)
        {
            if (notas[i] >= nota)
            {
                aprov++;
            }
        }

    }
    printf("%d\n", aprov);

    return 0;
}