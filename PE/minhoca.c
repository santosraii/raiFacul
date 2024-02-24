#include <stdio.h>

int main()
{
    int k, i, j, passos = 0;
    char matriz[100][100];
    
    scanf("%d", &k);

    if(k == 2)
    {
        matriz[2][2];
        for(i = 0; i < k; i++)
        {
            for(j = 0; j < k; j++)
            {
                scanf("%d", matriz[i][j]);
            }
        }
        
    }

    if(k == 3)
    {
        matriz[3][3];
        for(i = 0; i < k; i++)
        {
            for(j = 0; j < k; j++)
            {
                scanf("%d", matriz[i][j]);
            }
        }
    }
    matriz[0][0] = 'c';

    while(i < k)
    {
        while(j < k)
        {
            while(matriz[i][j] == 'c')
            {
                if(matriz[i][j + 1] == 'x')
                {
                    matriz[i][j + 1] = matriz[i][j];
                    j++;
                    passos++;
                }

                else if(matriz[i + 1][j] == 'x')
                {
                    matriz[i + 1][j] = matriz [i][j];
                    i++;
                    passos++;
                }

                else if(matriz[i][j - 1] == 'x')
                {
                    matriz[i][j - 1] = matriz[i][j];
                    j--;
                    passos++;
                }
                else if(matriz [i - 1][j] == 'x')
                {
                    matriz[i - 1][j] = matriz[i][j];
                    i--;
                    passos++;
                }
                if(matriz [i][j+1]== 'o' || matriz[i + 1][j] == 'o' || matriz[i][j - 1] == 'o' || matriz[i - 1][j] == 'o') 
                {
                    printf("%d", passos);
                }
            }
        }
    }
                /*  c c c
                    c c c
                    c c c */

    return 0;
}