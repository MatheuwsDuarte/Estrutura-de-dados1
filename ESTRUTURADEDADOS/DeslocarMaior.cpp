#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>


typedef struct lista{
    int valor;
    struct lista *prox; //ponteiro que guardar endereços do tipo lista
}Lista;

Lista* deslocaMaior(Lista *pLista, int info){

    Lista *maior;
    Lista *aux = pLista;

    maior = (Lista*)malloc(sizeof(Lista));

    maior -> valor = info;

        while(aux != NULL){

            if((aux -> valor) > (maior -> valor)){

                maior -> valor = aux -> valor;

            }

             aux = aux -> prox;
        }
    
    maior -> prox = pLista;

    return maior;
}

void imprimir(Lista *pLista){

     Lista *aux = pLista;

        while(aux != NULL){

            printf("\n %d", aux -> valor);

            aux = aux -> prox;

        }
}

int main(){
    
    Lista* pLista = NULL;
    
    pLista = (Lista*)malloc(sizeof(Lista)); //Ponteiro de referencia de inicio //malooc devolve o endereço de inicio

    pLista -> valor = 10;

    pLista -> prox = (Lista*)malloc(sizeof(Lista)); 

    pLista -> prox -> valor = 20;

    pLista -> prox -> prox = (Lista*)malloc(sizeof(Lista));

    pLista -> prox -> prox -> valor = 30;

    pLista -> prox -> prox -> prox = NULL;

    pLista = deslocaMaior(pLista, 5);

    imprimir(pLista);

    return 0;
}