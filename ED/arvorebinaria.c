#include <stdio.h>
#include <stdlib.h>

struct arvore
{
    char info;
    struct arvore* left;
    struct arvore* right;
}; typedef struct arvore Arv;

Arv* arv_vazia (void) //Arvore Binaria
{
    return NULL; 
}

Arv* arv_cria (char c, Arv* sae, Arv* sad)
{
    Arv* p = (Arv*)malloc(sizeof(Arv));
    p->info = c;
    p->left = sae;
    p->right = sad;
    return p;
}

int vazia (Arv *a)
{
    return a == NULL;
}

Arv* arv_libera (Arv* a)

{
    if(!vazia(a))
    {
        arv_libera(a->left);
        arv_libera(a->right);
        free(a);
    }
    return NULL;
}

int arv_pertence (Arv* a, char c)
{
    if(vazia(a))
        return 0;
    else
        return a->info == c || arv_pertence(a->left, c) || arv_pertence(a->right, c);
}

void arv_imprime(Arv* a)
{
    printf("<");
    if(!vazia(a))
    {
        printf("%c", a->info);
        arv_imprime(a->left);
        arv_imprime(a->right);
    }
    printf(">");
}


int main()
{
    Arv* a, *a1, *a2, *a3, *a4, *a5;
    a = arv_vazia();
    a = arv_cria('d', arv_vazia(), arv_vazia());
    a1 = arv_cria('b', arv_vazia(), a);
    a2 = arv_cria('e', arv_vazia(), arv_vazia());
    a3 = arv_cria('f', arv_vazia(), arv_vazia());
    a4 = arv_cria('c', a2, a3);
    a5 = arv_cria('a', a1, a4);
    arv_imprime(a5);
    a5 = arv_libera(a5);
    return 0;
}