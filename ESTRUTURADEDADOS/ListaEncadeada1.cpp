#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    int valor;
    struct lista *prox; //ponteiro que guardar endereços do tipo lista
}Lista;

int main(){
    
    Lista *pLista = NULL;
    
    pLista = (Lista*)malloc(sizeof(Lista)); //Ponteiro de referencia de inicio //malooc devolve o endereço de inicio

    pLista -> valor = 10;

    pLista -> prox = (Lista*)malloc(sizeof(Lista)); 

    pLista -> prox -> valor = 20;

    pLista -> prox -> prox = (Lista*)malloc(sizeof(Lista));

    pLista -> prox -> prox -> valor = 30;

    pLista -> prox -> prox -> prox = NULL;

    return 0;
}