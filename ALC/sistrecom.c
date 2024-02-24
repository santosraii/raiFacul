#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define M 10
#define N 10

double normaeuc (double v[], int n) //função pra calcular norma euclidiana de um vetor double norma
{
    double soma = 0;
    for (int i = 0; i < n; i++) {     //percorrer os elementos do vetor
        soma += v[i] * v[i]; //somar o quadrado do elemente v[i] à variavel soma
        }
        return sqrt(soma); //retorna a raiz da variavel soma
}

double produto_escalar(double u[], double v[], int n) //funçao pra calcular o produto escalar entre dois vetores
{
    double soma = 0;
    for (int i = 0; i < n; i++) { // percorrer os elementos dos vetores u e v
        soma += u[i] * v[i]; //somar o produto do elemento u[i] pelo elemento v[i] à variavel soma
        }
    return soma;
}

void gram_schmidt(double A[M][N], double Q[M][N], double R[N][N]) { // Definir uma função para calcular a decomposição QR usando o método de Gram-Schmidt 

    for (int i = 0; i < M; i++) {     // Inicializar as matrizes Q e R com zeros
        for (int j = 0; j < N; j++) { 
            Q[i][j] = 0; R[i][j] = 0;
            }
        }
for (int k = 0; k < N; k++) {     // Aplicar o método de Gram-Schmidt para cada coluna de A

    double v[M];     // Copiar a coluna k de A para um vetor v
    for (int i = 0; i < M; i++) {
        v[i] = A[i][k];
    }
    
    for (int j = 0; j < k; j++) {   // Subtrair a projeção de v sobre as colunas anteriores de Q
        double p = produto_escalar(v, Q[j], M); // Calcular o produto escalar entre v e a coluna j de Q
        
        R[j][k] = p; // Armazenar o valor de p na matriz R na posição [j,k]

        
        for (int i = 0; i < M; i++) {  // Subtrair p vezes a coluna j de Q do vetor v
            v[i] -= p * Q[i][j];
        }
    }
    
    double n = normaeuc(v, M);     // Calcular a norma do vetor v
    
    R[k][k] = n;     // Armazenar o valor de n na matriz R na posição [k,k]

    
    for (int i = 0; i < M; i++) {     // Normalizar o vetor v e armazená-lo na matriz Q na coluna k

        Q[i][k] = v[i] / n;
        }
    }
}

// Definir uma função para calcular a decomposição QR usando o método de Householder
void householder(double A[M][N], double Q[M][N], double R[N][N])
{ 
    // Inicializar as matrizes Q e R com zeros
    for (int i = 0; i < M; i++) 
    { 
        for (int j = 0; j < N; j++)
        {
            Q[i][j] = 0; R[i][j] = 0;
        } 
    }

    // Aplicar o método de Householder para cada coluna de A
    for (int k = 0; k < N && k < M - 1; k++)
    {
        // Copiar a subcoluna k de A para um vetor x
        double x[M - k];
        for (int i = k; i < M; i++)
        {
        x[i - k] = A[i][k];
        }
    
        // Calcular a norma do vetor x
        double n = normaeuc(x, M - k);
    
        // Calcular o sinal de x[0]
        double s = (x[0] >= 0) ? 1 : -1;
    
        // Calcular o vetor u
        double u[M - k];
        for (int i = 0; i < M - k; i++)
        {
            if (i == 0)
            {
                u[i] = x[i] + s * n;
            } 
            else
            {
                u[i] = x[i];
            }
        }
        
        // Normalizar o vetor u
        double nu = normaeuc(u, M - k);
        for (int i = 0; i < M - k; i++)
        {
            u[i] /= nu;
        }
        
        // Calcular a matriz P
        double P[M][M];
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (i < k || j < k)
                {
                    if (i == j)
                    {
                        P[i][j] = 1;
                    } 
                    else
                    {
                        P[i][j] = 0;
                    }
                }
                else
                {
                    P[i][j] = -2 * u[i - k] * u[j - k];
                    if (i == j)
                    {
                        P[i][j] += 1;
                    }
                }
            }
        }
        
        // Multiplicar a matriz P pela matriz A e armazenar o resultado na matriz R
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                double soma = 0;
                for (int l = 0; l < M; l++)
                {
                    soma += P[i][l] * A[l][j];
                }
                R[i][j] = soma;
            }
        }
        
        // Copiar a matriz R para a matriz A
        for (int i = 0; i < M; i++)
        {
            for (int j = 0; j < N; j++)
            {
                A[i][j] = R[i][j];
            }
        }
    }

    // Calcular a matriz Q como o produto das matrizes P
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (i == j)
            {
                Q[i][j] = 1;
            } 
            else
            {
                Q[i][j] = 0;
            }
        }
    }

    for (int k = N - 1; k >= 0 && k < M - 1; k--)
    {
        // Copiar a subcoluna k de R para um vetor x
        double x[M - k];
        for (int i = k; i < M; i++)
        {
            x[i - k] = R[i][k];
        }
        
        // Calcular a norma do vetor x
        double n = normaeuc(x, M - k);
        
        // Calcular o sinal de x[0]
        double s = (x[0] >= 0) ? 1 : -1;
        
        // Calcular o vetor u
    }
}

