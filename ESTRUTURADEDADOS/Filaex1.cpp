#include <stdio.h>
#include <stdlib.h>


typedef struct lista{

    int valor;
    struct lista *prox;


}Lista;


typedef struct fila{

    Lista *ini;
    Lista *fim;


}Fila;

void inserirFinal(Fila *f, int info){

    Lista *aux = (Lista*)malloc(sizeof(Lista));


     aux ->  valor = info;
     aux ->  prox = NULL;

    //verificar fila vazia

        if(f->ini == NULL){

            f -> ini = aux;
            f -> fim = aux;

        }else{

            f -> fim -> prox = aux;
            f -> fim = aux;

        }

}

void imprime(Fila *f){

    Lista *aux = f -> ini;

        while(aux!=NULL){

            printf(" %d -", aux -> valor);

            aux= aux -> prox;

        }

}


int main(){

    /*
    Lista *lista = (Lista*)malloc(sizeof(Lista));

    lista -> valor =10;
    lista -> prox = NULL;
    */

    Fila *fila = (Fila*)malloc(sizeof(Fila));

    //Criar a fila
    fila -> ini = NULL;
    fila -> fim = NULL;

    inserirFinal(fila, 10);
    inserirFinal(fila, 20);
    inserirFinal(fila, 30);

    imprime(fila);

    return 0;
}