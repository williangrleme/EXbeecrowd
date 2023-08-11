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
		
		if(f->ini == NULL) {f->ini = novo; f->fim = novo;}

		else {
		f->fim->prox = novo;
		f->fim = novo;
		}
		return 1;
	}

	void imprimir (fila *f){
		no *aux = f->ini;
		while(aux != NULL){
			printf("%c",aux->dado);
			aux = aux->prox;
		}
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

	int peso (char c) {
		
	switch (c) {

	case '^':
	return 3;

	case '*':
	return 2;

	case '/':
	return 2;

	case '+':
	return 1;

	case '-':
	return 1;

	default:
	return 0;

	}
	}

	void infixaposfixa (fila *f, fila *f2){
		no *aux;
		char p[1000];
		int t = -1;
		for (aux = f->ini; aux != NULL;aux = aux->prox){
			if(aux->dado == ' ') continue;
			if(aux->dado == '('){
				p[++t] = aux->dado;
			}
			else if (aux->dado == ')'){
				while(t > -1 && p[t] != '('){
					inserir(f2,p[t--]);
				}
				t--;	
			}
			else if ((aux->dado >= '0' && aux->dado <= '9') || (aux->dado >= 'a' && aux->dado <= 'z') || (aux->dado >= 'A' && aux->dado <= 'Z')){
				inserir(f2,aux->dado);
			}
			else {

				while(t > -1 && p[t] != '(' && peso(p[t]) >= peso(aux->dado)){
					inserir(f2,p[t--]);
				}
				p[++t] = aux->dado;
			}
		}

		while (t > -1){inserir(f2,p[t--]);
		}
		imprimir(f2);
	}

	int main (){
		fila f;
		fila f2;

		criar(&f);
		criar(&f2);

		char c;
		int i, cont;

		scanf("%d",&cont);
		fflush(stdin);
		for (i=0; i < cont; i++){
			do {
				scanf("%c",&c);
				inserir(&f,c);
			}
			while (c != '\n');
			infixaposfixa(&f,&f2);
			esvaziar(&f);
			esvaziar(&f2);
		}
	}

