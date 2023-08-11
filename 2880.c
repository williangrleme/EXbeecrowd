#include <stdio.h>
#include<stdlib.h>
#include <string.h>

int main (){

    char cifrada[100000], crib [100000];
    int tcf,tcr,i,y,cont=0,possivel=0,i2;

    scanf("%s",cifrada);
    scanf("%s",crib);
    tcf = strlen(cifrada);
    tcr = strlen(crib);
        
    for(i=0; i < tcf; i++){
        i2 = i;
        if ((tcf - i) >= tcr){
        for(y=0; y < tcr;y++){
            if (crib[y] == cifrada[i2]){
                cont = 0;
                break;
            }
            else {
                i2++;
                cont++;
            }
        }
        if(cont == tcr){
            possivel++;
            cont = 0;
        }
        else {
            cont = 0;
        }
    }
    else {
        break;
    }
    }
    printf("%d\n",possivel);
    return 0;
}