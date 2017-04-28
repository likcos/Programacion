dsresrdsfdsrs#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
	int id;
	char nombre[20];
	struct nodo *sig;
	}_nodo;

_nodo *top=NULL;

void push();
void imprimir();

void push() {
	_nodo *nuevo; 
	nuevo=(_nodo*)malloc(sizeof(_nodo));
	if(nuevo!=NULL) {
		printf("Dame id \n");
		scanf("%d", &nuevo->id);
		printf("Dame Nombre ");
		scanf("%s", nuevo->nombre);
		nuevo->sig=NULL;
		if(top==NULL){
			top=nuevo;
		}else{
			nuevo->sig=top;
			top=nuevo;
			
			}
		
		
		}
	
	
	}


void imprimir(){
	_nodo *aux;
	aux=top;
	while(aux!= NULL){
		printf("|%d|%s|%p|->", aux->id, aux->nombre, aux->sig);
	aux=aux->sig;	
	}
	
	
	}

int main(){
	int op;
	do{
	printf("1.-Alta\n");
	printf("2.-Imprimir\n");
	printf("3.-Salir\n");
	scanf("%d", &op);
	switch(op){
		case 1:
		push();
		break;
		case 2:
		imprimir();
		break;
		case 3:
		exit (0);
		break;
		default:
		printf("hola mundo ");
		}

	}while(op!=3);
	return 0;
	}
