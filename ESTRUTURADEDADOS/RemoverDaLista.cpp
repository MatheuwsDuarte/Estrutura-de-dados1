Lista* removeLista(Lista* L, int val){
  Lista* aux = L;
  Lista* ant = NULL;

  //Testa lista vazia
  if(L==NULL)
      return L;

  //Buscar o valor desejado
  L->10->20->30->40->NULL
  //Usuario: 50
  while(aux != NULL && aux->valor != val){
    ant = aux;
    aux = aux->prox;
  }

  //Teste se elemento esta na lista
  if(aux == NULL)
    //Devolve a lista original
    return L;
  else if(ant==NULL){ //Primeira posicao
    L = aux->prox;
    free(aux);
    return L;
  }else{//A partir da segunda posicao
    ant->prox = aux->prox;
    free(aux);
    return L;
  }  
}