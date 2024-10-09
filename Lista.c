#include<stdio.h>
#include<malloc.h>

typedef struct temp{				
  int chave;			
  struct temp *prox;			
}membro;

membro *aux, *start; 
int contador=0;

main(){
    
  start = NULL;
  for(int i=1; i<=5; i++){
    aux = (membro*) malloc (sizeof(membro)); 
    printf("\nDigite a chave do membro = "); 
    scanf("%d",&aux->chave);
    contador++;
    if (start==NULL) aux-> prox=NULL;
    else aux->prox = start; 
    start = aux;
  }
  
//adcionar na quarta posição 
  printf("\nAdicionar novo elemento na quarta posição");
  aux = (membro *)malloc(sizeof(membro));
  printf("\nDigite a chave do membro = ");
  scanf("%d", &aux->chave);
  aux->prox = start->prox->prox;
  start->prox->prox = aux;
  contador++;
  
//adcionar na sexta posição 
  printf("\nAdicionar novo elemento na sexta posição");
  aux = (membro *)malloc(sizeof(membro));
  printf("\nDigite a chave do membro = ");
  scanf("%d", &aux->chave);
  aux->prox = start->prox->prox->prox->prox;
  start->prox->prox->prox->prox = aux; 
  contador++;
  
//adcionar na primeira posição 
  printf("\nAdicionar novo elemento na primeira posição");
  aux = (membro*) malloc (sizeof(membro));
  printf("\nDigite a chave do membro = "); 
  scanf("%d",&aux->chave);
  aux->prox = start;
  start=aux;
  contador++;
  
//exclua o terceiro elemento 
  aux = start->prox->prox;
  start->prox->prox = aux->prox;
  free(aux);
  
  printf("\nForam alocados os seguintes elementos:\n");
  aux = start;
  while (aux != NULL)
  {
    printf("\n%d", aux->chave);
    aux = aux->prox;
  }
  printf("\nNULL");

  return 0;
}	
