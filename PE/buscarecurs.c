#include <stdio.h>

int busca(int tam, int vetor[], int pos, int x){
    if(pos < tam){
        if(x == vetor[pos]){
            return pos;
        }
        else{
            return busca(tam, vetor, pos + 1, x);
        }
    }
    else{
        return -1;
    }
}

int main(){

    int x, n, i;

    scanf("%d %d", &x, &n);
    int vetor[n];
    for (i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
    }
    printf("%d", busca(n, vetor, 0, x));

    return 0;
}