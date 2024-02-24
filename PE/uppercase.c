#include <stdio.h>

int main()
{
    char palavra[100];
    int i;

    scanf("%s", palavra);

    if (palavra[0] >= 'a' && palavra[0] <= 'z')
    {
        palavra[0] = palavra[0] - 'a' + 'A';
    }
    for (i = 1; palavra[i] != '\0'; i++)
    {
        if (palavra[i] >= 'A' && palavra[i] <= 'Z')
        {
            palavra[i] = palavra[i] -'A' + 'a';
        }
    }

    printf("%s", palavra);

    return 0;
}