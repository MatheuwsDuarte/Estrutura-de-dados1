#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{

    char nome[30];
    int ra;
    float media;

}Aluno;



int main(){

    Aluno  *pa;

    pa = (Aluno*)malloc(2*sizeof(Aluno));

    
    strcpy(pa->nome, "Matheus");
    pa->media = 10;
    pa->ra = 2417820;

    printf("\n -----------------------");

    printf("\n Nome: %s", pa->nome);
    printf("\n RA: %d", pa->ra);
    printf("\n Media: %f", pa->media);

    return 0;
}