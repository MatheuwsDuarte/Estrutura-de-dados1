#include <stdio.h>
#include <stdlib.h>


void mostrar(int *p){

        printf("\n FUNCAO");

        if(p!=NULL){
            for(int i=0; i<5; i++){

                 printf("\n %p - %d", p[i], p[i]); 

            }

        }

}

int main(){

    int *p;

    p = (int*)malloc(3*sizeof(int));

    if(p != NULL){
        for(int i=0; i<3; i++){

            p[i]= i;

        }
    }
    
    for(int i=0; i<3; i++){

        p[i]= i;
        printf("\n %p - %d", p[i], p[i]);
    }

    printf("\n REALLOC");

    p= (int*)realloc(p,5*sizeof(int));

    if(p != NULL){
        for(int i=3; i<5; i++){

            p[i]= i;

        }
    }

    for(int i=3; i<5; i++){

        p[i]=i;
        printf("\n %p - %d", p[i], p[i]);

    }

    mostrar(p);

    return 0;
}
