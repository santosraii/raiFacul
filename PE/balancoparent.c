#include <stdio.h>

int parenteses(char expre[])
{
    int j, contar = 0;

        for (j = 0; expre[j] != '\0'; j++){

            if (expre[j] == ')'){
                if (contar <= 0){
                    printf("incorrect\n");
                    return 0;
                } 
                contar = contar - 1;
            }
            if (expre[j] == '('){
                contar = contar + 1;
            }
        }
        if (contar == 0){
            printf("correct\n");
        }
        else{
            printf("incorrect\n");
        }
}

int main(){

    char expre[1000];
    scanf("%s", expre);
    parenteses(expre);

    return 0;
}