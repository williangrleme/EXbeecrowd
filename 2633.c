#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
	int data;
    char nome[20];
	struct no *prox;
}no;

typedef	struct {
	no *ini;
	no *fim;
}fila;

void criar(fila *f)
{
	f->ini = NULL;
	f->fim = NULL;
}

int vazia(fila *f)
{
	if(f->ini == NULL)
	return 1;
	else return 0;
}

void inserir(fila *f, int c, char nome[20])
{
	no *novo = (no *) malloc(sizeof(no));
	novo->data = c; 
    strcpy(novo->nome,nome);
	novo->prox = NULL;
	
	if(f->ini == NULL) f->ini = novo;
	else f->fim->prox = novo;
	f->fim = novo;
}

void remover(fila *f)
{
	no *auxr;
	if (vazia(f)){
        exit(1);
	}
	
	auxr = f->ini;
	f->ini = auxr->prox;
	if (f->ini == NULL)
		f->fim = NULL;
	free(auxr);
}

void imprimir(fila *f)
{
	no *aux;
		aux = f->ini;
		while(aux!=NULL){
		printf ("%s",aux->nome);
		if(aux->prox != NULL){
			printf(" ");
		}
		aux = aux->prox;
	}
}

void esvaziar (fila *f){
	while (f->ini != NULL){
		remover(f);
	}
}
int ordenar (fila *f, fila *f2,fila *f3){
	no *aux;
	no *aux2;

	while ((vazia(f) == 0) || (vazia(f2) == 0)){
		aux = f->ini;
		while (aux->prox != NULL){
			if (aux->data > aux->prox->data){
				inserir(f2,aux->data,aux->nome);
				remover(f);
				aux = f->ini;
			}
			else {
				inserir(f,aux->data,aux->nome);
				remover(f);
				aux = f->ini;
			}
		}
		
		inserir (f3,aux->data,aux->nome);
		remover(f);
		if (f2->ini == NULL){
			return 0;
		}
		else{
			aux2 = f2->ini;
		while (aux2->prox != NULL){
			if (aux2->data > aux2->prox->data){
				inserir (f,aux2->data,aux2->nome);
				aux2 = aux2->prox;
				remover(f2);
			}
			else {
				inserir(f2,aux2->data,aux2->nome);
				aux2 = aux2->prox;
				remover(f2);
			}
		}
		inserir (f3,aux2->data,aux2->nome);
		remover(f2);
	}
	}
	return 1;
}

int main (){
    fila f;
	fila f2;
	fila f3;
    criar (&f);
	criar (&f2);
	criar (&f3);
    int x,cont=0,data;
    char nome[20];

    while(scanf ("%d " , &x)!= EOF && x<=10){
    while (cont != x){
        scanf ("%s  %d", nome, &data);
        inserir(&f,data,nome);
        cont++;
    }
	ordenar (&f,&f2,&f3);
	imprimir(&f3);
	printf("\n");
	esvaziar(&f);
	esvaziar(&f2);
	esvaziar(&f3);
	cont = 0;
	}
return 0;
}


