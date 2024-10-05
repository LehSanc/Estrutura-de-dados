//Bubble Sort com alocação dinâmica de memória

#include <stdio.h>
#include <stdlib.h>

void imprimirVetor(int *vetor, int tamanho) {
  for (int i = 0; i < tamanho - 1; i++) {
    printf("\n[%d]: %d", i, vetor[i]);
  }
  free(vetor);
}

void bubbleSort(int *vetor, int tamanho) {
  int aux = 0;
  for (int i = 0; i < tamanho - 1; i++) {
    for (int j = 1; j < tamanho - 1; j++) {
      if (vetor[j] < vetor[j - 1]) {
        aux = vetor[j - 1];
        vetor[j - 1] = vetor[j];
        vetor[j] = aux;
      }
    }
  }
  imprimirVetor(vetor, tamanho);
}

void receberVetor() {
  int *vetor = NULL;
  int tamanho = 1, numero = 0;

  printf("\nInforme os valores positivos de cada índice do vetor.\nDigite 0 em "
         "algum índice para encerrar o preenchimento.");

  // Na linguagem C usamos alocação dinâmica de memória para criar vetores sem a
  // necessidade de um tamanho pré definido.
  for (int i = 0; i < tamanho; i++) {

    // fazemos a verificaçao se o numero é positivo
    do {
      printf("\n[%d]:", i);
      scanf("%d", &numero);
    } while (numero < 0);

    // se o numero for diferente de 0, o vetor recebe o numero
    if (numero != 0) {
      vetor = (int *)realloc(vetor, tamanho * sizeof(int)); // alocamos memória
      if (vetor == NULL) {
        printf("Erro ao alocar memória para o vetor\n");
        exit(1);
      }

      // armazenamos o valor aumentamos o tamanho do vetor
      vetor[i] = numero;
      tamanho++;
    }
  }

  bubbleSort(vetor, tamanho); // chamamos a função de ordenação
}

int main() {
  receberVetor();
  return 0;
}
