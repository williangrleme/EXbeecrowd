#include <stdio.h>
#include <stdlib.h>

typedef struct interruptor{
    int c[1001];
}interruptor;

int main (){
    int quanti,quantl,i,n,ligadas,cont,cont2,comutacao=0;;
    
    scanf(" %d  %d",&quanti,&quantl);

    int lampadas[quantl];
    interruptor it[quanti];

    for (i=0;i<=quantl;i++){  // deixando todas desligadas
        lampadas[i]=0;
    }
    scanf("%d",&ligadas);

    for(i=0;i<ligadas;i++){ //ligadas inicialmente
        scanf("%d",&n);
        lampadas[n-1] = 1; 
    }

    for(i=0;i<quanti;i++){ // associando os interruptores com as lamp
        scanf("%d",&cont);
        cont2=0;
        while(cont != 0){
            scanf("%d",&n);
            it[i].c[cont2] = n; 
            cont2++;
            cont--;
        }
        it[i].c[cont2] = '\0';
    }

        for (i=0;i < quanti;i++){  // ativando os interruptores 
            cont2 = 0;  
            cont = 0;

        for(n=0;n<quantl;n++){  
            if(lampadas[n] == 0){
                cont2++;
            }
        }
        if(cont2 == quantl){    // verificando se as lamp tao tudo apagada
            printf("%d\n",comutacao);
            break;
        }

        while(it[i].c[cont] != '\0'){   // comutando
            if(lampadas[it[i].c[cont] - 1] == 1){
                lampadas[it[i].c[cont] - 1] = 0;
            }
            else {
                lampadas[it[i].c[cont] - 1] = 1;
            }
            cont++;
        }
        comutacao++;
        }
        cont2 = 0;
         for(n=0;n<quantl;n++){  
            if(lampadas[n] == 0){
                cont2++;
            }
        }

        if (cont2 != quantl){ // segunda leva caso a primeira nao deu
        for (i=0;i < quanti;i++){   
            cont2 = 0;  
            cont = 0;

        for(n=0;n<quantl;n++){  
            if(lampadas[n] == 0){
                cont2++;
            }
        }
        if(cont2 == quantl){    
            printf("%d\n",comutacao);
            break;
        }

        while(it[i].c[cont] != '\0'){   // 
            if(lampadas[it[i].c[cont] - 1] == 1){
                lampadas[it[i].c[cont] - 1] = 0;
            }
            else {
                lampadas[it[i].c[cont] - 1] = 1;
            }
            cont++;
        }
        comutacao++;
        }
        }
        cont2 = 0;
        for(n=0;n<quantl;n++){  
            if(lampadas[n] == 0){
                cont2++;
            }
        }

        if (cont2 != quantl){
            printf ("-1\n");
        }

     
    return 0;
}