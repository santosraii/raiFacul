#include <stdio.h>

int verifica_linhas(int matriz[][3], int linhas, int colunas)
{
    int i, j, somalinha = 0;

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            somalinha = somalinha + matriz[i][j];
        }
    }
    if(somalinha == 15)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int verifica_colunas(int matriz[][3], int linhas, int colunas)
{
    int k, l, somacoluna;

    for(l = 0; l < colunas; l++)
    {
        for(k = 0; k < linhas; k++)
        {
            somacoluna = somacoluna + matriz[k][l];
        }
    }
    if(somacoluna == 15)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int verifica_diagonais(int matriz[][3], int linhas, int colunas)
{
    int a, m, n;
    int resultado = 0;

   // for(a = 0; a < 6; a++)
    //{
        for(m = 0; m < linhas; m++)
        {
            for(n = 0; n < colunas; n++)
            {
                
                    resultado = resultado + matriz[m][n + 1];
            }
       // }
    }
    if(resultado == 15)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int verifica_numeros_unicos(int matriz[][3], int linhas, int colunas)
{
    int c, d, e, f, vetor[10];

    for(c = 0; c < linhas; c++)
    {
        for(d = 0; d < colunas; d++)
        {
            for(e = 0; e < (linhas * colunas); e++)
            {
                vetor[e] = matriz[c][d];
            }
        }
    }
    for(c = 0; c < linhas; c++)
    {
        for(d = 0; d < colunas; d++)
        {
            for(f = e - 1; f >= 0; f--)
            {
                if(vetor[f] == matriz[c][d])
                {
                    return 0;
                }
                else
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}


int verifica_matriz(int matriz[][3], int linhas, int colunas)
{
    if(verifica_linhas(matriz[linhas][colunas], linhas, colunas) && verifica_colunas(matriz[linhas][colunas], linhas, colunas) && verifica_diagonais(matriz[linhas][colunas], linhas, colunas) && verifica_numeros_unicos(matriz[linhas][colunas], linhas, colunas))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}

int main()
{
    int linhas = 3, colunas = 3, i, j;
    int matriz[linhas][colunas];

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            scanf("%d", matriz[i][j]);
        }
    }
    verifica_linhas(matriz[linhas][colunas], linhas, colunas);
    verifica_colunas(matriz[linhas][colunas], linhas, colunas);
    verifica_diagonais(matriz[linhas][colunas], linhas, colunas);
}