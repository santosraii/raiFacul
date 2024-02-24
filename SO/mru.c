#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar uma página
typedef struct Page {
    int pageNumber;
    struct Page* next;
    struct Page* prev;
} Page;

// Função para criar uma nova página
Page* createPage(int pageNumber) {
    Page* newPage = (Page*)malloc(sizeof(Page));
    newPage->pageNumber = pageNumber;
    newPage->next = NULL;
    newPage->prev = NULL;
    printf("criou\n");
    return newPage;
}

// Função para mover uma página para o final da lista
void moveToEnd(Page** head, Page* page) {
    if (page->next == NULL) {
        // Já está no final da lista
        return;
    }

    if (page->prev != NULL) {
        page->prev->next = page->next;
    } else {
        // É a cabeça da lista
        *head = page->next;
        printf("add a prox pag no inicio da lista\n");

    }

    page->next->prev = page->prev;
    page->prev = NULL;
    page->next = NULL;

    // Adiciona a página no final
    Page* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
        printf("add a pag no final\n");
    }
    temp->next = page;
    page->prev = temp;
    printf("moveu para o fim\n");
}

// Função principal do LRU
void lru(int pages[], int total_pages, int total_frames) {
    Page* head = NULL;

    for (int i = 0; i < total_pages; i++) {
        int pageNumber = pages[i];
        Page* currentPage = NULL;

        // Verifica se a página já está na lista
        Page* temp = head;
        while (temp != NULL) {
            if (temp->pageNumber == pageNumber) {
                currentPage = temp;
                break;
            }
            temp = temp->next;
            printf("vendo se ta na lista\n");

        }

        if (currentPage == NULL) {
            // Página não está na lista, cria uma nova
            currentPage = createPage(pageNumber);

            // Verifica se a lista está cheia
            if (total_frames == 0) {
                // Remove a página menos recentemente usada (a cabeça da lista)
                Page* temp = head;
                head = head->next;
                if (head != NULL) {
                    head->prev = NULL;
                }
                free(temp);
                printf("lista ta cheia, mudou o inicio\n");

            } else {
                total_frames--;
            }
        }

        // Move a página para o final da lista (indicando uso mais recente)
        moveToEnd(&head, currentPage);
        printf("foi pro fim\n");


        // Imprime o estado atual da lista
        temp = head;
        while (temp != NULL) {
            printf("[%d] ", temp->pageNumber);
            temp = temp->next;
        }
        printf("\n");
    }

    // Libera a memória alocada para as páginas no final
    Page* temp = head;
    while (temp != NULL) {
        Page* next = temp->next;
        free(temp);
        temp = next;
    }
    printf("liberou tudo\n");

}

int main() {
    int total_pages, total_frames;

    printf("Digite o número total de páginas: ");
    scanf("%d", &total_pages);

    printf("Digite o número total de quadros de página: ");
    scanf("%d", &total_frames);

    int pages[total_pages];

    printf("Digite as referências de página: \n");
    for (int i = 0; i < total_pages; i++) {
        printf("Referência %d: ", i + 1);
        scanf("%d", &pages[i]);
    }

    printf("Estado da lista após cada referência:\n");
    lru(pages, total_pages, total_frames);

    return 0;
}
