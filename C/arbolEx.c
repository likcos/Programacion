#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
  int id;
  int cubo[3][3];
  struct nodo *der, *izq;
}_nodo;



void push(_nodo , int valor); 


int main()
{
  _nodo test;
  int i, j;
  
  for(i=0; i<3; i++ ) {
    for (j=0; j<3; j++) {
      test.cubo[i][j]=1 ;
    }
  }

  for(i=0; i<3; i++ ) {
    for (j=0; j<3; j++) {
      printf(" %d ",  test.cubo[i][j]) ;
    }
    printf("\n");
  }
  return 0;
}


void push( ptrNodoArbol *ptrRaiz, int valor )
{
  if (*ptrRaiz == NULL) {
    *ptrRaiz = (_nodo*) malloc(sizeof(_nodo));
    if (*ptrRaiz != NULL) {
      (*ptrRaiz)->dato = valor;
      (*ptrRaiz)->ptrIzq = NULL;
      (*ptrRaiz)->prtDer = NULL;
    }
    else {
      printf("no se inserto %d. No hay memoria disponible.n", valor);
    }
  }
  else {
    if (valor < (*ptrRaiz)->id) {
      push(&((*ptrRaiz)->izq), valor);
    } else if (valor > (*ptrRaiz)->id) {
      push(&((*ptrRaiz)->der), valor);
    } else {
      printf("repetido");
    }
  }
}
