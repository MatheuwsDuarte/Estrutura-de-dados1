#include <stdio.h>
#include <stdlib.h>

//Deslocar nao usa malloc

typedef struct lista{
    int valor;
    struct lista* prox;
    struct lista* ant;

}ListaD;

ListaD* inserirInicial(){




}

ListaD* inserirFinal(){



    
}



int main(void){

    ListaD *L = (ListaD*)malloc(sizeof(ListaD));

    L-> valor = 10;
    L-> prox = NULL;
    L -> ant = NULL;

    printf("%d", L-> valor);

    ListaD *aux = (ListaD*)malloc(sizeof(ListaD));

    aux -> valor = 20;
    aux -> prox = NULL;
    aux -> ant = L;
    L->prox = aux;

    printf("\n %d - %d", L-> valor, L->prox->valor );

    return 0;
}