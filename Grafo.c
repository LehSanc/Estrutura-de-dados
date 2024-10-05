#include <stdio.h>
#include <stdlib.h>
#define LINHAS 10

void estrelas(int **leao) {
  leao[1][0] = 1;
  leao[2][1] = 1;
  leao[3][2] = 1;
  leao[4][3] = 1;
  leao[5][4] = 1;
  leao[6][5] = 1;
  leao[7][6] = 1;
  leao[8][7] = 1;
  leao[9][3] = 1;
  leao[9][8] = 1;
}

int propriedade(int grauVertices[], int linhas) {
  int impar = 0;

  for (int i = 0; i < linhas; i++) {
    if (grauVertices[i] % 2 != 0) {
      impar++;
    }
  }

  switch (impar) {
  case 0:
    printf("Grafo euleriano\n");
    break;
  case 2:
    printf("Grafo semieuleriano\n");
    break;
  default:
    printf("Grafo comum\n");
    break;
  }

  return 0;
}

void grau(int **leao, int linhas) {
  int grauVertices[LINHAS] = {0};

  for (int i = 0; i < linhas; i++) {
    for (int j = 0; j <= i; j++) {
      if (leao[i][j] == 1) {
        grauVertices[i]++;
        grauVertices[j]++;
      }
    }
  }

  printf("\nGrau:\n");
  for (int i = 0; i < linhas; i++) {
    printf("Vertice %d:\t%d\n", i, grauVertices[i]);
  }

  propriedade(grauVertices, linhas);
}

int main(void) {

  int **leao;
  leao = (int **)malloc(LINHAS * sizeof(int *));

  if (leao == NULL) {
    printf("Erro ao alocar memória");
    return 1;
  }

  for (int i = 0; i < LINHAS; i++) {
    leao[i] = (int *)malloc((i + 1) * sizeof(int));
    if (leao[i] == NULL) {
      printf("Erro ao alocar memória");
      return 1;
    }
    for (int j = 0; j <= i; j++) {
      leao[i][j] = 0;
    }
  }

  estrelas(leao);

  printf("Matriz:\n");
  for (int i = 0; i < LINHAS; i++) {
    for (int j = 0; j <= i; j++) {
      printf("%d ", leao[i][j]);
    }
    printf("\n");
  }

  grau(leao, LINHAS);

  for (int i = 0; i < LINHAS; i++) {
    free(leao[i]);
  }
  free(leao);

  return 0;
}