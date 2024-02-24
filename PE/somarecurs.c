#include <stdio.h>

int soma(int tam, int vetor[], int pos, int result){
    if (pos < tam){
        return soma(tam, vetor, pos + 1, result + vetor[pos]);
    }
    return result;
}

int main(){

    int t, n, v, i, j;

    scanf("%d", &t);

    for (i = 0; i < t; i++){
        scanf("%d", &n);
        int vetor[n];
        for (j = 0; j < n; j++){
        scanf("%d", &vetor[j]);
        }
    printf("%d\n", soma(n, vetor, 0, 0));
    }

    return 0;
}