#include <stdio.h>
 
int main() {
    int x=0;
    int ano = 0;
    int mes = 0;
    int dia = 0;
    int aux = 0;
    
    scanf("%d",&x);
    ano = x/365;
    aux = x - (365*ano);
    mes  = aux/30;
    dia = aux % 30;
    printf("%d ano(s)\n%d mes(es)\n%d dia(s)\n",ano,mes,dia);
    return 0;
}