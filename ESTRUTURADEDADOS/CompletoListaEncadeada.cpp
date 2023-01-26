#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
  int valor;
  struct lista *prox;
  struct lista *ant;
} ListaD;

ListaD* removeLista(ListaD* L, int info){

    ListaD* aux = L;

  if(L==NULL)//Lista vazia
    return L;
 
  while(aux!=NULL && aux->valor != info){
    aux = aux->prox;
  }
  if(aux==NULL) //info nao esta na Lista
    return L;

  //Remove o primeiro
  if(aux->ant == NULL){
    L = L->prox;
    L->ant = NULL;
    free(aux);  
  }else if(aux->prox == NULL){
    aux->ant->prox = NULL;
    free(aux);
  }else{//meio da lista
    aux->ant->prox = aux->prox;
    aux->prox->ant = aux->ant;
    free(aux);    
  }  
   return L;
}

ListaD *insereIni(ListaD *L, int info) {
  ListaD *novo = (ListaD *)malloc(sizeof(ListaD));
  novo->valor = info;
  novo->prox = L;
  novo->ant = NULL;
  if (L != NULL)
    L->ant = novo;
  return novo;
}

ListaD *insereFim(ListaD *L, int info) {
  ListaD *novo = (ListaD *)malloc(sizeof(ListaD));
  novo->valor = info;
  novo->prox = NULL;

  if (L == NULL) {
    novo->ant = NULL;
    return novo;
  } else {
    ListaD *aux = L;
    while (aux->prox != NULL) {
      aux = aux->prox;
    }
    novo->ant = aux;
    aux->prox = novo;
  }
  return L;
}

void imprime(ListaD *L) {
  printf("Lista:\n");
  while (L != NULL) {
    printf("%d\n", L->valor);
    L = L->prox;
  }
}

ListaD *liberaLista(ListaD *L) {
  ListaD *aux = L;
  while (L != NULL) {
    L = L->prox;
    free(aux);
    aux = L;
  }
  return NULL;
}

int main(void) {
  ListaD *L = NULL;


  imprime(L);
  L = liberaLista(L);
}