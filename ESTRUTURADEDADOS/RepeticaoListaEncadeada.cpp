#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>


typedef struct lista{
    int valor;
    struct lista *prox; //ponteiro que guardar endereços do tipo lista
}Lista;

void imprimir(Lista *pLista){

     Lista *aux = pLista;

        while(aux != NULL){

            printf("\n %d", aux -> valor);

            aux = aux -> prox;

        }
}

Lista* inserirInicial(Lista *pLista, int info){

    Lista *inicial;

    inicial = (Lista*)malloc(sizeof(Lista));

    inicial -> valor = info;

    inicial -> prox = pLista; //Liga o novo com o primeiro

    return inicial;
}
Lista* inserirFinal(Lista *pLista, int info){

    Lista *final = (Lista*)malloc(sizeof(Lista));
    Lista *aux = pLista;

    final -> valor = info;

    final -> prox = NULL;
    
        if(pLista == NULL){

                return final;
        }


        while(aux -> prox != NULL){

            aux =  aux -> prox;

        }
        
        aux -> prox = final;
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

    pLista = inserirInicial(pLista, 5);

    inserirFinal(pLista, 40);

    imprimir(pLista);

    return 0;
}