// Essa função recebe um vetor de caracteres com alocação dinâmica e faz uma
// busca por palavras de tamanho maior que 3.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *vetorCaracteres() {
  char *frase = NULL;
  int tamanho = 0;
  char letra;

  frase = (char *)realloc(frase, (tamanho + 1) * sizeof(char));

  if (frase == NULL) {
    printf("\nErro de alocação");
    exit(1);
  }

  while ((letra = getchar()) != '\n') {
    frase = (char *)realloc(frase, (tamanho + 1) * sizeof(char));

    if (frase == NULL) {
      printf("\nErro de alocação");
      exit(1);
    }

    frase[tamanho] = tolower(letra);
    tamanho++;
  }

  if (frase == NULL) {
    printf("\nErro de alocação");
    exit(1);
  }
  frase[tamanho] = '\0';
  return frase;
}

int pesquisar(char *frase, char *palavra) {

  char *resultado = strstr(frase, palavra);
  if (resultado == NULL) {
    printf("\nPalavra nao encontrada.");
    exit(1);
  }

  printf("\nPalavra encontrada: %s", palavra);
  free(frase);
  free(palavra);
  return 1;
}

int main(void) {

  printf("\nDigite uma frase:");
  char *frase = vetorCaracteres();

  printf("\nDigite a palavra a ser pesquisada:");
  char *palavra = vetorCaracteres();

  if (pesquisar(frase, palavra))
    return 0;
  else
    return 1; // Erro na função pesquisar
}