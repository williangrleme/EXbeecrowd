#include <stdio.h>
#include <stdlib.h>

typedef struct no {
	int vet[100000];
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

int inserir(fila *f,int coluna)
{	
	int c,x;
	no *novo = (no *) malloc(sizeof(no));
	for(c = 0; c < coluna;c++){
		scanf("%d",&x);
		novo->vet[c] = x;
	}
	novo->prox = NULL;
	
	if(!novo) return 0;
	
	if(f->ini == NULL) f->ini = novo;
	else f->fim->prox = novo;
	f->fim = novo;
	return 1;

}

int escada (fila *f,int coluna){
no *aux = f->ini, *aux2 = aux->prox;
int cont,cont2,y = 1,x = 0;

while (aux != NULL){ // enquanto n ver todas linha
	for (cont=0; cont <= coluna;cont++){
		if(aux->vet[cont] == 0){
			x++;
		}
		else {  
			if (y == 1){ // achando o elemento mais a esquerda e vericando os 0 até chegar no indice dele
				aux2 = aux->prox;
				while(aux2 != NULL){ // até acabar todas linha
					for(cont2 = 0; cont2 <= cont;cont2++){
						if(aux2->vet[cont2] != 0){	
							printf ("N\n");
							return 0;
						}
					}
					aux2 = aux2->prox;  // pula pra proxima linha
				}
				y = 0;
			}
		}
		if (x == coluna){  // se o numero de 0 for igual o numero de colunas
			while(aux2 != NULL){
				for(cont2 = 0; cont2 < x; cont2++){
					if (aux2->vet[cont2] != 0){
						printf("N\n");
						return 0;
					}
				}
				aux2 = aux2->prox;
			}
		}
	}
aux2 = aux->prox; // atualizando (pode dar segmentation aqui)
y = 1;  // pra achar o proximo elemento mais a esquerda da outra linha
aux = aux->prox; // pulando de linha
x = 0;
}
printf("S\n");
return 1;
}

int main (){
	
    fila f;
    criar(&f);

    int linha,coluna,i;
    scanf("%d",&linha);
    scanf("%d",&coluna);

    for (i=0; i < linha;i++){
		inserir(&f,coluna);
    }  
	escada(&f,coluna);
    return 0;
}



