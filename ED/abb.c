#include <stdio.h>
#include <stdlib.h>

struct arvore
{
    int info;
    struct arvore* left;
    struct arvore* right;
}; typedef struct arvore Arv;

Arv* abb_cria (void) //Arvore Binaria de busca
{
    return NULL; 
}

void abb_imprime (Arv* a)
{
    if (a != NULL) 
    {
        abb_imprime(a->left);
        printf("%d\n",a->info);
        abb_imprime(a->right);
    }
}

Arv* abb_busca (Arv* r, int v)
{
    if (r == NULL)
        return NULL;
    else if (r->info > v)
        return abb_busca (r->left, v);
    else if (r->info < v)
        return abb_busca (r->right, v);
    else 
        return r;
}

Arv* abb_insere (Arv* a, int v)
{
    if (a == NULL)
    {
        a = (Arv*) malloc(sizeof(Arv));
        a->info = v;
        a->left = a->right = NULL;
    }

    else if(a->info > v)
    {
        a->left = abb_insere(a->left, v);
    }
    else if (v > a->info)
        a->right = abb_insere(a->right, v);
    
    return a;
}

float soma_folhas(Arv* a)
{
    if(a == NULL)
        return 0;

    if(a->left == NULL && a->right == NULL)
        return a->info;

    return soma_folhas(a->right) + soma_folhas(a->left);
   

}

int menores_x (Arv* a, int x)
{
    if(a == NULL)
        return 0;
    
    int cont = 0;
    if(a->info < x)
        cont++;

    if(a->info >= x)
    {
        return cont + menores_x(a->left, x);
    }

    else
        return cont + menores_x(a->left, x) + menores_x(a->right, x);
}

Arv* antecessor (Arv* a, int x)
{
    if(a == NULL || x <= a->info)
        return NULL;
    
    if(a->right != NULL && a->right->info < x)
         
        return a->right;
    else
        return antecessor(a->left, x);
}

int main()
{
    Arv* ex1;
    
    ex1 = abb_cria();
    ex1 = abb_insere(ex1, 10);
    ex1 = abb_insere(ex1, 5);
    ex1 = abb_insere(ex1, 2);
    ex1 = abb_insere(ex1, 12);
    ex1 = abb_insere(ex1, 7);
    /*ex1 = abb_insere(ex1, 1);
    ex1 = abb_insere(ex1, 3);*/
    ex1 = abb_insere(ex1, 15);
    ex1 = abb_insere(ex1, 18);
    int ant = antecessor(ex1, 9);
    
    printf("%d", antecessor(ex1, 9));
    abb_imprime(ex1);

    return 0;
}