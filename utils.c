#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"
#include <string.h>


// Leitura do ficheiro de input
// Par�metros de entrada: Nome do ficheiro, nome, N�mero de v�rtices, n, N�mero de itera��es, iter
// Par�metros de sa�da: Matriz de adjac�ncias, p
int* init_dados(char *nome, int *n){
  FILE    *f;
  int     *p;
  int     i, j, lig, lin, col;
  char    str[100];
  f=fopen(nome, "r");
  if(!f){
    printf("Erro no acesso ao ficheiro dos dados\n");
    exit(1);
  }
  while(strcmp(str,"edge")){
    fscanf(f,"%s",str);
  }
    // Numero de vertices
    fscanf(f, "%d", n);
    // Numero de liga��es
    fscanf(f, "%d", &lig);
    // Alocacao dinamica da matriz
    p = malloc(sizeof(int)*(*n)*(*n));
    if(!p){
      printf("Erro na alocacao de memoria\n");
      exit(1);
    }
    // Preenchimento da matriz
    for(i=0; i<*n; i++)
      for(j=0; j<*n; j++)
        *(p+(*n)*i+j)=0;
          for(i=0; i<lig; i++)
          {
            fscanf(f, " e %d %d", &lin, &col);
            *(p+(*n)*(lin-1)+col-1)=1;
            *(p+(*n)*(col-1)+lin-1)=1;
          }
  fclose(f);
  return p;
}


int flip(){ // TIAGO - SERVE PARA A 1 FICHA depois do gera solu��o
	if ((rand() % 100) < 50)
		return 0;
	else
		return 1;
}

// Gera a solu��o inicial
// Par�metros de entrada: Solu��o, sol, N�mero de vertices, v
void gera_sol_inicial(int *sol, int v){
	int i;

	for (i = 0; i < v; i++)
        sol[i] = 0;


   // dentro gera solu��o

    for(i=0; i < v; i++)
    sol[i] = flip();

}

// Escreve solu��o no ecr�
// Par�metros de entrada: Solu��o, sol, N�mero de vertices, vert
void escreve_sol(int *sol, int vert){
	int i;
	printf("\nConjunto A: ");
	for (i = 0; i < vert; i++)
		printf("%2d  ", sol[i]);
  }

// copia vector b para a (tamanho n)
// Par�metros de entrada: Solu��o que ser� substitu�da, a, Solu��o que ir� substituir, b, N�mero de vertices, n
void substitui(int a[], int b[], int n){
    int i;
    for (i = 0; i < n; i++)
      a[i] = b[i];
    }

// Inicializa o gerador de n�meros aleat�rios
void init_rand(){
	srand((unsigned)time(NULL));
}

// Gera um valor inteiro aleat�rio entre min e max
// Par�metros de entrada: Valor inferior do intervalo, min, Valor superior do intervalo, max
// Par�metros de sa�da: Valor aleat�rio entre min e max
int random_l_h(int min, int max){
	return min + rand() % (max - min + 1);
}

// Gera um valor inteiro aleat�rio entre 0 e 1
// Par�metros de sa�da: Valor aleat�rio entre 0 e 1
float rand_01(){
	return ((float)rand()) / RAND_MAX;
}

void imprime_matriz(int *grafo, int vert){
  for (int i = 0; i < vert; i++) {
        printf("\n");
        for (int j = 0; j < vert; j++) {
                    printf("%d\t", grafo[i*vert+j]);
        }
    }
}
