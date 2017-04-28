#include <stdio.h>
#include <stdlib.h>

typedef struct nodos{
	int valor;
	char signo;
	struct nodos *sig;
	} _nodo ;

_nodo *ini=NULL, * fin=NULL;

void alta(_nodo* );
void imprime();

void alta(_nodo *valor){
	//printf("%p\n", valor);
	_nodo *nuevo;
	nuevo=(_nodo*)malloc(sizeof(_nodo));
	if(nuevo!=NULL){
		*nuevo=*valor;
		if(ini==NULL && fin==NULL)
		{
			ini=nuevo;
			fin=nuevo;
			}else{
				fin->sig=nuevo;
				fin=nuevo;
				
				}
			
		}
	
	
	}


void imprime(){
	_nodo *aux = ini;
	while(aux!=NULL){
		printf("|%d|->",aux->valor);
		aux=aux->sig;
		}
		
	}


int main(){
	int op; 
	_nodo  aux;
	aux.valor=0;
	aux.signo=' ';
	aux.sig=NULL;
	
	do{
	printf("1.- Valores\n");
	printf("2.- Imprimir\n");
	scanf("%d", &op);
	switch(op){
		case 1:
		printf("Dame un valor entero\n");
		scanf("%d", &aux.valor);
		alta(&aux);
		break;
		case 2:
		printf("Imprimir\n");
		imprime();
		break;
		case 3:
		exit(0);
		default:
		printf("otro valor");
		
		}
	}while(op!=3);
	return 0;
	}
