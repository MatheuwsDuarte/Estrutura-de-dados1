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

Arv* verificar(Arv *a){

    if (a!=NULL) {

        if((a->esq != null) && (a->dir != null)){
        
            if((a->esq->info > a->info) && (a->dir->info < a->info)){

                if (a->esq->info < a->dir->info)
                {
                    verificar(a->esq);
                    verificar(a->dir);

                }else{
                    
                    

                }



            }else{



            }

        }

    }

    return a;
}

int main(){

  Arv* abb;
  int soma=0;

    abb = abb_cria();
    abb = abb_insere(abb, 15);
    abb = abb_insere(abb, 10);
    abb = abb_insere(abb, 22);
    abb = abb_insere(abb, 5);
    abb = abb_insere(abb, 12);
    abb = abb_insere(abb, 14);
    abb = abb_insere(abb, 23);

    print2DTree(abb, 0);


     return 0;
}