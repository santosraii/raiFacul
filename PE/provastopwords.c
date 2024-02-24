#include<stdlib.h>

typedef struct
{
    char *lista;
    int tamanho;
} TEXTO;

TEXTO* remove_palavra(TEXTO *texto, int base, int offset) {
    TEXTO *p_texto, *x;
    int i, j;
    int fim = base + offset;

    p_texto = (TEXTO *) malloc(sizeof(TEXTO));

    p_texto->tamanho = texto->tamanho - offset;

    p_texto->lista = (char *) malloc(sizeof(char) * p_texto->tamanho);
    for(j = 0; j < base; j++)
    {
        p_texto->lista[j] = texto->lista[j];
    }

    for(i = fim; texto->lista[i] != '\0'; i++)
    {
        p_texto->lista[j] = texto->lista[i];
        j++;
    }
    
    return p_texto;
}