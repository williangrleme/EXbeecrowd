#include<stdio.h>
#include<stdlib.h>

// com numeros muito grande ele simplesmente nao funciona
// o cont tambem funciona de formal anormal

void insert(int x , int v[x]){
    int i, j, aux;
  for(i = 1; i < x; i++)
 {
  aux = v[i];
  for(j = i-1; j >= 0 && aux < v[j]; j--)
  {
   v[j+1] = v[j];
  }
  v[j+1] = aux;
 }
}


void encontrar(int vet[],int tamanho,int numero){
    
    int x = -1,y = -1,i,j=0;

    for(i=0; i < tamanho;i++){  // se der time limit muda isso (muda o if pra dar break quando !=)
        if(vet[i] == numero){
            if (x == -1){
                x = i;
            }
            else {
                y = i;
            }
        }   
        else {
            if(x != -1){
                break;   // pra nao andar o vetor inteiro mesmo ja encontrado o que queria
            }
        }
    }
    if (x == -1){
        printf ("%d not found\n",numero);
    }
    else {
        if(y == -1){
            y = x;
        }
        printf ("%d found from %d to %d\n",numero,x,y);
    }
}

int main (){
    int n,inicio,fim,cont,i,cont2=0,numero;
    int vet[100];

    scanf("%d",&n);
    do{
        for (cont = 0; cont <= n; cont++){
            scanf ("%d %d", &inicio, &fim);
            for (i = inicio; i <= fim; i++){
                vet[cont2]= i;
                cont2++;
            }
        }
        scanf("%d",&numero);
        insert(cont2,vet);
        encontrar(vet,cont2,numero);
        cont2 = 0;
        scanf("%d",&n);
    }
    while(n != EOF);
    return 0;
}