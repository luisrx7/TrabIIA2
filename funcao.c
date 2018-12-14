#include "funcao.h"

// Calcula a qualidade de uma solu��o
// Par�metros de entrada: Solu��o actual, a, Matriz de adjac�ncias, mat, N�mero de v�rtices, vert
// Par�metros de sa�da: Custo, total -
int calcula_fit(int a[], int *mat, int vert){
	int total = 0;
	int i, j;
	int zeros=0;

	for (i = 0; i < vert; i++){
		if (a[i] == 0)
		{
			for (j = 0; j < vert; j++)
				if (a[j] == 0 && *(mat+i*vert+j) == 1)
			    total++; //total é o numero de ligaçoes entre os membros dos grupos de 0's
		}
	}
		if(total == 0){
			//conta os zeros
			//ciclo for para contar os zeros
			for(i=0;i<vert;i++){
				if(a[i] == 0){
					zeros++;
				}
			}
			return zeros;//numero de zeros;
		}
		else{
			return -total;
		}
}
