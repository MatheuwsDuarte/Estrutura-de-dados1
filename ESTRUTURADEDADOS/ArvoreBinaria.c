#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

//
// Struct Binary Tree
//
typedef struct node {
  int data;
  struct node *esq;
  struct node *dir;
} Node;

// Gera um novo nó folha
Node *newNode(int info) {
  Node *novo = (Node *)malloc(sizeof(Node));
  novo->data = info;
  novo->esq = NULL;
  novo->dir = NULL;
  return novo;
}

// Imprime formatado
void print2DTree(Node *root, int space) {
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
  printf("%d\n", root->data);

  // Avalia o nó esquerda
  print2DTree(root->esq, space);
}

// Desenvolver as funções recursivas:
/*
 * void imprime_Pre(Node* Arv);
 * void imprime_Ord(Node* Arv);
 * void imprime_Pos(Node* Arv);
 * int contNos(Node* Arv);
 */

// Pós-Ordem
void printPostorder(Node *node) {
  if (node == NULL)
    return;

  printPostorder(node->esq);
  printPostorder(node->dir);
  printf("%d ", node->data);
}

// In-Ordem
void printInorder(Node *node) {
  if (node == NULL)
    return;

  printInorder(node->esq);
  printf("%d ", node->data);
  printInorder(node->dir);
}

// Pré-Ordem
void printPreorder(Node *node) {
  if (node == NULL)
    return;

  printf("%d ", node->data);
  printPreorder(node->esq);
  printPreorder(node->dir);
}

int contNos(Node* Arv){
  int cont=0;
  if(Arv == NULL){
     return 0;
    }else{
      cont += contNos(Arv->esq);
      cont += contNos(Arv->dir);
      return ++cont;    
    }  
}
//Atividade:
//Retorna o maior No da Arv
int maiorNo(Node* Arv){

  int esq = 0;
  int dir = 0;

  if(Arv == NULL){
      return 0;
  }else{

      esq = maiorNo(Arv->esq);
      dir = maiorNo(Arv->dir);

        if(esq>dir && esq > Arv->data){
          
          return esq;

        }
          else if(dir>esq && dir > Arv->data){
            return dir;
          }
          else
            return Arv->data;
  }
}

int contFolha(Node *Arv){

  int cont = 0;

  if(Arv == NULL){

      return 0;    
      
  }
  if(Arv->esq == NULL && Arv->dir == NULL){

    return 1;
    
  }else{

      cont += contNos(Arv->esq);
      cont += contNos(Arv->dir); 
      return cont;
  }
}

void ArvoreBusca(Node *Arv, int info){



   if(Arv == NULL){

      return 0;    
      
  }
  else{
    
    if(Arv->data = info){



    }else if(Arv->data < info){

      ArvoreBusca(node->esq);

    }else if(Arv->data < info){

      ArvoreBusca(node->dir);

    }


  
    printf("%d ", node->data);
    printPreorder(node->esq);
    printPreorder(node->dir);

  }



}

int main() {
  Node *Arv = newNode(1);
  Arv->esq = newNode(2);
  Arv->esq->esq = newNode(5);
  Arv->esq->dir = newNode(7);
  Arv->dir = newNode(3);

  print2DTree(Arv, 0);

  printf("Em ordem\n");
  printInorder(Arv);
  printf("\nPós ordem\n");
  printPostorder(Arv);
  printf("\nPré ordem\n");
  printPreorder(Arv);
  printf("\nTotal Nos: %d\n", contNos(Arv));
  printf("\nMaior no: %d\n", maiorNo(Arv));
  printf("\nTotal Folhas: %d\n", contFolha(Arv));
 
  return (0);
}