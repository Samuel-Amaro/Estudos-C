/*
 *ALGORITMO DE ORDENA��O QUICK SORT

 *QUICK SORT == ORDENA��O POR TROCA DE PARTI��ES

 * IDEIA BASICA: dividir e conquistar.
 * Um elemento e escolhido como piv�.
 * Particionar: com o pivo ja escolhido os dados s�o rearranjandos(valores menores do que o pivo s�o colocados antes dele e os maiores, depois)
   vai ter o pivo no meio elementos menores que um pivo de um lado, maiores que o pivo de outro lado.
 * recursivamente ordena as duas parti��es, as maiores que o pivo, e menores que o pivo.
 * n�o altera a ordem de dados iguais no vetor.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//costante de tamanho 4
const int TAMANHO = 4;

//FUN��O QUE FAZ A TROCA DE VALORES ENTRE DUAS VARIAVEIS
void troca(int *a,int *b);
//fun��o que faz a orden��o pelo metodo QuikSort
void QuickSort(int conjuntoValores[],int inicio,int fim);
//mostra conjunto de valores
void getValores(int conjuntoValores[]);

void main() {
 //definido o conjunto de valores vazio
 int conjuntoValores[TAMANHO];
 //inicia uma contador para gerar numeros aleatorios
 srand(time(NULL));
 int indice;
 //atribuindo valores aleatorios ao conjunto de valores
 for(indice = 0; indice < TAMANHO; indice += 1)
     conjuntoValores[indice] = rand() % 10;
 getValores(conjuntoValores);
 QuickSort(conjuntoValores,0,TAMANHO - 1);
 getValores(conjuntoValores);
}

//implementa��o da troca de variaveis
void troca(int *a,int *b) {
 int aux;
 aux = *a; //aux recebe o conteudo da varivel que (a) esta pontando
 *a = *b; //local onde esta o conteudo da variavel que a aponta recebe, o valor do conteudo da variavel que b aponta.
 *b = aux;
}

void getValores(int conjuntoValores[]) {
 int indice;
 for(indice = 0; indice < TAMANHO; indice += 1)
    printf("%d\t",conjuntoValores[indice]);
 printf("\n");
}

void QuickSort(int conjuntoValores[],int inicio,int fim) {
 int pivo,i,j;
 if(inicio < fim) { //condi��o de parada para a chamada recursiva da fun��o
     pivo = inicio;
     i = inicio;
     j = fim;
     while(i < j) {
           while(conjuntoValores[i] <= conjuntoValores[pivo] && i < fim)
                i++;
           while(conjuntoValores[j] > conjuntoValores[pivo])
                 j--;
           if(i < j)
              troca(&conjuntoValores[i],&conjuntoValores[j]);
     }
     troca(&conjuntoValores[pivo],&conjuntoValores[j]);
     QuickSort(conjuntoValores,inicio,j - 1);
     QuickSort(conjuntoValores,j + 1,fim);
 }
}
