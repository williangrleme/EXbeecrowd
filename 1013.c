#include <stdio.h>
 
int main() {
    int x,y,z,maior=0;
    scanf("%d %d %d",&x,&y,&z);
    if(x>=maior){
        maior = x;
    }
    if(y>=maior){
        maior = y;
    }
    if(z>=maior){
        maior = z;
    }
    printf("%d eh o maior\n",maior);
    return 0;
}