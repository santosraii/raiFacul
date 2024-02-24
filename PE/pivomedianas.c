#include <stdio.h>

int PivoMedianas(int S[], int p, int r) {
  if (r - p < 3) {
    return p;  // Não há elementos suficientes para calcular a mediana
  }
  else {
    int a = S[p];
    int b = S[p + 1];
    int c = S[p + 2];
    // Calcule a mediana dos três elementos
    int mediana; //= a;
    if ((b < a && a < c) || (c < a && a < b)) {
      mediana = a;
    }
    else if ((a < b && b < c) || (c < b && b < a)) {
      mediana = b;
    }
    else {
      mediana = c;
    }

    // Encontre o índice da mediana nos elementos originais
    if (mediana == a) {
      return p;
    }
    else if (mediana == b) {
      return p + 1;
    }
    else {
      return p + 2;
    }
  }
}

int main()
{
    int vetor[]={50, 49876, 567};
    printf("%d",PivoMedianas(vetor , 0, sizeof(vetor)/sizeof(*vetor)));
    return 0;
}