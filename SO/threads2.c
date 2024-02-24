#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 3
#define ARRAY_SIZE 10

int array[ARRAY_SIZE];

// Estrutura para armazenar os parâmetros da thread
typedef struct {
    int thread_id;
    int valor_procurado;
} ThreadParams;

// Função executada por cada thread
void *search(void *param) {
    ThreadParams *params = (ThreadParams *)param;
    int thread_id = params->thread_id;
    int valor_procurado = params->valor_procurado;
    
    // Busca do valor X no conjunto de inteiros
    for (int i = thread_id * (ARRAY_SIZE / NUM_THREADS); i < (thread_id + 1) * (ARRAY_SIZE / NUM_THREADS); i++) {
        if (array[i] == valor_procurado) {
            printf("Thread %d achou o valor %d no índice %d\n", thread_id, valor_procurado, i);
            pthread_exit(NULL);
        }
    }
    
    printf("Thread %d não achou o valor %d\n", thread_id, valor_procurado);
    pthread_exit(NULL);
}

int main() {
    // Preenchendo o conjunto de inteiros
    printf("Insira os valores do conjunto de inteiros:\n");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        scanf("%d", &array[i]);
    }
    
    // Criando as threads
    pthread_t threads[NUM_THREADS];
    
    // Parâmetros das threads
    ThreadParams params[NUM_THREADS];
    
    // Valor a ser buscado
    printf("Insira os valores a serem buscados:\n");
    int valores[NUM_THREADS];
    for(int i = 0; i < NUM_THREADS; i++)
    {
        scanf("%d", &valores[i]);
    }
    
    // Inicializando e executando as threads
    for (int i = 0; i < NUM_THREADS; i++) {
         params[i].thread_id = i;
        params[i].valor_procurado = valores[i];
        pthread_create(&threads[i], NULL, search, (void *)&params[i]);
    }
    
    // Esperando todas as threads terminarem
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }
    
    return 0;
}
