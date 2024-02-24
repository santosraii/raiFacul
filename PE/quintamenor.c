#include <stdio.h>

int main()
{
    int n, i, menor = 10, seg = 10, ter = 10, quar = 10, quinta = 10;

    scanf("%d", &n);

    int nota[n];
    
    for (i = 0; i < n; i++)
    {
        scanf("%d", &nota[i]);
        if (nota[i] >= 0 && nota[i] <= 10 && nota[i] <= menor)
        {
            menor = nota[i];
        }
    }
    for (i = 0; i < n; i++)
    {
        if (nota[i] < seg && nota[i] > menor)
        {
            seg = nota[i];
        }
        if (seg < ter && seg > menor)
        {
            ter = nota[i];
        }
        if (ter < quar && ter > seg)
        {
            quar = nota[i];
        }
        if (quar < quinta && quar > ter)
        {
            quinta = nota[i];
        }
    }

    printf("%d", quinta);

    return 0;
}