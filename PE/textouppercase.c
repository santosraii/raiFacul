#include <stdio.h>

int main()
{
    int i = 0;

    char texto[200];

    fgets(texto, 200, stdin);

    if (texto[i] >= 'a' && texto[i] <= 'z')
    {
        texto[i] = texto[i] - 'a' + 'A';
    }
    for( i = 1; texto[i] != '\0'; i++)
    {
        if (texto[i] == ' ')
        {
            if (texto[i + 1] >= 'a' && texto[i + 1] <= 'z')
            {
                texto[i + 1] = texto[i + 1] - 'a' + 'A';
            }
        
        }
    } 
    printf("%s", texto);

    return 0;
}