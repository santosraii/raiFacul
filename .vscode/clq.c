#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 100

bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
int numVertices;

bool isClique(int vertices[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (!adjMatrix[vertices[i]][vertices[j]]) {
                return false;
            }
        }
    }
    return true;
}

bool findClique(int vertices[], int size, int k) {
    if (size == k) {
        return isClique(vertices, size);
    }
    int lastVertex = (size == 0) ? 0 : vertices[size - 1] + 1;
    for (int i = lastVertex; i < numVertices; i++) {
        vertices[size] = i;
        if (findClique(vertices, size + 1, k)) {
            return true;
        }
    }
    return false;
}

bool hasClique(int k) {
    int vertices[MAX_VERTICES];
    return findClique(vertices, 0, k);
}

int main() {
    int k;
    printf("Digite o número de vértices da clique (k): ");
    scanf("%d", &k);
    
    printf("Digite o número de vértices do grafo: ");
    scanf("%d", &numVertices);
    
    printf("Digite a matriz de adjacência do grafo:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &adjMatrix[i][j]);
        }
    }
    
    if (hasClique(k)) {
        printf("Existe uma clique com pelo menos %d vértices.\n", k);
    } else {
        printf("Não existe uma clique com pelo menos %d vértices.\n", k);
    }
    
    return 0;
}
