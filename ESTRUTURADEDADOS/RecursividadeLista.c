#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
  int valor;
  struct lista* prox;
}Lista;

Lista *insereFim(Lista *L, int info){

    if(L==NULL){
        Lista* novo = malloc(sizeof(Lista));
        novo->valor = info;
        novo->prox = NULL;

        return novo;
    }else{

        L->prox = insereFim(L->prox, info);
        return L;
    }

}

int mostrarMaior(Lista *L){

    int maior=0;

    if(L==NULL){

        return 0;
    
    }else{

        maior = mostrarMaior(L->prox);      
    
        if(maior > L->valor){
            return maior;
        }
        else{
              return L->valor;
        }
    }
    
}

Lista *remove(Lista *L, int info){

    if(L==NULL){

        return NULL;
        
    }

}

void imprime(Lista *L){

    if (L!=NULL)
    {   
        printf("%d\n", L->valor);    
        imprime(L-> prox);
    }

}

int main(){

    int maior;

    Lista* pLista = NULL;
    pLista = insereFim(pLista, 30);
    pLista = insereFim(pLista, 90);
    pLista = insereFim(pLista, 60);
    pLista = insereFim(pLista, 70);
 
    imprime(pLista);
    maior = mostrarMaior(pLista);
    printf("\nMaior: %d", maior);
  
    
     
  return (0);

}