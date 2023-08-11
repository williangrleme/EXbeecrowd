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

int saiu(fila *f,int c)
{
	no *aux1, *aux2;
	if (vazia(f)){
		return 0;
	}
    else {
        aux1 = f->ini;
        while ((aux1 != f->fim) && (aux1->dado != c)){
            aux2 = aux1;
            aux1 = aux1->prox;
        }
        if (aux1->dado == c){
            if (aux1 == f->ini){
                f->ini = aux1->prox;
                if (f->ini == NULL)
                f->fim = NULL;
                free(aux1);
            } 
            else{
				if (aux1 == f->fim){
					aux2->prox = NULL;
					f->fim = aux2;
					free(aux1);
				}
				else if ((aux1 != f->ini) && (aux1 != f->fim)){
					aux2->prox = aux1->prox;
					free(aux1);
				}
			}
        }
    }

	return 1;
}

int imprimir(fila *f)
{
	no *aux;
	if (vazia(f)){
		return 0;
	} else {
		aux = f->ini;
		while(aux!=NULL){
			if (aux->prox == NULL){  // VIADAGEM DO URI
				printf ("%d", aux->dado);
			}
			else {
				printf ("%d ",aux->dado);
			}
			aux = aux->prox;
	}
	}
	printf ("\n");
	return 1;
}


int main (){
    fila f;
    criar(&f);
    int c,i=0,y;
    int q,x=0,p;

    scanf ("%d", &c);
    while (i != c){
        scanf("%d", &y);
        inserir(&f,y);
        i++;
    }
    scanf("%d",&q);
    while (x != q){
		scanf ("%d", &p);
		saiu(&f,p);
		x++;
    }
	imprimir (&f);

	return 0;
}


