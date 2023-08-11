#include <stdio.h>

int main (){
    int a1,a2,a3,result1,result2,result3;
    scanf("%d",&a1);
    scanf("%d",&a2);
    scanf("%d",&a3);

    result1 = (a2*2) + (a3*4);
    result2 = (a1*2) + (a3*2);
    result3 = (a1*4) + (a2*2);

    if(result1 <=  result2){
        if(result1 <= result3){
            printf("%d\n",result1);
        }
        else{
            printf("%d\n",result3);
        }
    }
    else{
        if(result2 <= result3){
            printf("%d\n",result2);
        }
        else{
            printf("%d\n",result3);
        }
    }
    return 0;
}