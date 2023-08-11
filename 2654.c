#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct candidato{
    char nome[100];
    int poder;
    int matou;
    int morreu;
}candidato;

int insertion_poder(candidato v[],int x){
    int i, j;
    candidato aux;
  for(i = 1; i < x; i++)
 {
  aux = v[i];
  for(j = i-1; j >= 0 &&  v[j].poder < aux.poder; j--)
  {
   v[j+1] = v[j];
  }
  v[j+1] = aux;
 }
}

int insertion_matou(candidato v[],int x){
    int i, j;
    candidato aux;
  for(i = 1; i < x; i++)
 {
  aux = v[i];
  for(j = i-1; j >= 0 &&  v[j].matou < aux.matou; j--)
  {
   v[j+1] = v[j];
  }
  v[j+1] = aux;
 }
}

int insertion_morreu(candidato v[],int x){
    int i, j;
    candidato aux;
  for(i = 1; i < x; i++)
 {
  aux = v[i];
  for(j = i-1; j >= 0 &&  v[j].morreu > aux.morreu; j--)
  {
   v[j+1] = v[j];
  }
  v[j+1] = aux;
 }
}

int insertion_nome(candidato v[],int x){
    int i, j;
    candidato aux;
  for(i = 1; i < x; i++)
 {
  aux = v[i];
  for(j = i-1; j >= 0 &&  strcmp(v[j].nome,aux.nome) > 0; j--)
  {
   v[j+1] = v[j];
  }
  v[j+1] = aux;
 }
}

int main (){
    int i,cont;
    candidato v[100];

    scanf("%d",&i);

    for (cont = 0; cont < i; cont++){
        scanf ( "%s %d %d %d",&v[cont].nome, &v[cont].poder, &v[cont].matou, &v[cont].morreu);
    }

    insertion_nome(v,i);
    insertion_morreu(v,i);
    insertion_matou(v,i);
    insertion_poder(v,i);

    printf ("%s\n",v[0].nome);
    return 0;
}