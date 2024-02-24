#include <stdio.h>
int main()
{
    int money, n100, n50, n20, n10, n5, n2, n1;
    scanf("%d", &money);
    printf("%d\n", money);
    n100 = money / 100;
    money = money % 100;
    n50 = money / 50;
    money = money % 50;
    n20 = money / 20;
    money = money % 20;
    n10 = money / 10;
    money = money % 10;
    n5 = money / 5;
    money = money % 5;
    n2 = money / 2;
    money = money % 2;
    n1 = money;
    printf("%d nota(s) de R$ 100,00\n", n100);
    printf("%d nota(s) de R$ 50,00\n", n50);
    printf("%d nota(s) de R$ 20,00\n", n20);
    printf("%d nota(s) de R$ 10,00\n", n10);
    printf("%d nota(s) de R$ 5,00\n", n5);
    printf("%d nota(s) de R$ 2,00\n", n2);
    printf("%d nota(s) de R$ 1,00\n", n1);
    return 0;
}