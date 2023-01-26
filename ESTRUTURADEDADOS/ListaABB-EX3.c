#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

struct arv {
    int info;
    struct arv* esq;
    struct arv* dir;
};
typedef struct arv Arv;

Arv* abb_cria (void)
{
   return NULL;
}

void abb_imprime (Arv* a)
{
    if (a != NULL) {
        abb_imprime(a->esq);
        printf("%d\n",a->info);
        abb_imprime(a->dir);
    }
}

// Imprime formatado
void print2DTree(Arv *root, int space) {
  // Caso base;
  if (root == NULL)
    return;

  // Aumento da distância entre os níveis
  space += COUNT;

  // Avalia primeiro o nó direita
  // Vai empilhar todas subárvores direitas;
  print2DTree(root->dir, space);

  // Imprime o nó no retorno da recursão
  for (int i = COUNT; i < space; i++)
    printf(" ");
  printf("%d\n", root->info);

  // Avalia o nó esquerda
  print2DTree(root->esq, space);
}

Arv* abb_insere (Arv* a, int v)
{
    if (a==NULL) {
        a = (Arv*)malloc(sizeof(Arv));
        a->info = v;
        a->esq = a->dir = NULL;
    }
    else if (v < a->info)
         a->esq = abb_insere(a->esq,v);
    else // v > a->info
         a->dir = abb_insere(a->dir,v);
    return a;
}

Arv* abb_retira (Arv* r, int v)
{
    if (r == NULL)
       return NULL;
    else if (r->info > v)
         r->esq = abb_retira(r->esq, v);
    else if (r->info < v)
         r->dir = abb_retira(r->dir, v);
    else {// achou o nó a remover
     //nó sem filhos
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            r = NULL;
        }
        // nó só tem filho à direita
        else if (r->esq == NULL) {
            Arv* t = r;
            r = r->dir;
            free(t);
        }
        // só tem filho à esquerda
        else if (r->dir == NULL) {
            Arv* t = r;
            r = r->esq;
            free(t);
        }
        // nó tem os dois filhos
        else {
            Arv* f = r->esq;
            while (f->dir != NULL) {
                  f = f->dir;
            }
            r->info = f->info; // troca as informações
            f->info = v;
            r->esq = abb_retira(r->esq,v);
        }
   }
   return r;
}

//A)
int um_filho(Arv* arv){

    if(arv==NULL){
		return 0;
	}

        if(arv->esq != NULL && arv->dir == NULL){
            return 1 + um_filho(arv->esq);
            
        }else if(arv->esq == NULL && arv->dir != NULL){
            return 1 + um_filho(arv->dir);
            
        }else{ 
            return um_filho(arv->esq) + um_filho(arv->dir);
        }
    
}

//B)
int intermediarios(Arv* arv){

    if(arv==NULL){
		return 0;
	}
	
        if(arv->esq == NULL && arv->dir == NULL){
            return 0;

        }else{

            return 1 + intermediarios(arv->esq) + intermediarios(arv->dir);

        }
	
}

int main(){

    Arv* abb;
    int nFilhos=0, nIntermediario=0;

    abb = abb_cria();
    abb = abb_insere(abb, 15);
    abb = abb_insere(abb, 10);
    abb = abb_insere(abb, 22);
    abb = abb_insere(abb, 5);
    abb = abb_insere(abb, 12);
    abb = abb_insere(abb, 14);
    abb = abb_insere(abb, 23);
   
    print2DTree(abb, 0);

    nFilhos = um_filho(abb);
    nIntermediario = intermediarios(abb);

    printf("\n Apenas 1 filho: %d", nFilhos);
    printf("\n Nos que nao sao folhas: %d", nIntermediario);

  return 0;
 
}