//Definir uma função para calcular a decomposição QR usando o método de Givens 
void givens(double A[M][N], double Q[M][N], double R[N][N])
{
    // Inicializar as matrizes Q e R com zeros 
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Q[i][j] = 0; R[i][j] = 0;
        }
    }
    // Copiar a matriz A para a matriz R
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            R[i][j] = A[i][j];
        }
    }

    // Inicializar a matriz Q com a matriz identidade
    for (int i = 0; i < M; i++)
    {
        Q[i][i] = 1;
    }

    // Aplicar o método de Givens para cada elemento fora da diagonal principal de R
    for (int k = 0; k < N && k < M - 1; k++)
    {
        for (int l = k + 1; l < M; l++)
        {
            // Calcular o cosseno e o seno do ângulo de rotação
            double c, s;
            if (R[l][k] == 0)
            {
                c = 1;
                s = 0;
            }
            else
            {
                double t = sqrt(R[k][k] * R[k][k] + R[l][k] * R[l][k]);
                c = R[k][k] / t;
                s = -R[l][k] / t;
            }
            
            // Calcular a matriz G de rotação
            double G[M][M];
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                    if (i == j) {
                        G[i][j] = 1;
                    } else if (i == k && j == k) {
                        G[i][j] = c;
                    } else if (i == l && j == l) {
                        G[i][j] = c;
                    } else if (i == k && j == l) {
                        G[i][j] = -s;
                    } else if (i == l && j == k) {
                        G[i][j] = s;
                    } else {
                        G[i][j] = 0;
                    }
                }
            }
            
            // Multiplicar a matriz G pela matriz R e armazenar o resultado na matriz R
            double temp[N][N];
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    double soma = 0;
                    for (int m = 0; m < M; m++) {
                        soma += G[i][m] * R[m][j];
                    }
                    temp[i][j] = soma;
                }
            }
            
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < N; j++) {
                    R[i][j] = temp[i][j];
                }
            }
            
            // Multiplicar a matriz Q pela matriz G transposta e armazenar o resultado na matriz Q
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                    double soma = 0;
                    for (int m = 0; m < M; m++) {
                        soma += Q[i][m] * G[j][m];
                    }
                    temp[i][j] = soma;
                }
            }
            
            for (int i = 0; i < M; i++) {
                for (int j = 0; j < M; j++) {
                    Q[i][j] = temp[i][j];
                }
            }
        }
    }
}

