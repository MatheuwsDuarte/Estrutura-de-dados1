#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    int valor;
    struct lista *prox; //ponteiro que guardar endereços do tipo lista
}Lista;

void Imprimir(Lista pLista){

    Lista *aux = pLista;

        while(aux != NULL){

            printf("\n %d", aux -> valor);

            aux = aux -> prox;

        }


}

void inserirInicial(Lista *aux){

    Lista *inicial = aux;

    inicial = (Lista*)malloc(sizeof(Lista));


    inicial -> valor = 5;

    inicial -> prox = null;


}


int main(){

    Lista *pLista = NULL;
    
    pLista = (Lista*)malloc(sizeof(Lista));

    pLista -> valor = 10;

    pLista -> prox = (Lista*)malloc(sizeof(Lista)); 

    pLista -> prox -> valor = 20;

    pLista -> prox -> prox = (Lista*)malloc(sizeof(Lista));

    pLista -> prox -> prox -> valor = 30;

    pLista -> prox -> prox -> prox = NULL;

    InserirInicial(pLista);
    Imprimir(pLista);

    return 0;
}