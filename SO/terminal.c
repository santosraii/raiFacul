#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct
{
    char *nome;
    void (*funcao)(char **);
} Comando;

// comparando as strings pra saber se são iguais, se sim retorna 1, se não retorna 0
int comparar(char *a, char *b)
{
    int i = 0, j = 0;
    for (; a[i] != '\0' && b[j] != '\0'; i++, j++)
    {
        if (a[i] != b[j])
            return 0;
    }
    if (i == j)
        return 1;
    return 0;
}

// recebe uma string (str) como entrada e retorna uma matriz de strings em que cada palavra da string original é armazenada em uma linha separada
char **separar_esp(char *str)
{
    int n_palavras = 1, i;

    // Alocar espaço para o array de palavras
    char **matriz = (char **)malloc(sizeof(char *) * n_palavras);

    char *token = strtok(str, " ");
    while (token != NULL)
    {
        matriz = realloc(matriz, sizeof(char *) * (n_palavras + 1));
        matriz[n_palavras - 1] = strdup(token);
        n_palavras++;
        token = strtok(NULL, " ");
    }
    matriz[n_palavras - 1] = NULL;
    return matriz;
}

void cmd_exit(char **matriz)
{
    exit(0);
}

void cmd_cd(char **matriz)
{
    if (matriz[1] != NULL)
    {
        if (chdir(matriz[1]) != 0)
        {
            perror("cd");
        }
    }
    else
    {
        printf("Uso: cd <diretorio>\n");
    }

    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
        printf("Diretorio atual: %s\n", cwd);
    }
    else
    {
        perror("getcwd");
    }
}

void cmd_help(char **matriz)
{
    printf("Comandos disponíveis:\n");
    printf("cd <diretorio>: Mudar para o diretório especificado\n");
    printf("exit: Sair do terminal\n");
    printf("help: Mostrar esta mensagem de ajuda\n");
    printf("ls: Listar os arquivos no diretório atual\n");
    printf("pwd: Mostrar o diretório atual\n");
    printf("clear: Limpar a tela\n");
}

void liberar_mem(char **matriz)
{
    for (int i = 0; matriz[i] != NULL; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

void executeCommandExt(char **matriz)
{
    pid_t pid, wpid;
    int status;

    pid = fork();

    if (pid == 0)
    {
        execvp(matriz[0], matriz);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
    else if (pid > 0)
    {
        do
        {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status)); // espera o processo mudar de estado
    }
    else
    {
        perror("fork");
    }
}

int main(void)
{
    char linha[50], **args;
    int TRUE = 1;
    printf("BEM VINDO AO TERMINAL \n");
    Comando comandos[] = {
        {"cd", cmd_cd},
        {"help", cmd_help},
        {"exit", cmd_exit},
    };

    do
    {
        printf("> "); // prompt pro usuário
        scanf("%[^\n]", linha);
        getchar();
        args = separar_esp(linha);
        int encontrado = 0;
        for (int i = 0; i < sizeof(comandos) / sizeof(comandos[0]); i++)
        {
            if (comparar(args[0], comandos[i].nome))
            {
                comandos[i].funcao(args);
                encontrado = 1;
                break;
            }
        }
        if (!encontrado)
        {
            executeCommandExt(args);
        }

        liberar_mem(args);
    } while (TRUE);

    return 0;
}