// Definir uma função para resolver o sistema linear usando a decomposição QR 
void resolver(double Q[M][N], double R[N][N], double b[N], double x[N])
{
    // Inicializar o vetor x com zeros
    for (int i = 0; i < N; i++)
    {
        x[i] = 0;
    }
    // Multiplicar o vetor b pela matriz Q transposta e armazenar o resultado no vetor y
    double y[N];
    for (int i = 0; i < N; i++) {
        double soma = 0;
        for (int j = 0; j < M; j++) {
            soma += Q[j][i] * b[j];
        }
        y[i] = soma;
    }

    // Resolver o sistema triangular superior Rx = y usando o método de substituição retroativa
    for (int i = N - 1; i >= 0; i--) {
        double soma = 0;
        for (int j = i + 1; j < N; j++) {
            soma += R[i][j] * x[j];
        }
        x[i] = (y[i] - soma) / R[i][i];
    }
}

// Definir uma função para gerar recomendações usando as matrizes de fatores latentes
void recomendar(double Q[M][N], double R[N][N], double b[N], int k)
{
    double x[N];
    // Calcular o vetor x usando a função resolver double x[N];
    resolver(Q, R, b, x);
    // Calcular o vetor p como o produto da matriz R pelo vetor x
    double p[N];
    for (int i = 0; i < N; i++) {
        double soma = 0;
        for (int j = 0; j < N; j++) {
            soma += R[i][j] * x[j];
        }
        p[i] = soma;
    }

    // Encontrar os k filmes com as maiores avaliações previstas em p
    int filmes[k];
    double avaliacoes[k];
    char movies[100];

    // Inicializar os vetores filmes e avaliacoes com zeros
    for (int i = 0; i < k; i++) {
        filmes[i] = 0;
        avaliacoes[i] = 0;
    }

    // Percorrer os elementos do vetor p
    for (int i = 0; i < N; i++) {
        // Verificar se o usuário alvo já avaliou o filme i
        if (b[i] == 0) {
            // Verificar se a avaliação prevista p[i] é maior que a menor avaliação em avaliacoes
            if (p[i] > avaliacoes[0]) {
                // Substituir a menor avaliação em avaliacoes pela avaliação prevista p[i]
                avaliacoes[0] = p[i];
                
                // Substituir o filme correspondente em filmes pelo filme i
                filmes[0] = i;
                
                // Ordenar os vetores filmes e avaliacoes em ordem crescente de avaliação
                for (int j = 1; j < k; j++) {
                    if (avaliacoes[j] < avaliacoes[j - 1]) {
                        double temp1 = avaliacoes[j];
                        int temp2 = filmes[j];
                        avaliacoes[j] = avaliacoes[j - 1];
                        filmes[j] = filmes[j - 1];
                        avaliacoes[j - 1] = temp1;
                        filmes[j - 1] = temp2;
                    } else {
                        break;
                    }
                }
            }
        }
    }

    // Exibir os k filmes recomendados e suas respectivas avaliações previstas
    printf("Os %d filmes recomendados para você são:\n", k);
    for (int i = k - 1; i >= 0; i--) {
        printf("%d, com uma avaliação prevista de %.2f\n", movies[filmes[i]], avaliacoes[i]);
    }
}

int main()
{
    double A[M][N], Q[M][N], R[N][N], b[N], x[N];
    // Carregar os dados do MovieLens para a matriz A e o vetor b
FILE *fp1, *fp2;

fp1 = fopen("ratings.csv", "r");

if (fp1 == NULL) {
    printf("Erro ao abrir o arquivo ratings.csv\n");
    return -1;
}

for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
        fscanf(fp1, "%lf,", &A[i][j]);
}

fclose(fp1);

fp2 = fopen(“movies.csv”, “r”);


    /*// Declarar as matrizes A, Q e R e os vetores b e x 

    A[M][N] =
    gram_schmidt(A, Q, R);
    householder(A, Q, R);
    givens(A, Q, R);


    for (int i = 0; i < N; i++) {
        b[i] = A[10][i];
    }

    // Chamar a sua função para resolver o sistema linear usando a decomposição QR
    resolver(Q, R, b, x);

    // Chamar a sua função para gerar recomendações usando as matrizes Q e R e os vetores b e x
    // Escolher um valor de k entre 1 e num_filmes
    int k = 3;
    recomendar(Q, R, b, k);

    // Retornar 0 para indicar que o programa terminou com sucesso*/
    return 0;
    }
}