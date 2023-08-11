#include <stdio.h>
#include <stdlib.h>
int pop = 0;

typedef struct no {
	int caixas[1001];
	struct no *prox;
    struct no *ant;
    int containdice;
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

void inserir(fila *f, int quantidade)
{
    int c,x;
	no *novo = (no *) malloc(sizeof(no));
    for (c = 0; c < quantidade;c++){
        scanf("%d",&x);
        novo->caixas[c] = x;
    }
    novo->containdice = quantidade;
	novo->prox = NULL;
    novo->ant = NULL;
		
	if(f->ini == NULL){
        f->ini = novo;
        f->fim = novo;
    }
    else {
        novo->ant = f->fim;
        f->fim->prox = novo;
        f->fim = novo;
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

void caminho (no *aux,int i){
no *aux2 = aux->ant, *aux3 = aux->prox;
int j,popesquerda = 0, popdireita = 0;
//ESQUERDA
while (aux2 != NULL){
    for(j = aux2->containdice; j > i; j--){
        popesquerda++;
    }
    aux2 = aux2->ant;
}
    popesquerda = popesquerda + (aux->containdice - (i+1));
    //DIREITA
    while(aux3 != NULL){
        for(j = aux3->containdice; j > i; j--){
        popdireita++;
    }
    aux3 = aux3->prox;
    }
    popdireita = popdireita + (aux->containdice - (i+1));

    if (popdireita <= popesquerda){
        pop = popdireita;
    }
    else{
        pop = popesquerda;
    }
}

int inventario (fila *f){
no *aux = f->ini;
int i;
while (aux != NULL){
    for(i=aux->containdice; i >= 0; i--){
        if(aux->caixas[i] == 1){ //achou o invetario comeca a brincadeira
            if(i+1 == aux->containdice){ // se a caixa ta no topo de alguma pilha
            if(aux->prox->containdice >= aux->containdice && aux->ant->containdice >= aux->containdice){ // caso o invetario esteja no topo mas nao da pra retirar 
            caminho(aux,i);
            } 
            else {
                pop = 0;
            }
            }
            else {
                if(aux->prox == NULL || aux->ant == NULL){ // se a pilha tiver em um canto nao precisa desempilhar
                    pop = aux->containdice - (i+1);
                }
                else { // se ta no meio
                    if (i == 0){  // se o 1 tiver na base da pilha
                    caminho(aux,i);
                    }
                    else {
                        caminho(aux,i);   
                    }
                }
            }
        }
    }
    aux = aux->prox;
}
return 1;
}

int main (){
    fila f;
    criar(&f);

    int i,caixa,pilha,quantidade;

        do{
        scanf("%d",&caixa);
        scanf("%d",&pilha);
        if(caixa == 0 && pilha == 0){
            continue;
        }
        for (i=0;i<pilha;i++){
            scanf("%d",&quantidade);
            inserir(&f,quantidade);
        }
        inventario(&f);
        printf("%d\n",pop);
        pop = 0;
        esvaziar(&f); 
        }
        while (caixa != 0 && pilha != 0);
        return 0;
}
