#include <stdio.h>

int fatorial (int x){
    if (x == 0 || x == 1){
        return 1;
    }
    int result = x * fatorial(x - 1);
    return result;
}

int main(){

    int n;
    scanf("%d", &n);

    int resultado = fatorial(n);

    printf("%d", resultado);

    return 0;
}