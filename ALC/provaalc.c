#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 21

void criarMatriz(double a[N][N+1], int n)
{
    int i, j;
    
    for(i = 0; i < n; i++) // percorrer as linhas da matriz
    {
        for(j = 0; j < n; j++) // percorrer as colunas da matriz
        {
            a[i][j] = abs(i-j); 
        }
        a[i][n] = i + 1; // armazenar o valor de i + 1 na última coluna da matriz (vetor b)
    }
}
void trocarlinha(double a[N][N+1], int n, int l1, int l2)
{
    if(l1 < 0 || l1 >= n || l2 < 0 || l2 >= n)
    {
        return;
    }
    double aux;
    for(int i = 0; i < n+1; i++)
    {
        aux = a[l1][i]; // 1  3  4  6
        a[l1][i] = a[l2][i]; //3  5  8  2
        a[l2][i] = aux;
    }
}
void elimGauss(double a[N][N+1], int n)//
{
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        for(int j = (i+1); j < n; j++)
        {
            if(a[i][i] != 0)
            {
                double m = a[j][i]/a[i][i];
                for(k = i; k < n+1; k++)
                {
                    a[j][k] = a[j][k] - (m*a[i][k]);
                }
            }
            else
            {
                trocarlinha(a, n, i, j);
            }
        }
    }
}
void printMatrix(double a[N][N+1], int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n+1; j++)
        {
            printf("%.4lf  ", a[i][j]);
        }
            printf("\n");
    }
}
void gaussParcial(double a[N][N+1], int n)
{
    int i, j, k;
    for(j = 0; j < n; j++) //fixando a coluna para percorrer os elementos dela
    {
            int maior_elem = fabs(a[j][j]); // atribuindo o primeiro elemento da matriz como o maior
            int pos_maior = j;
            for(i = j+1; i < n; i++) // for para percorrer a coluna
            { 
                if(fabs(a[i][j]) > maior_elem) // verificando se o modulo da linha atual é maior que da linha anterior que atribuimos como o maior
                {
                    maior_elem = fabs(a[i][j]); // se for maior define como maior 
                    pos_maior = i; // salva a pos do maior elem
                }
            trocarlinha(a, n, j, pos_maior);
            if(a[j][j] != 0)
            {
                elimGauss(a, n);
            }
        }
    }
}
void trocarcoluna(double a[N][N+1], int n, int c1, int c2)
{
    if(c1 < 0 || c1 >= n || c2 < 0 || c2 >= n)
    {
        return;
    }
    double aux;
    for(int i = 0; i < n; i++)
    {
        aux = a[i][c1];
        a[i][c1] = a[i][c2];
        a[i][c2] = aux;
    }
}
void gaussTotal(double a[N][N+1], int n)
{
    int i, j, k;
    int perm[n]; // vetor para armazenar as permutações das colunas

    for( i = 0; i < n; i++)
    {
        perm[i] = i;//inicializar o vetor com a ordem original das colunas
    }

    for(k = 0; k < n; k++) //fixando a coluna para percorrer os elementos dela
    {
        int maior_elem = fabs(a[k][k]); // atribuindo o primeiro elemento da matriz como o maior
        int pos_maior_i = k; // armazenando o índice da linha do maior elemento
        int pos_maior_j = k;// armazenando o índice da coluna do maior elemento
        for(i = k; i < n; i++) // for para percorrer as linhas da submatriz
        {
            for(j = k; j < n; j++)// for para percorrer as colunas da submatriz
            {
                if(fabs(a[i][j]) > maior_elem) // verificando se o modulo da linha atual é maior que o maior encontrado ate então
                {
                    maior_elem = fabs(a[i][j]); // se for maior define como maior
                    pos_maior_i = i; // salva a pos da linha do maior elem
                    pos_maior_j = j; // salva a pos da coluna do maior elem
                }
            }
        }
        trocarlinha(a, n, k, pos_maior_i);// trocar a linha atual pela linha que contém o maior elemento
        trocarcoluna(a, n, k, pos_maior_j);// trocar a coluna atual pela coluna que contém o maior elemento
        int aux =  perm[k];// atualizar o vetor de permutações das colunas
        perm[k] = perm[pos_maior_j];
        perm[pos_maior_j] = aux; // trocar a posição do maior elemento pela posição do elemento que estava na posição k
        elimGauss(a, n);// atualizar o vetor de permutações das colunas
    }
}
void substituicaoRegressiva(double a[N][N+1], int n, double x[N], int perm[N])
{
    int i, j;
    for(i = n-1; i >= 0; i--) // começar pela última equação e subir até a primeira
    {
        double soma = 0; // variável para armazenar a soma dos termos já calculados
        for(j = i+1; j < n; j++) // percorrer os termos à direita do pivô
        {
            if(perm!= NULL) // se o vetor de permutações não for nulo, usar o vetor de permutações
            {
                soma += a[i][perm[j]] * x[perm[j]]; // multiplicar o coeficiente pelo valor da variável e somar ao total
            }
            else // se for pivoteamento parcial, usar os índices diretos
            {
                soma += a[i][j] * x[j]; // multiplicar o coeficiente pelo valor da variável e somar ao total
            }
        }
        if(perm!= NULL) // se n for nulo, usar o vetor de permutações
        {
            x[perm[i]] = (a[i][n] - soma) / a[i][perm[i]]; // isolar a variável e dividir pelo coeficiente do pivô
        }
        else // se for pivoteamento parcial, usar os índices diretos
        {
            x[i] = (a[i][n] - soma) / a[i][i]; // isolar a variável e dividir pelo coeficiente do pivô
        }
    }
}
void luTotal(double a[N][N+1], int n, int perm[N])
{
    int i, j, k;
    for(i = 0; i < n; i++)
    {
        perm[i] = i; // inicializar o vetor de permutações com a ordem original das colunas
    }
    for(k = 0; k < n-1; k++) // fixar a coluna para percorrer os elementos dela
    {
        int maior_elem = fabs(a[k][k]); // atribuir o primeiro elemento da submatriz como o maior
        int pos_maior_i = k; // armazenar o índice da linha do maior elemento
        int pos_maior_j = k; // armazenar o índice da coluna do maior elemento
        for(i = k; i < n; i++) // for para percorrer as linhas da submatriz
        { 
            for(j = k; j < n; j++) // for para percorrer as colunas da submatriz
            {
                if(fabs(a[i][j]) > maior_elem) // verificando se o módulo do elemento atual é maior que do maior encontrado até então
                {
                    maior_elem = fabs(a[i][j]); // se for maior, define como maior 
                    pos_maior_i = i; // salva a posição da linha do maior elemento
                    pos_maior_j = j; // salva a posição da coluna do maior elemento
                }
            }
        }
        trocarlinha(a, n, k, pos_maior_i); // trocar a linha atual pela linha que contém o maior elemento
        trocarcoluna(a, n, k, pos_maior_j); // trocar a coluna atual pela coluna que contém o maior elemento
        int aux = perm[k]; // atualizar o vetor de permutações das colunas
        perm[k] = perm[pos_maior_j];
        perm[pos_maior_j] = aux;
        for(i = k+1; i < n; i++) // percorrer as linhas abaixo do pivô
        {
            a[i][k] = a[i][k] / a[k][k]; // calcular o multiplicador e armazenar no lugar do elemento eliminado (parte de L)
            for(j = k+1; j < n; j++) // percorrer as colunas à direita do pivô
            {
                a[i][j] = a[i][j] - a[i][k] * a[k][j]; // eliminar o elemento e armazenar no lugar (parte de U)
            }
        }
    }
}

