#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct telefone{
    char numero[200];
}telefone;

int maisperto(telefone *x, telefone *y){
    int result = strcmp(x->numero,y->numero);

    if (result == 0){
        return 0;
    }
    else if (result < 0){
        return 1;
    }
    else {
        return -1;
    }
}

int main (){
    int x,cont,resposta,i,j;
    while (scanf("%d",&x) != EOF){

        resposta = 0; 
        telefone vet[x];
        for(cont=0;cont < x; cont++){
            scanf("%s",vet[cont].numero);
        }
         qsort(vet,x,sizeof(telefone),maisperto);

        for(i = 1; i < x;++i)
            for(j=0;vet[i].numero[j];++j)
            if(vet[i].numero[j] == vet[i-1].numero[j])
            ++resposta;
            else
                break;
        printf("%d\n",resposta);
    }
    return 0;
}