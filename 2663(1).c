#include<stdio.h>


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
 return 1;
}

int main (){
    int nc,vagas,i;
    scanf ("%d",&nc);
    int p[nc];
    scanf("%d",&vagas);

    for (i=0;i<nc;i++){
        scanf("%d",&p[i]);
    }
    insert(nc,p);

    for(i=0;i<nc;i++){
        if(p[vagas] != p[vagas-1]){
            break;
        }
        else {
            vagas++;
        }
    }
    printf("%d\n",vagas);


    return 0;
}