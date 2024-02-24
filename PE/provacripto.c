#include <stdio.h>

void criptografia_caracterer(char texto_original[101], char texto_modificado[101])
{
    int i;
    for (i = 0; texto_original[i] != '\0'; i++)
    {
        texto_modificado[i] = texto_original[i];
    }

    for(i = 0; texto_original[i] != '\0'; i++)
    {
        if(texto_original[i] >= 'a' && texto_original[i] < 'z' || texto_original[i] >= 'A' && texto_original[i] < 'Z')
        {
            texto_modificado[i]
            = texto_original[i] + 1;
        }
        if(texto_original[i] == 'z')
        {
            texto_modificado[i] = 'a';
        }
        if(texto_original[i] == 'Z')
        {
            texto_modificado[i] = 'A';
        }
    }
    //printf("%s\n", texto_modificado);
    return;
}

void criptografia_numero(char texto_original[101], char texto_modificado[101])
{
    int i;
    for (i = 0; texto_original[i] != '\0'; i++)
    {
        texto_modificado[i] = texto_original[i];
    }

    for(i = 0; texto_original[i] != '\0'; i++)
    {
        if(texto_original[i] == '0')
        {
            texto_modificado[i] = '9';
        }
        if(texto_original[i] > '0' && texto_original[i] <= '9')
        {
            texto_modificado[i] = texto_original[i] - 1;
        }
    }
    //printf("%s\n", texto_modificado);
    return;
}

void deslocar_frase(char texto_original[101], char texto_modificado[101])
{
    int i, j;
    char caracter[3];

    for(i = 0; texto_original[i] != '\0'; i++)
    {
        texto_original[i] = texto_modificado[i];
    }

    for(j = i - 1; j > '\0'; j--)
    {
        texto_modificado[j] = texto_original[j - 1];
    }
    caracter[0] = texto_original[i - 1];
    texto_modificado[0] = caracter[0];

    printf("%s\n", texto_modificado);
    return;
}

void criptografar(char texto_original[101], char texto_modificado[101])
{
    criptografia_caracterer(texto_original, texto_modificado);
    criptografia_numero(texto_original, texto_modificado);
    deslocar_frase(texto_original, texto_modificado);

    //printf("%s", texto_modificado);
    return;
}


int main()
{
    char texto[101], modificado[101];
    scanf("%[^\n]", texto);

    criptografar(texto, modificado);

    return 0;
}