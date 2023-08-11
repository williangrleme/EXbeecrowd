#include <stdio.h>

int main (){
    double n1,n2,n3,n4,media,exame;
    scanf("%lf %lf %lf %lf",&n1,&n2,&n3,&n4);
    media = ((n1*2) + (n2*3) + (n3*4) + n4) / 10;
    if(media >= 7.0){
        printf("Media: %0.1lf\n", media);
        printf("Aluno aprovado.\n");
    }
    else{
        if(media < 5.0){
            printf("Media: %0.1lf\n", media);
            printf("Aluno reprovado.\n");
        }
        else {
            if(media >= 5.0 && media <= 6.9){
                scanf("%lf",&exame);
                printf("Media: %0.1lf\n", media);
                printf("Aluno em exame.\n");
                printf("Nota do exame: %0.1lf\n",exame);
                media += exame;
                media = media/2;
                if(media >= 5.0){
                    printf("Aluno aprovado.\n");
                    printf("Media final: %0.1lf\n",media);
                }
                else{
                    printf("Aluno reprovado.\n");
                }
            }
        }
    }
    return 0;
}