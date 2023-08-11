#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
    char risada[51];
    int x,i,y=0;
    scanf (" %s",risada);
    x = strlen(risada);
    char aux[x+1];

    for (i=0; i < x;i++){
        if (risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u'){
            aux[y++] = risada[i];
        }
    }
    aux[y] = '\0';
    x = strlen(aux);
    char aux2[x+1];
    y = x-1; 
    for (i=0; i < x;i++){
        aux2[i] = aux[y--];
    }
    aux2[i] = '\0';
    if (strcmp (aux,aux2) == 0){
        printf("S\n");
    }
    else {
        printf("N\n");
    }
    return 0;
}