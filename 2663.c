#include <stdio.h>

int insert(int x , int v[x]){
    int i, j, aux;
  for(i = 1; i < x; i++)
 {
  aux = v[i];
  for(j = i-1; j >= 0 && aux > v[j]; j--)
  {
   v[j+1] = v[j];
  }
  v[j+1] = aux;
 }
}

int main (){
    int x,min,i,result;
    scanf("%d",&x);
    scanf("%d",&min);
    int vet[x];
    for(i=0;i<x;i++){
        scanf("%d",&vet[i]);
    }
    insert(x,vet);
    i = min-1;
    result = min;

    while(i  < x){
        if(vet[i] == vet[i+1]){
            i++;
            result++;
        }
        else{
            break;
        }
    }
    printf("%d\n",result);
 
    return 0;
}