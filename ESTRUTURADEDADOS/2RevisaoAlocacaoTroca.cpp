#include <stdio.h>
#include <stdlib.h>

void mostrar(int *vetor, int n){

        printf("\n FUNCAO");

        if(vetor!=NULL){
            for(int i=0; i<n; i++){

                 printf("\n %p - %d", vetor[i], vetor[i]); 

            }

        }

}

int main(){

    int *vetor, i;

    vetor = (int*)malloc(20*sizeof(int));


    if(vetor!=NULL){
        for(i=0; i<20; i++){

            vetor[i] = i;
            
        }

    }

    int *vetorInicio = vetor;
    int *vetorFim = &vetor[19];
    int aux;

        for(i=0; i<10; i++){

            aux = *vetorInicio;
            *vetorInicio =  *vetorFim ;
            *vetorFim = aux;

            vetorInicio++;
            vetorFim--;

        }
    
    mostrar(vetor, 20);

    return 0;
}