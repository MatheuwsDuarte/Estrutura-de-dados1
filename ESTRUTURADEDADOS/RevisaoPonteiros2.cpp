#include <stdio.h>
#include <stdlib.h>


int main(){

    int n[10], *pn;

    pn = n;

    for(int i=0; i<10; i++){

        printf("\n Digite um numero: ");
        scanf("%d", pn);
        pn++;

    }   

    pn = n + 9;


    for(int i=0; i<10; i++){
        
        printf("\n %d", *pn);
        pn--;


    } 
    

    

    return 0;
}