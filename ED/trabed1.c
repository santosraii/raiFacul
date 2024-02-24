#include <stdio.h>
#include <string.h>

struct contato
{
    char nome[81];
    float telefone;
};
typedef struct contato Contato;

int inscontato(Contato agenda[], int *tamanho, Contato novo)
{
    int i;
    
    if(*tamanho > 100)
    {
        printf("Agenda cheia");
        return -1;
    }

    Contato aux = novo;
    for(i = 0; i < *tamanho; i++)
    {
        if(strcmp(agenda[i].nome, novo.nome) > 0)
        {         
            
            Contato atual = agenda[i];
            agenda[i] = aux;
            aux = atual;

        }
    }
    agenda[*tamanho] = aux;
    *tamanho = *tamanho + 1;
    printf("Contato adicionado\n");
    return 1;
}

int buscacontato(Contato agenda[], int tamanho, char* nome)
{
    int inicio = 0;
    int fim = tamanho - 1;
    int achou = 0;
    int meio = 0;
    while(inicio <= fim)
    {
        meio = (inicio + fim)/2;

        if(strcmp(nome, agenda[meio].nome) < 0)
        {
            fim = meio - 1;
        }
        else if(strcmp(nome, agenda[meio].nome) > 0)
        {
            inicio = meio + 1;
        }
        else
        {
            return meio;
        }
    }
    return -1;
}

void removecont(Contato agenda[], int *tamanho, char* nome)
{
    int pos = buscacontato(agenda, *tamanho, nome);

    if(pos == -1)
    {
        printf("Contato não existe\n");
    }

    else
    {
        for(int i = pos; i < *tamanho; i++)
        {
            agenda[i] = agenda[i + 1];
        }
        *tamanho = *tamanho - 1;
        
        printf("Contato removido\n");
    }
}

void imprime(Contato agenda[], int tamanho)
{
    for(int i = 0; i < tamanho; i++)
    {
        printf("%s %.0f\n", agenda[i].nome, agenda[i].telefone);
    }
}

int main()
{
    Contato agenda[100], novo = {};
    int tam = 0, op, busca;
    char nome[81];
    float tel;

    while(1)
    {
        printf("1 - Inserir novo contato\n2 - Buscar contato\n3 - Remover contato\n4 - Imprimir agenda\n");
        scanf("%d", &op);

        if(op == 1)
        {
            printf("Insira nome e telefone do novo contato:\n");
            scanf("%s %f", nome, &tel);
            strcpy(novo.nome, nome);
            novo.telefone = tel;
            inscontato(agenda, &tam, novo);
        }
        else if(op == 2)
        {
            printf("Insira o nome do contato que deseja buscar:");
            scanf("%s", nome);
            busca = buscacontato(agenda, tam, nome);
            if(busca == -1)
            {
                printf("Contato não existe\n");
            }

            else
            {
                printf("O contato está na posição: %d\n", busca);
                printf("%s %.0f\n", agenda[busca].nome, agenda[busca].telefone);
            }
        }
        else if(op == 3)
        {
            printf("Insira o nome do contato que deseja remover:");
            scanf("%s", nome);
            removecont(agenda, &tam, nome);
        }
        else if(op == 4)
        {
            imprime(agenda, tam);

        }
    }
    return 0;
}
