#include <stdio.h>
int main()
{
    int tempo, velocidade;
    float distancia;
    double litros;
    scanf("%d", &tempo);
    scanf("%d", &velocidade);
    distancia = velocidade * tempo;
    litros = distancia / 12;
    printf("%.3lf", litros);
    return 0;
}