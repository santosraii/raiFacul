#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5
sem_t semaforo;
int inicio = 1;

void* escrever(int a, int b)
{
    int i = a;
    while(i <= b)
    {
        printf("%d\n", i);
        i++;
    }  
}
void* thread_func(void *arg)
{
    int i = (int)arg;
    sem_wait(&semaforo);
    if(i < N)
    {
        escrever(1 + (i-1)*100, i*100);
    }
    sem_post(&semaforo);
}

int main()
{
    pthread_t threads[N];

    sem_init(&semaforo, 0, 1);
    for(int i=1; i<N; i++)
    {
        pthread_create(&threads[i-1], NULL, thread_func, (void*)i);
    }

    for(int i = 0; i < N; i++)
    {
        pthread_join(threads[i], NULL);
    }
    sem_destroy(&semaforo);

    return 0;
}