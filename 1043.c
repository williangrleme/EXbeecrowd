#include <stdio.h>


int main(){

    double x,y,z;
    scanf("%lf %lf %lf",&x,&y,&z);
    if(x+y > z){
        if(y+z > x){
            if(x+z > y){
                printf("Perimetro = %.1lf\n",x+y+z);
            }
            else {
                printf("Area = %.1lf\n", z * (x+y)/2);
            }
        }
        else{
            printf("Area = %.1lf\n", z * (x+y)/2);
        }
    }
    else{
        printf("Area = %.1lf\n", z * (x+y)/2);
    }
    return 0;
}