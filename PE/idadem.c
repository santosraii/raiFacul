#include <stdio.h>
int main()
{
    //dizem as más linguas que está errado
    int m, i1, i2, i3;
    scanf("%d", &m);
    scanf("%d", &i1);
    scanf("%d", &i2);
    i3 = m - i1 - i2;
    printf("%d", i3);
    return 0;
}