#include <stdio.h>

int main()
{
    int n, i, j;
    float notas[20];

    scanf("%d", &n);
    float mediap[n];

    for(i = 0; i < n; i++)
    {
        float nota1, nota2, nota3;
        scanf("%f %f %f", &nota1, &nota2, &nota3);
        mediap[i] = (nota1*2 + nota2*3 + nota3*5)/10;
        printf("%.1f\n", mediap[i]);
    }
    return 0;
}