#include <stdio.h>
#include <stdlib.h>

typedef struct no_fila {
	int dado;
	struct no_fila *prox;
}no_fila;

typedef struct no_pilha {
	int dado;
	struct no_pilha *proximo;	
}no_pilha;

typedef struct no_prioridade{
    int dado;
    struct no_prioridade *proximo;
}no_prioridade;

typedef	struct {
	no_fila *ini;
	no_fila *fim;
}fila;

 typedef struct {
 	no_pilha *topo;
 }pilha;

 typedef struct{
     no_prioridade *ini;
     no_prioridade *fim;
 }filap;
 
void criar_fila(fila *f)
{
	f->ini = NULL;
	f->fim = NULL;
}

void criar_pilha (pilha *p)
{
    p->topo = NULL;
}

void criar_fila_prioridade (filap *f){
    f->ini = NULL;
    f->fim = NULL;
}

int inserir_fila(int c,fila *f)
{
	no_fila *novo = (no_fila *) malloc(sizeof(no_fila));
	novo->dado = c; 
	novo->prox = NULL;
	
	if(!novo) return 0;
	
	if(f->ini == NULL) f->ini = novo;
	else f->fim->prox = novo;
	f->fim = novo;
	return 1;

}

void push (int c,pilha *p){
	no_pilha *novo;
	novo=(no_pilha *)malloc(sizeof(no_pilha));
	novo->proximo=NULL;
	novo->dado=c;

	if (p->topo == NULL){
		p->topo=novo;
	}
	else {
        novo->proximo = p->topo;
        p->topo=novo;
	}
}

int inserir_prioridade (int c, filap *f){
    no_prioridade *novo = (no_prioridade *) malloc(sizeof(no_prioridade));
    novo->dado = c;
    novo->proximo = NULL;

    if(!novo) return 0;
    if(f->ini == NULL) f->ini=novo;
    else f->fim->proximo = novo;
    f->fim = novo;
    return 1;
}

int remover_fila(fila *f)
{
	no_fila *aux;
	int c;
	if (f->ini == NULL){
        return 0;
	}
	aux = f->ini;
    c = aux->dado;
	f->ini = aux->prox;
	if (f->ini == NULL) f->fim = NULL;
	free(aux);
	return c;
}

int pop (pilha *p){
	no_pilha *auxiliar;
    int c;
	
if (p->topo == NULL){
	return 0;
}
else {
	auxiliar=p->topo;
    c = auxiliar->dado;
	p->topo=auxiliar->proximo;
	free(auxiliar);
}
return c;
}

int remover_priorirdade (filap *f){
    no_prioridade *aux1, *aux2,*aux3;
	int c,maior=0;
		aux3 = f->ini;
		while (aux3 != NULL){
			if (aux3->dado > maior){
				maior = aux3->dado;
				aux3 = aux3->proximo;
			}
			else {
				aux3 = aux3->proximo;
			}
		}
		aux1 = f->ini;
		aux2 = aux1->proximo;
		while ((aux1->dado != maior) && (aux2->dado != maior)){
			aux1 = aux1->proximo;
			aux2 = aux2->proximo;
		}
		if (aux1->dado == maior){ // possibilidade de o maior ser  primeiro
			c = aux1->dado;
			f->ini = aux1->proximo;
			if (f->ini == NULL) f->fim = NULL;
			free(aux1);
		}
		else {
			if(aux2 == f->fim){ //posibilidade de o maior ser o ultimo
				c = aux2->dado;
				aux1->proximo = NULL;
				f->fim = aux1;
				free(aux2);
			}
			else {
			c = aux2->dado;
			aux1->proximo = aux2->proximo;
			free(aux2);
			}
		}
	return c;
}


void esvaziar_fila (fila *f){
	while (f->ini != NULL){
		remover_fila(f);
	}
}

void esvaziar_pilha (pilha *p){
	while (p->topo != NULL){
		pop(p);
	}
}

void esvaziar_prioridade (filap *fp){
	while (fp->ini != NULL){
		remover_priorirdade(fp);
	}
}

void imprimir (filap *fp){
	no_prioridade *aux;
	aux = fp->ini;
	if (fp->ini == NULL){
		printf ("fila vazia\n");
	}
	else {
	while (aux != NULL){
		printf ("%d  ", aux->dado);
		aux = aux->proximo;
	}
	printf("\n");
	}
}
int main (){

	fila f;
	filap fp; 	
	pilha p;

	criar_fila(&f);
	criar_fila_prioridade(&fp);
	criar_pilha(&p);	

	
	int c,cont,op,n,rp,rfp,rf;
	while(scanf("%d", &c) != EOF){
		rf = 1;
		rp = 1;
		rfp = 1;  
		for (cont=0; cont<c; cont++){
			scanf ("%d  %d", &op, &n);
			if (op == 1){
				push(n,&p);
				inserir_fila(n,&f);
				inserir_prioridade(n,&fp);
			}
			if (op == 2){
				if ((rp == 1) && (pop(&p) == n)){  // pilha 
					rp=1;
				}
				else {
					rp = 0;
				}
				if((rf == 1) && (remover_fila(&f) == n)){ // fila
					rf = 1;
				}
				else{
					rf = 0;
				}
				if ((rfp == 1) && (remover_priorirdade(&fp) == n)){ // fila com prioridade
					rfp = 1;
				}
				else {
					rfp = 0;
				}
			}
		}
		if ((rp == 1) && (rf == 0) && (rfp == 0)){
			printf("stack\n");
		}
		else {
			if ((rf == 1) && (rp == 0) && (rfp == 0)){
				printf("queue\n");
			}
			else {
				if ((rfp == 1) && (rf == 0) && (rp == 0)){
					printf("priority queue\n");
				}
				else {
					if ((rfp == 0) && (rf == 0) && (rp == 0)){
						printf("impossible\n");
					}
					else {
						printf ("not sure\n");
					}
				}
			}	
		}
		esvaziar_fila(&f);
		esvaziar_pilha(&p);
		esvaziar_prioridade(&fp);
}
return 0;
}