#include <stdio.h>

int main()
{
    int tam = 5, num[tam], i, maiornum = 0, pos = 0;

    for(i = 0; i < tam ; i++)
    {
        scanf("%d", &num[i]);
        if (num[i] > maiornum)
        {
            maiornum = num[i];
            pos = i;
        }
    }
    pos++;
    printf("%d\n%d\n", maiornum, pos);
    return 0;
}