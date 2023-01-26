#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct pilhaLaco{
    char valor;
    struct pilhaLaco *abaixo;
}PilhaLaco;

typedef struct pilha{
    int tamanho;
    PilhaLaco *topo;
}Pilha;

void push(Pilha *P, char valor){

    P->tamanho += 1;
    PilhaLaco *novoTopo = (PilhaLaco*) malloc(sizeof(PilhaLaco));

        novoTopo->valor = valor;
        novoTopo->abaixo = P->topo;
        P->topo = novoTopo;
}

void pop(Pilha *P){

    if(P->tamanho > 0){
        P->tamanho -= 1;
        PilhaLaco *velhoTopo = P->topo;
        P->topo = P->topo->abaixo;
        free(velhoTopo);
    }
} 

char top(Pilha *P){
    
    return P->topo->valor;
}

int tam(Pilha *P){

    return P->tamanho;
}

int vazio(Pilha *P){

    return P->tamanho == 0;
}

void inicializa(Pilha *P){

    P->tamanho = 0;
    P->topo = NULL;
}

void limpa(Pilha* P){

    while(!vazio(P)){
        pop(P);
    }
}

int main(){
    Pilha P;
    int N, tamanho=0, resposta=0, k=0, i=0;
    char expressao[1001];

    scanf("%d\n", &N);

    for(k; k < N; ++k){
        scanf("%s\n", &expressao);

        inicializa(&P);
        tamanho = strlen(expressao);

        for(i; i < tam; ++i){

            if(expressao[i] == '<'){
                push(&P, '<');

            }else if(expressao[i] == '>'){

                if(!vazio(&P)){

                    resposta++;
                    pop(&P);
                }
            }
        }

        printf("%d\n", resposta);

        limpa(&P);
    }

    return 0;
}