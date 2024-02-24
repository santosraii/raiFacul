#include <stdio.h>

int main()
{
    int n, i, j, num;

    scanf("%d", &n);

    int led[n], aux;
    
    for (i = 0; i < n; i++)
    {
        scanf("%d", &led[i]);
    }
    for(int j = 0; j < n; j++)
    {
        aux = led[j];
        num = 0;
        for (i = 0; aux > 0; i++)
        {
            int help = aux % 10;
                aux = aux / 10;

                if (help == 1)
                {
                    num = num + 2;
                }
                if (help == 2 || help == 3 || help == 5)
                {
                    num = num + 5;
                }
                if (help == 4)
                { 
                    num = num + 4;
                }
                if (help == 6 || help == 9 || help == 0)
                {
                    num = num + 6;
                }
                if (help == 7)
                {
                    num = num + 3;
                }
                if (help == 8)
                {
                    num = num + 7;
                }
        }
            printf("%d leds\n", num);
    }

    return 0;
}