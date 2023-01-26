#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>


typedef struct lista{
    int valor;
    struct lista *prox; //ponteiro que guardar endereços do tipo lista
}Lista;


int main(){
    
    int foram, voltaram, qtdeMergulhadores=20,  i;
    Lista *QtdeVoltaram = NULL, *aux, *qtdeVoltou;


    qtdeVoltou = (Lista*)malloc(5*sizeof(Lista));
    QtdeVoltaram= (Lista*)malloc(qtdeMergulhadores*sizeof(Lista)); 

    aux = QtdeVoltaram;

    while(aux != NULL){

            aux-> valor = 0;

            aux = aux -> prox;

        }

    while(scanf("%d %d", &foram, &voltaram)==2){

        if(foram==voltaram){

            for (i = 1; i <= voltaram; i++) { 


                scanf("%d", & qtdeVoltou->valor); 
                
            }

            printf("*");

        }

        else{
            while(qtdeVoltou->valor <= voltaram){

                scanf("%d", &qtdeVoltou->valor);

                qtdeVoltou-> valor = 1;

                aux -> prox = qtdeVoltou;

            }
        

        while(aux->valor <= foram){

            if(aux->valor != NULL){

                printf("%d", i);
                
            }


            aux -> valor = 0;

            aux = aux -> prox;

        }

    }

        printf("\n");

    }

    return 0;
}