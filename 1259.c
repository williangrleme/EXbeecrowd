#include <stdio.h>

void quickcrescente(int v[], int ini, int fim)  
{
    if (ini < fim)
    {
       int x;
        x = quick1(v, ini, fim);

        quickcrescente(v, ini, x - 1);  
        quickcrescente(v, x + 1, fim); 
    }
}

int quick1 (int v[], int ini, int fim)  
{  
	int aux;
    int pivo = v[fim]; 
    int i = (ini - 1), j;  
  
    for (j = ini; j <= fim - 1; j++)  
    {  
       
        if (v[j] < pivo)  
        {  
            i++; 
             	aux      = v[i];  
                v[i]     = v[j];
                v[j] = aux;
        }  
    }   
    			aux      = v[i+1];   
                v[i+1]     = v[fim];
                v[fim] = aux;
    return (i + 1);  
} 

void quickdecrescente(int v[], int ini, int fim)  
{
    if (ini < fim)
    {
       int x;
        x = quick2(v, ini, fim);

        quickdecrescente(v, ini, x - 1);  
        quickdecrescente(v, x + 1, fim); 
    }
}

int quick2 (int v[], int ini, int fim)  
{  
	int aux;
    int pivo = v[fim]; 
    int i = (ini - 1), j;  
  
    for (j = ini; j <= fim - 1; j++)  
    {  
       
        if (v[j] > pivo)  
        {  
            i++; 
             	aux      = v[i];  
                v[i]     = v[j];
                v[j] = aux;
        }  
    }   
    			aux      = v[i+1];   
                v[i+1]     = v[fim];
                v[fim] = aux;
    return (i + 1);  
} 

void divide (int x, int vet[x]){

    int aux1[x],aux2[x],cont;
    int a = 0;
    int b = 0;

    for (cont = 0; cont < x;cont++){
        if (vet[cont] % 2 == 0){
            aux1[a] = vet[cont];
            a++;
        }
        else {
            aux2[b] = vet[cont];
            b++;
        }
    }
    int ini1 = 0, fi1 = a-1;
    int ini2 = 0, fi2 = b-1;

    quickcrescente(aux1,ini1,fi1);
    quickdecrescente(aux2,ini2,fi2);
    for(cont = 0; cont < a; cont++){
        vet[cont] = aux1[cont];
    }
    for (cont = 0; cont < b;cont++){
        vet[a] = aux2[cont];
        a++; 
    }
    for (cont = 0; cont < x; cont++){
        printf("%d\n",vet[cont]);
    }
}

int main (){
    int x,cont,n;

    scanf ("%d",&x);
    int vet[x];

    for (cont=0; cont < x;cont++){
        scanf ("%d",&n);
        vet[cont] = n;
    }
    divide(x,vet);
    return 0;
}