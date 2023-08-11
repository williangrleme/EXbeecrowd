#include <stdio.h>
#include <stdlib.h>

int main (){
int N, M, i=0, g=0;
	
	 scanf ("%d %d", &N, &M);
	 	
int X[N];
	 while (i<N){
	 	scanf ("%d", &X[i]);
	 	i++;
	 }
	 
i=0;
	while (i<N){
		g = g + abs(M-X[i]);
		if (X[i] == X[i+1]) { i++;}
		else { X[i+1] = X[i+1] + (M-X[i]);}
		i++;
	}

	printf ("%d\n", g);
}
