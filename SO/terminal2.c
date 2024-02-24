#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_command(char** args) //executa um unico comando
{
    pid_t pid = fork();
    if(pid == 0)
    {
        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else if(pid > 0)
    {
        wait(NULL);
    }
    else
    {
        perror("fork");
    }
printf("Tudo certo até aqui 1\n");}

char **separar_esp(char *str)
{
    int n_palavras = 1, i, j, k;

    for (i = 0; str[i++]!= '\0'; i++)
    { 
        if (str[i]==' ') n_palavras++;
    }
    char ** matriz = (char **) malloc(sizeof(char*) * n_palavras);

    for (i = 0; i < n_palavras; i++)  {
        matriz[i] = (char *) malloc (sizeof(char) * 10);
    }
    for (i = 0, j = 0, k = 0; k < strlen(str); k++) 
    { 
        if (str[k] ==' ' || str[k] == '\n' || str[k] == '\0')
            {
                matriz [j][i] = '\0';
                i = 0;
                j++;
                continue;
            }
            matriz[j][i++] = str[k];
    }
    matriz[j][i] = '\0';
printf("Tudo certo até aqui 2\n");
    char **args = (char **)malloc(sizeof(char *) * (n_palavras + 1)); // +1 para o argumento nulo

    // Copie os argumentos da matriz para o array de argumentos
    for (i = 0; i < n_palavras; i++) {
        args[i] = matriz[i];
    }

    args[n_palavras] = NULL; // Indique o final da lista de argumentos

    // Libere a matriz temporária, mas mantenha os argumentos em args
    free(matriz);

    return args;
    printf("Tudo certo até aqui 3\n");
}

int comparar(char *a, char *b)
{
    int i = 0, j = 0;
    for(; a[i] != '\0' && b[j] != '\0'; i++, j++)
    {
        if(a[i] != b[j])
            return 0;
    }
    printf("Tudo certo até aqui 4\n");
    if(i == j)
        return 1;
    return 0;
    printf("Tudo certo até aqui 5\n");
}

void liberar_mem(char **args)
{
    int i = 0;
    while(args[i] != NULL)
    {
        free(args[i]);
        i++;
    }
    free(args);
    printf("Tudo certo até aqui 6\n");
}

void execute_commands(char* linha)
{
    char* comando;
    char* rest = linha;
    while((comando = strtok_r(rest, ";", &rest)))
    {
        char** args = separar_esp(comando);
        execute_command(args);
        liberar_mem(args);
    }
    printf("Tudo certo até aqui 7\n");
}

int main(void) 
{
    char linha[100], **args;
    int TRUE = 1; 
    int background = 0;

    printf ("BEM VINDO AO TERMINAL \n");

    //int i;
do { 
    printf("> "); //prompt pro usuário
    scanf ("%[^\n]", linha);
    getchar();
    args = separar_esp(linha);
    printf("Tudo certo até aqui 8\n");
    if(comparar(linha, "exit"))
    {
        break;
        printf("Tudo certo até aqui 9\n");
    }
    else if(fork() == 0)
    {
        background = 0;
        for (int i = 0; args[i] != NULL; i++) 
        {
            if (comparar(args[i], "&")) {
                background = 1;
                args[i] = NULL; // Remova o "&" dos argumentos
                break;
            }
        }//verificar se é um comando em segundo plano
        execute_commands(linha);
        exit(EXIT_SUCCESS);
        printf("Tudo certo até aqui 10\n");
    }
    else
    {
        if(background == 0)
        {
            wait(NULL);
            printf("Tudo certo até aqui 11\n");
        }
    }
   
 }
 while (TRUE);

 printf("FIM DO TERMINAL\n");
 return 0;
}