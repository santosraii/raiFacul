#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 3
int page_faults = 0;

struct page {
  int id;
  int reference_bit;
  int last_referenced;
};
typedef struct page Page;

void printPages(Page pages[]) {
    printf("Estado da Memória Principal:\n");
    for (int i = 0; i < MAX; i++) {
        if(pages[i].reference_bit == 1){
        printf("Página %d: Referenciada=%d, Última Referência=%d\n", pages[i].id, pages[i].reference_bit, pages[i].last_referenced);
        }
    }
    printf("\n");
}

void replacePage(Page pages[], int new_page_id, int current_cycle, int N) {
    int i, least_recently_referenced = -1;
    int not_referenced_in_N_cycles = -1;

    // Percorre todas as páginas na memória cache
    for (i = 0; i < MAX; i++) {
        // Verifica se a página não foi referenciada e se o tempo desde a última referência é maior que N ciclos
        if (pages[i].reference_bit == 0 && (current_cycle - pages[i].last_referenced > N) || pages[i].reference_bit == 1 && (current_cycle - pages[i].last_referenced > N)) {
            // Verifica se é a primeira página não referenciada nos últimos N ciclos ou se foi referenciada menos recentemente
            if (not_referenced_in_N_cycles == -1 || pages[i].last_referenced < pages[not_referenced_in_N_cycles].last_referenced) {
                // Atualiza o índice da página não referenciada nos últimos N ciclos
                not_referenced_in_N_cycles = i;
            }
        }
        // Verifica se é a primeira página ou se foi referenciada menos recentemente
        if (least_recently_referenced == -1 || pages[i].last_referenced < pages[least_recently_referenced].last_referenced) {
            // Atualiza o índice da página menos recentemente referenciada
            least_recently_referenced = i;
        }
    }

    // Substitui a página não referenciada nos últimos N ciclos, se existir
    if (not_referenced_in_N_cycles != -1) {
        pages[not_referenced_in_N_cycles].id = new_page_id;
        pages[not_referenced_in_N_cycles].reference_bit = 1;
        pages[not_referenced_in_N_cycles].last_referenced = current_cycle;
        printf("Página %d substituída pela página não referenciada nos ultimos %d ciclos.\n", pages[not_referenced_in_N_cycles].id, N);
      page_faults++;
    }
    // Caso contrário, substitui a página menos recentemente referenciada
    else if (least_recently_referenced != -1) {
        pages[least_recently_referenced].id = new_page_id;
        pages[least_recently_referenced].reference_bit = 1;
        pages[least_recently_referenced].last_referenced = current_cycle;
        printf("Página %d substituída pela pagina menos recentemente referenciada.\n", pages[least_recently_referenced].id);
      page_faults++;
    }
    // Se não houver páginas elegíveis para substituição, imprime uma mensagem
    else {
        printf("Nenhuma página foi substituída.\n");
    }
  printPages(pages);
}
void referencePage(Page pages[], int page_id, int current_cycle) {
    int i;

    for (i = 0; i < MAX; i++) {
        if (pages[i].id == page_id) {
            pages[i].reference_bit = 1;
            pages[i].last_referenced = current_cycle;
            printf("Página %d referenciada.\n", pages[i].id);
            printPages(pages);
            return;
        } else if (pages[i].id == -1) {  // ID -1 indica espaço livre
            pages[i].id = page_id;
            pages[i].reference_bit = 1;
            pages[i].last_referenced = current_cycle;
            printf("Página %d incluída na memória.\n", pages[i].id);
            printPages(pages);
            return;
        }
    }

    // Se não houver espaço livre, realizar a substituição
    replacePage(pages, page_id, current_cycle, 2);
}

void clearReferenceBits(Page pages[]) {
    int i;
    for (i = 0; i < MAX; i++) {
        pages[i].reference_bit = 0;
    }
    printPages(pages);
}

int main() {
Page pages[MAX];
    char page_ids[] = "70120304230321201701";  // Sua string de IDs de páginas
    int num_pages = strlen(page_ids);

    // Inicializa as páginas
    for (int i = 0; i < MAX; i++) {
        pages[i].id = -1;
        pages[i].reference_bit = 0;
        pages[i].last_referenced = -1;
    }

    // Referencia as páginas de acordo com a string de IDs
    for (int i = 0; i < num_pages; i++) {
        int page_id = page_ids[i] - '0';  // Converte o caractere para um número
        referencePage(pages, page_id, i);
    }

    printf("Número total de page faults: %d\n", page_faults);  // Imprime o número total de page faults

    // Limpa os bits de referência após N ciclos
    clearReferenceBits(pages);

    return 0;
}