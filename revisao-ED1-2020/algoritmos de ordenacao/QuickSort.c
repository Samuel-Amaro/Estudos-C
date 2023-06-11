/*
 *ALGORITMO DE ORDENAÇÃO QUICK SORT

 *QUICK SORT == ORDENAÇÃO POR TROCA DE PARTIÇÕES

 * IDEIA BASICA: dividir e conquistar.
 * Um elemento e escolhido como pivô.
 * Particionar: com o pivo ja escolhido os dados são rearranjandos(valores menores do que o pivo são colocados antes dele e os maiores, depois)
   vai ter o pivo no meio elementos menores que um pivo de um lado, maiores que o pivo de outro lado.
 * recursivamente ordena as duas partições, as maiores que o pivo, e menores que o pivo.
 * não altera a ordem de dados iguais no vetor.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//costante de tamanho 4
const int TAMANHO = 4;

//FUNÇÃO QUE FAZ A TROCA DE VALORES ENTRE DUAS VARIAVEIS
void troca(int *a,int *b);
//função que faz a ordenção pelo metodo QuikSort
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

//implementação da troca de variaveis
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
 if(inicio < fim) { //condição de parada para a chamada recursiva da função
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
