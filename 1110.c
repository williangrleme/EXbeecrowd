#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int dado;
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

int inserir(fila *f, int c)
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

int remover(fila *f)
{
	no *aux;
	int c;
	if (vazia(f)){
	return 0;
	}
	
	aux = f->ini;
	c = aux->dado;
	f->ini = aux->prox;
	if (f->ini == NULL)
		f->fim = NULL;
	free(aux);
	return c;
}

void esvaziar(fila *f)
{
	while (f->ini != NULL){
		remover(f);
	}
}

void organizar (fila *f1, fila *f2){
	int x,c;
	printf ("Discarded cards:");
	while (f1->ini->prox != NULL){
		x = remover(f1);
		inserir(f2,x);
		c = remover(f1);
		inserir(f1,c);
		printf (" %d",f2->fim->dado);
		if(f1->ini->prox != NULL){
			printf(",");
		}
	}
	printf ("\nRemaining card:");
	printf (" %d\n",f1->fim->dado);
}

int main () {
            
    int n,i;
	fila f1, f2;
    criar(&f1);
	criar(&f2);
    while(scanf("%d",&n) != EOF){
        if(n == 0 || n >50){
            return 0;
        }
        for(i=1; i<=n; i++){
            inserir(&f1,i);
        }
        organizar(&f1,&f2);
		esvaziar(&f1);
		esvaziar(&f2);
		i = 0;
    }           
    return 0;
}


