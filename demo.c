#include <stdio.h>


void cambia(int *, int *);

int main()
{
  int a=9,b=10;
  cambia(&a,&b);
  printf("%d %d\n", a,b);
  
  return 0;
}


void cambia(int *a, int *b) {
  int aux=0;
  aux=*a;
  *a=*b;
  *b=aux;
}
