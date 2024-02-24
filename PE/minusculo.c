#include <stdio.h>

int main()
{
    int i;
    char aaa[200];

    scanf("%s", aaa);

    for(i = 0; aaa[i] != '\0'; i++)
    {
        if (aaa[i] >= 'A' && aaa[i] <= 'Z')
        {
            aaa[i] = aaa[i] - 'A' + 'a';
        }
    }
    printf("%s\n", aaa);

    return 0;
}