int main()
{
    double a[N][N+1], resultado[N][N+1], x[N];
    int n, perm[N];
    printf("Digite o numero de linhas e colunas da matriz: ");
    scanf("%d", &n);
    criarMatriz(a, n);      
    printMatrix(a, n);
    
    printf("Matriz com eliminação de gauss: \n");
    elimGauss(a, n);
    printMatrix(a, n);
    /*substituicaoRegressiva(a, n, x, perm);
    
    for(int i = 0; i < n; i++)
    {
        printf("x%d = %.4lf\n", i, x[i]);
    }

    printf("Matriz com eliminação de gauss com pivoteamento parcial: \n");
    gaussParcial(a, n);
    printMatrix(a, n);
    substituicaoRegressiva(a, n, x, perm);
    
    for(int i = 0; i < n; i++)
    {
        printf("x%d = %lf\n", i, x[i]);
    }

    printf("Matriz com eliminação de gauss com pivoteamento total: \n");
    gaussTotal(a, n);
    printMatrix(a, n);
    substituicaoRegressiva(a, n, x, perm);
    
    for(int i = 0; i < n; i++)
    {
        printf("x%d = %lf\n", i, x[i]);
    }

    printf("LU com pivoteamento total: \n");
    luTotal(a, n, perm);
    printMatrix(a, n);

    printf("Matriz com substituição regressiva: \n");
    substituicaoRegressiva(a, n, x, perm);
    //printMatrix(a, n);
    for(int i = 0; i < n; i++)
    {
        printf("x%d = %lf\n", i, x[i]);
    }*/
    return 0;
}