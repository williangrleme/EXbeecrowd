#include <stdio.h>

int main (){
    double v[6];
    int i,count=0;
    for(i=0;i<6;i++){
        scanf("%lf",&v[i]);
        if(v[i] > 0){
            count++;
        }
    }
    printf("%d valores positivos\n",count);


    return 0;
}