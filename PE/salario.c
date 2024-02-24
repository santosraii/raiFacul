#include <stdio.h>
#define porcent 0.15
int main()
{
    char nome;
    double salario;
    double comissao;
    double total;
    printf("Digite seu nome");
    scanf("%s", &nome);
    printf("Digite seu salário fixo: ");
    scanf("%lf", &salario);
    printf("Digite seu montante total de vendas: ");
    scanf("%lf", &comissao);
    total = salario + comissao * porcent;
    printf("TOTAL = R$ %.2lf", total);
    
    return 0;
}