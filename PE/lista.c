#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lista 
{
    char* string; /* string armazenada */
    struct lista* prox; /* ponteiro para próximo elemento */
};
typedef struct lista Lista;

Lista* listavazia(void)
{
    return NULL;
}

Lista* inserir(Lista* l, char* string)
{
    Lista* novo = (Lista*) malloc(sizeof(Lista));
    novo->string = string;
    novo->prox = l;
    return novo;
}

Lista* retira (Lista* l, char* n)
{
    Lista* ant = NULL; /* ponteiro para elemento anterior */
    Lista* p = l; /* ponteiro para percorrer a lista */
   
    /* procura elemento na lista, guardando anterior */
    while (p != NULL && strcmp(p->string, n) != 0) 
    {
        ant = p;
        p = p->prox;
    }
    
    if (p == NULL)
    return l; /* não achou: retorna lista original */
    
    /* retira elemento */
    if (ant == NULL)
    { /* retira elemento do inicio */
        l = p->prox; 
    }
    
    else 
    { /* retira elemento do meio da lista */
        ant->prox = p->prox; 
    }

    free(p);
    return l;
}

/*Lista* imprime(Lista* l, char* n)
{

}
*/

int main()
{
    Lista* l;
    l = listavazia();

    l = inserir(l, "Raiane");
    l = inserir(l, "aaaaa");
    l = inserir(l, "bbbbb");
    l = retira(l, "aaaaa");
    Lista* ptr = l;
    while (ptr != NULL) 
    {
        printf("%s\n", ptr->string);
        ptr = ptr->prox;
    }

    return 0;
}