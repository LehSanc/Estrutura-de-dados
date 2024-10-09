#include<stdio.h>
#include<malloc.h>

typedef struct temp{				
	int chave;			
	struct temp *prox;			
}membro;

typedef struct tempII{
  int chave;
  struct tempII *prox;
}membroII;

membro *topo, *aux;	
membroII *topoII;

main(){
  
	topo = NULL;
  
	for(int i=1; i<=5; i++){
    
		aux = (membro*) malloc (sizeof(membro)); 
		printf("\nDigite a chave do membro %d = ",i); 
		scanf("%d",&aux->chave);

		if (topo==NULL) aux->prox=NULL;

		else aux->prox=topo; 
		topo = aux;

	}

  //Parte 1
  
  //Adicionar três novos elementos
  printf("\nVamos adicionar mais três elementos:\n");

  for(int i=1; i<=3; i++){

    aux = (membro*) malloc (sizeof(membro));
    printf("\nDigite a chave do membro %d = ",i+5);
    scanf("%d",&aux->chave);

    aux->prox=topo;
    topo=aux;
  }	
  

  //impressão dos elementos
	printf("\nForam alocados os seguintes elementos:\n");

	aux = topo;
	int i = 1;
  while(aux!=NULL){
	printf("\nElemento %d = %d",i++,aux->chave);
	aux = aux->prox; 
	}

  
  //Desalocar dois elementos
  for(int i=1; i<=2; i++){
    aux = topo;
    topo = topo->prox;
    free(aux);
  }

  //Parte 2

  //Nova estrutura com 5 elementos
  topoII = NULL;

  for(int i=1; i<=5; i++){
    aux = (membroII*) malloc (sizeof(membroII));
    printf("\nDigite a chave do membro %d = ",i);
    scanf("%d", &aux->chave);

    if(topoII == NULL) aux->prox = NULL;
    else aux->prox = topoII;

    topoII = aux;
  }

  //União das duas estruturas
  i=1;
  while (topoII != NULL){
    aux = (membro*) malloc (sizeof(membro));
    aux->chave = topoII->chave;
    aux->prox = topo;

    topo = aux;
    aux = topoII;
    topoII = topoII->prox;
    free(aux);
  }

  //Impressão do resultado da junção 
  printf("\nResultado dos elementos unidos:\n");

  aux = topo;
  i = 1;
  while(aux!=NULL){
  printf("\nElemento %d = %d",i++,aux->chave);
  aux = aux->prox; 
  }

  //Esvaziar a pilha
  while(topo!=NULL){
    aux = topo;
    topo = topo->prox;
    free(aux);
  }
  
}