#include <stdio.h>

typedef struct dados{
  int chave;
  struct dados *direita;
  struct dados *esquerda;
}arvore;

arvore *raiz, *aux;

arvore* novoNo(int chave){
  aux = (arvore*) malloc (sizeof(arvore));
  aux->chave = chave;
  aux->esquerda = NULL;
  aux->direita = NULL;
  return aux;
}

void excluirFolha(arvore **raiz, int chave){
  //pré-ordem
  if((*raiz)->chave == chave){
    if((*raiz)->esquerda == NULL && (*raiz)->direita == NULL){
      free(*raiz);
      printf("Elemento excluído com sucesso\n");
    } else{
      printf("Não foi possível excluir visto que não se trata de uma folha\n");
    }
  }
    
  else if (aux->esquerda != NULL) {
    (*raiz) = (*raiz)->esquerda;
    excluirFolha((&*raiz), chave);
  }
  else if ((*raiz)->direita != NULL){
    (*raiz) = (*raiz)->direita;
    excluirFolha((&*raiz), chave);
  }
}
  
void imprimirArvoreAux(arvore *aux, int espaco) {
  if (aux == NULL) {
    return;
  }
  espaco += 10; // Aumenta a distância entre os níveis
  imprimirArvoreAux(aux->direita, espaco);
  printf("\n");
  for (int i = 10; i < espaco; i++) {
    printf(" ");
  }
  printf("%d\n", aux->chave);
  imprimirArvoreAux(aux->esquerda, espaco); 
}

void imprimirArvore(arvore *aux) {
  imprimirArvoreAux(aux, 0);
}

int main(void) {
  int elemento=0;
  
  raiz = novoNo(10);
  raiz->esquerda = novoNo(7);
  raiz->esquerda->esquerda = novoNo(3);
  raiz->esquerda->direita = novoNo(2);
  raiz->direita = novoNo(15);
  raiz->direita->esquerda = novoNo(2);
  raiz->direita->direita = novoNo(11);

  printf("Árvore antes da exclusão:\n");
  imprimirArvore(raiz);
  printf("\n");

  printf("Qual elemento deseja excluir?\n");
  scanf("%d", &elemento);
  excluirFolha(&raiz, elemento);
}