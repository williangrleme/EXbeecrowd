#include <stdio.h>
#include<stdlib.h>

typedef struct no {
	char dado;
	struct no *proximo;	
}no;

 typedef struct {
 	no *topo;
 }pilha;
 
 void criar (pilha *p){
 	p->topo=NULL;
 } 

void push (char c,pilha *p){
	no *novo;
	
	novo=(no *)malloc(sizeof(no));
	novo->proximo=NULL;
	novo->dado=c;
	
	
	if (p->topo == NULL){
		p->topo=novo; // caso o topo esteja vazio o novo é o topo
	}
	else {
        novo->proximo = p->topo;
        p->topo=novo;
	}
}

int imprimir (pilha *p){
	no *aux = p->topo;
	if (p->topo == NULL){
		return 0;
	}
	else {
	    while (aux != NULL){
			printf ("%c", aux->dado);
			aux=aux->proximo;
		}
	}
	printf("\n");
	return 1;	
}

void pop (pilha *p){
	no *aux;
	aux=p->topo;
	p->topo=aux->proximo;
	free(aux);
}

void esvaziar (pilha *p){
	while (p->topo != NULL){
		pop(p);
	}
}

void sequencia (pilha *p,unsigned long long x){
    x = x*x;
    int i=0;
    char vet[4] = {'A','B','C','D'};
    while (x != 0){
        i = x % 4;
        push(vet[i],p);
        x = x/4;
    }
}

int main (){
    pilha p;
    criar(&p);

	unsigned long long x;
	do {
		scanf("%d",&x);
		if(x == 0){
			return 0;
		}
		sequencia(&p,x);
		imprimir(&p);
		esvaziar(&p);
	}
	while(x != 0);
	return 0;
}
