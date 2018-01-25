//Programa que intercambia dos números utilizando punteros 

#include <stdio.h>

void intera( int &, int &);
void interb(int *, int *);

int main() {
  int a=4, b=3;
  //intera(a, b);
  interb(&a,&b);
  printf("a=%d, b=%d ", a,b);
  return 0;
}


void intera(int &a, int &b) {
  printf("funcion %p", &a);
  int aux=0;
  aux=a;
  a=b;
  b=aux;
}


void interb(int *a, int *b) {
  int aux=0;
  aux=*a;
  *a=*b;
  *b=aux;
}
