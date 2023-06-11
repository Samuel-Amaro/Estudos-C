/*
 *ALGORITMO DE ORDENA��O MERGE SORT.
  * � preciso revolver um problema com uma entrada
   grande
  � Para facilitar a resolu��o do problema, a entrada �
   quebrada em peda�os menores (DIVIS�O)
  � Cada peda�o da entrada � ent�o tratado separadamente
   (CONQUISTA)
  � Ao final, os resultados parciais s�o combinados para
   gerar o resultado final procurado
 * A t�cnica de divis�o e conquista consiste de 3 passos:
  � Divis�o: Dividir o problema original em subproblemas menores
  � Conquista: Resolver cada subproblema recursivamente
  � Combina��o: Combinar as solu��es encontradas, compondo uma solu��o para o problema original
  * MergeSort sempre divide o problema de forma balanceada (gerando subproblemas de mesmo tamanho).
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 4

//fun��o que mostra o conjunto de valores
void getValores(int vetor[]);

void merge(int conjunto_valores[],int inicio,int meio,int fim);

void mergeSort(int conjuntoValores[],int inicio,int fim);

void main() {
 //vetor onde vai estar armazenado o conjunto de valores que vai ser ordenado
 int conjunto_valores[TAMANHO];
 //variaveis guarda tempo de execuca��o do algoritmo
 clock_t tempoInicial,tempoFinal;
 srand(time(NULL));
 //inicia contegem do tempo
 tempoInicial = clock();
 //atribuindo valores aleatorios ao conjunto de valores
 for(int i = 0; i < TAMANHO; i += 1)
     conjunto_valores[i] = rand() % 100 + 1;
 getValores(conjunto_valores);
 mergeSort(conjunto_valores,0,TAMANHO - 1);
 //mostra vetor ordenado
 getValores(conjunto_valores);
 tempoFinal = clock();//finaliza contagem do tempo
 //calcula e mostra o tempo total execu��o
 printf("Tempo: %fs \n",(double) (tempoFinal - tempoInicial) / CLOCKS_PER_SEC);
 }

//fun��o que mostra o conjunto de valores
void getValores(int vetor[]) {
 printf("\t\t\t\tVALORES\n");
 printf("--------------------------------------------------------------------------\n");
 for(int i = 0; i < TAMANHO; i += 1)
     printf("%d\t",vetor[i]);
 printf("\n--------------------------------------------------------------------------\n");
}

void merge(int conjunto_valores[],int inicio,int meio,int fim) {
 int i,j,k;
 int n1 = meio - inicio + 1;
 int n2 = fim - meio;
 int vetorEsquerda[n1],vetorDireita[n2];
 for(i = 0; i < n1; i += 1)
     vetorEsquerda[i] = conjunto_valores[inicio + 1];
 for(j = 0; j < n2; j += 1)
     vetorDireita[j] = conjunto_valores[meio + 1 + j];
 i = 0,j = 0, k = 0;
 while(i < n1 && j < n2) {
       if(vetorEsquerda[i] <= vetorDireita[j]) {
          conjunto_valores[k] = vetorEsquerda[i];
          i++;
       }else{//troca
            conjunto_valores[k] = vetorDireita[j];
            j++;
       }
       k += 1;
 }
 while(i < n1) {
      conjunto_valores[k] = vetorEsquerda[i];
      i++;
      k++;
 }
 while(j < n2) {
      conjunto_valores[k] = vetorDireita[j];
      j++;
      k++;
 }

}

void mergeSort(int conjuntoValores[],int inicio,int fim) {
 if(inicio < fim) {
    int m = inicio + (fim - inicio) / 2;
    mergeSort(conjuntoValores,inicio,m);
    mergeSort(conjuntoValores,m + 1, fim);
    merge(conjuntoValores,inicio,m,fim);
 }
}
