#include <stdio.h>
#include <stdlib.h>

void imprimir(int **p){

    printf("\n *** FUNCAO *** \n");

    for(int i=0; i<4; i++){
         p++; 
        printf(" %d \n", *p);
         //desloca 4 bytes
    }

     printf("\n *** FUNCAO *** \n");
}

/*
void imprime1(int vet[]){
    for(int i=0; i<4; i++){

        printf("%d\n", *vet);
    }

}

void imprime2(int *vet){
    for(int i=0; i<4; i++){

        printf("%d\n", vet[i]);
        vet++;
    }

}

*/


int main(){

    int notas[4] = {7,8,9,10};
    int *p;

    p=&notas[0];
    
    imprimir(&p);

    
    for(int i=0; i<4; i++){
        printf("%d \n", *p);
        p++; //desloca 4 bytes
    }

    //Retorna dois blocos 4 bytes
    p-=2;
    printf("\n%d\n", *p);

    //Mostrando o endereço de inicio
    printf("\n%p - %p\n", notas, &notas[0]);

    //imprimir1(p);
    //imprimir2(&notas[0]);

    
    return 0;
}