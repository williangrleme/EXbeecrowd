#include <stdio.h>
#include <stdlib.h>

int main (){
    int vet[5];
    int i, m = 0,c=0,mm,d=0;

    for(i=0;i<5;i++){
        scanf("%d", &vet[i]);
    }

    for(i=0;i<5;i++){   //achando maior
        if(vet[i] > m){
            m = vet[i];
        }
    }

    mm = vet[0];

     for(i=0;i<5;i++){   //achando menor
        if(vet[i] <= mm){
            mm = vet[i];
        }
    }
    
    for(i=0;i<5;i++){
        if(i+1 < 5){    //pra n estourar
            if(vet[i] <= vet[i+1]){
            c++;
        }
        }
        else{
            if(vet[i] == m){
                c++;
            }
        }

    }

    for(i=0;i<5;i++){  
        if(i+1 < 5){ //pra n estourar
            if(vet[i] >= vet[i+1]){
                d++;
            }
        }
        else {
            if(vet[i] == mm){
                d++;
            }
        }
    }

    if(c == 5){
        printf("C\n");
    }
    else{
        if(d==5){
            printf("D\n");
        }
        else{
            printf("N\n");
        }
    }


    return 0;
}