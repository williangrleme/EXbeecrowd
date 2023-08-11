#include <stdio.h>
#include <stdlib.h>

int main (){
    int quant,i,carro,venceu=0;
    scanf ("%d",&quant);
    for (i=0;i<quant;i++){
        scanf("%d",&carro);
        if (carro == 2 || carro == 3){venceu++;}
    }
    printf("%d\n",venceu);
    return 0;
}