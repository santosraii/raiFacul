#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Função para gerar um número aleatório entre min e max
int randomInt(int min, int max) {
    return min + rand() % (max - min + 1);
}

int main() {
    // Definindo o número de usuários e filmes
    int num_usuarios = 10;
    int num_filmes = 10;

    // Criando uma matriz para armazenar as avaliações
    int avaliacoes[num_usuarios][num_filmes];

    // Semente para a geração de números aleatórios
    srand(time(NULL));

    // Preenchendo a matriz com avaliações aleatórias (valores entre 1 e 5)
    for (int i = 0; i < num_usuarios; i++) {
        for (int j = 0; j < num_filmes; j++) {
            avaliacoes[i][j] = randomInt(1, 5);
        }
    }

    // Imprimindo a matriz de avaliações
    printf("Matriz de Avaliações:\n");
    for (int i = 0; i < num_usuarios; i++) {
        for (int j = 0; j < num_filmes; j++) {
            printf("%d ", avaliacoes[i][j]);
        }
        printf("\n");
    }

    return 0;
}