// Essa função recebe um vetor de caracteres com alocação dinâmica e faz uma
// busca por palavras

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Em C não é possível declarar uma função que retorne diretamente um array
// arrays em C são tratados como ponteiros
char *vetorCaracteres() {
  char *frase = NULL;
  int tamanho = 0;
  char letra;

  // alocamos memória para receber o caracter
  frase = (char *)realloc(frase, (tamanho + 1) * sizeof(char));

  if (frase == NULL) {
    printf("\nErro de alocação");
    exit(1);
  }

  // enquanto o enter não for pressionado continuaremos a capiturar letras
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

  // strstr( ) faz a pesquisa da palavra no vetor
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
