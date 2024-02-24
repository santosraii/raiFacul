#include <stdio.h>
int main()
{
    int n, h, m, s;
    scanf("%d", &n);
    h = n / (60*60);
    n = n % (60*60);
    m = n / 60;
    s = n % 60;
    printf("%d:%d:%d", h, m, s);
    return 0;
}