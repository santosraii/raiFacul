#include <stdio.h>

int fibo(int x){
    if (x == 0 || x == 1){
        return x;
    }
    int result;
    result = fibo(x - 2) + fibo(x - 1);
    return result;
}

int main(){

    int n, fibonacci;

    scanf("%d", &n);
    fibonacci = fibo(n);
    printf("%d", fibonacci);

    return 0;
}