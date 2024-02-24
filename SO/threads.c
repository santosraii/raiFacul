#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Estrutura para armazenar os parâmetros da thread
typedef struct{
    int start;
    int end;
} ThreadParams;

typedef struct{
    int indice;
} ReturnParams;

int *array;
int num_threads;
int valor_procurado;

ReturnParams returnParams = { -1 };

// Função executada por cada thread
void *search(void *param) {
    ThreadParams *params = (ThreadParams *)param;
    int start = params->start;
    int end = params->end;
    
    // Busca do valor X no conjunto de inteiros
    for (int i = start; i < end; i++) {
        if (returnParams.indice != -1) pthread_exit(NULL);
        //printf("Thread %ld está procurando no indice: %d %d\n", pthread_self(), i, array[i]);
        if (array[i] == valor_procurado) {
            printf("Thread %ld achou o valor %d no índice %d \n", pthread_self(), valor_procurado, i);
            returnParams.indice = i;
        }
    }
    
    printf("Thread %ld não achou o valor %d\n", pthread_self(), valor_procurado);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Uso: %s <quantidade_threads> <valor_procurado> <arquivo_valores>\n", argv[0]);
        return 1;
    }
    
    num_threads = atoi(argv[1]);
    valor_procurado = atoi(argv[2]);
    
    // Lendo os valores do arquivo
    FILE *file = fopen(argv[3], "r");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    //Contando o numero de valores no arquivo
    int count = 0;
    int cleber = 0;
    while(fscanf(file, "%d", &cleber) > 0){
        count++;
    }

    //Alocando dinamicamente o array
    array = (int*) malloc(count * sizeof(int));
    if(array == NULL){
        perror("Erro ao alocar memória para o array");
        fclose(file);
        return 1;
    }
    
    //Retornando ao inicio do arq
    fseek(file, 0, SEEK_SET);

    //Lendo os valores do arq e preenchendo o array
    for (int i = 0; i < count; i++) {
        fscanf(file, "%d", &array[i]);
    }
    
    fclose(file);
    
    // Criando as threads
    pthread_t threads[num_threads];
    ThreadParams params[num_threads];
    int step = count / num_threads;

    // Inicializando e executando as threads 
    for (int i = 0; i < num_threads; i++) {
        params[i].start = i * step;
        params[i].end = (i == num_threads -1) ? count : (i + 1) * step;
        printf("%d %d\n", i * step, (i == num_threads -1) ? count : (i + 1) * step);
        pthread_create(&threads[i], NULL, search, (void *)&params[i]);
    }
    
    // Esperando todas as threads terminarem
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    free(array);

    return 0;
}