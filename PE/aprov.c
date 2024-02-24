#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct lista {
    char nome[81];
    float nota;
    struct lista *prox;
};
typedef struct lista Lista;

int aprovados(Lista* alunos)
{
    Lista* temporario = alunos;
    int contador = 0;
    while(temporario!=NULL)
    {
        if((*temporario).nota>=5)
        {
            contador++;
        }
        temporario = (*temporario).prox;
    }
    if(contador==0)
        return 0;
    else
        return contador;
}

Lista* insere(Lista* lista_especifica, int nota, char* nome_inserir)
{
    Lista *novo_elemento = (Lista*)malloc(sizeof(Lista));
    (*novo_elemento).nota = nota;
    strcpy((*novo_elemento).nome, nome_inserir);
    (*novo_elemento).prox = lista_especifica;
    return novo_elemento;
}

Lista* cria (void)
{
    return NULL;
}

int main(int argc, char const *argv[])
{
    Lista* listinha;
    int aprovados_numero;

    listinha = cria();
    listinha = insere(listinha, 10, "riho");
    listinha = insere(listinha, 10, "mrinho");
    listinha = insere(listinha, 10, "minho");

    aprovados_numero = aprovados(listinha);

    printf("%d\n", aprovados_numero);

    return 0;
}