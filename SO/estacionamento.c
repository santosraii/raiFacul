#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<semaphore.h>

#define PARKING_THREADS 2
#define TAM_LISTA_ESPERA 10

int N = -1, carros = -1; // SPOTS QNTTY
int listaEspera = 0;
int estacionado = 0;

sem_t mutex;
sem_t vagas;
sem_t carsSmph;
sem_t esperaVaga;

struct carros
{
    pthread_t thCarro;
    int id;
    int vaga;
};
typedef struct carros Carros;

void* producer()
{
    while(1)
    {
        sem_wait(&carsSmph);

        sleep(rand()%10+1);

        sem_wait(&mutex);
        estacionado--;
        sem_post(&mutex);

        sem_post(&vagas);
    }
}

void* consumer(void* carro)
{
    sem_wait(&mutex);
    Carros* thCarro = (Carros*)carro;
    if(estacionado < N)
    {
        estacionado++;
        sem_post(&carsSmph);
        sem_post(&mutex);
        sem_wait(&vagas);
    }
    else if(listaEspera < TAM_LISTA_ESPERA)
    {
        listaEspera++;
        sem_post(&mutex);
        sem_post(&carsSmph);
        sem_wait(&esperaVaga);

        sem_wait(&vagas);
        sem_post(&esperaVaga);

        sem_wait(&mutex);
        listaEspera--;
        estacionado++;
        sem_post(&mutex);
    }
    else
    {
        sem_post(&mutex);
    }
}


int main()
{
    printf("Vagas : "); 
    scanf("%d", &N);

    printf("Carros : ");
    scanf("%d", &carros);

    sem_init(&mutex, 0, 1);
    sem_init(&carsSmph, 0, 0);
    sem_init(&vagas, 0, N);
    sem_init(&esperaVaga, 0, 10);

    pthread_t thVagas[PARKING_THREADS];
    for(int i=0; i< PARKING_THREADS; i++)
        pthread_create(&thVagas[i], NULL, &producer, NULL);

    Carros* thCarros = (Carros*)malloc(sizeof(Carros) * carros); 
    for(int j=0; j<carros; j++)
    {
        thCarros[j].id = j;
        pthread_create(&thCarros[j].thCarro, NULL, &consumer, (void*)&thCarros[j]);
    }
    for(int i=0; i<PARKING_THREADS; i++)
        pthread_join(thVagas[i], NULL);

    for(int i=0; i<carros; i++)
        pthread_join(thCarros[i].thCarro, NULL);

    sem_destroy(&mutex);
    sem_destroy(&vagas);
    sem_destroy(&carsSmph);

    pthread_exit(0);
}

