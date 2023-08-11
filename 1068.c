#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	char dado;
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

int inserir(fila *f, char c)
{
	no *novo = (no *) malloc(sizeof(no));
	novo->dado = c; 
	novo->prox = NULL;
	
	if(!novo) return 0;
	
	if(f->ini == NULL) f->ini = novo;
	else f->fim->prox = novo;
	f->fim = novo;
	return 1;

}

void esvaziar(fila *f)
{
	no *x = f->ini, *aux;
	while (x != NULL){
        aux = x;
        x = x->prox;
        free(aux);
	}
    f->ini = NULL;
}

void parenteses (fila *f){
	no *aux = f->ini;
	int abre = 0, fecha = 0;
	int soma = 1;
	while (aux != NULL){
		if(aux->dado == 40){
			abre++;
		}
		else if (aux->dado == 41){
			fecha++;
		}
		if (fecha > abre){
			soma = 0;
		}
		aux = aux->prox;
	}
	if (fecha == abre && soma){
		printf("correct\n");
	}
	else {
		printf("incorrect\n");
	}
}

int main (){
    fila f;
    criar(&f);
    char c;
	
	while(scanf("%c",&c) != EOF){
		if(c == '\n'){
			parenteses(&f);
			esvaziar(&f);
			}
		inserir(&f,c);
	}
    return 0;
}
