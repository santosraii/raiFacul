#include <stdio.h>
#include <stdlib.h>

struct DATA {
	int dia;
	int mes;
	int ano;
};

struct REGISTRO {
	char descricao[1000];
	struct DATA data;
	float valor;
};

struct LIVRO_CAIXA {
	struct REGISTRO vetor[100];
    int total;
};

int main(void) {

    FILE *documento;
    char nomearquivo[16];
    int ano, i;
    float imposto = 0, lucro = 0;
    struct LIVRO_CAIXA caixa;

    scanf("%s %d", nomearquivo, ano);

    documento = fopen(nomearquivo, "r+");

    if(documento == NULL)
    {
        printf("Não é possível abrir o arquivo");
        return 1;
    }

    fread(&caixa, sizeof(struct LIVRO_CAIXA), 1, docmento);

    for (i = 0; i < caixa.total; i++) {
        if (caixa.vetor[i].data.ano == ano) {
            lucro += caixa.vetor[i].valor;
            imposto += abs(caixa.vetor[i].valor) * 0.15;
        }
    }

    imposto += lucro * 0.32;
    printf("R$ %.2f", imposto);

	return 0;
}
