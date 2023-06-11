/*
*algoritmo selection sort oriundo do slide ordena��o.
*ordena da seguinte maneira: escolhe o menor valor dentro do conjunto e troca ele com o valor da posi��o atual que estou num vetor
*so escolhe valores a direita, isso e na ordem de inser��o no vetor so valores a direita sa posi��o atual que estou s�o eleitos para ser menores
*assim vai ordenado ate no final aparecer uma lista ordenada crescentemente
*ilustra��o para entender melhor no slide: ordena��o que esta na pasta
*/
//n�o e do mendes e do slide

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 10

/*fun��o aux que vai ajudar a buscar e retorna o indice do menor elemento do conjunto de valores n�o ordenados*/
int getIndiceElemento(int conjuntoValores[],int tamanho,int posicaoInicial);
/*fun��o que vai fazer a ordena��o do conjunto de valores aplicando o metodo do selection sort*/
void selectionSort(int conjuntoValores[],int posicaoInicial);

void getConjuntoValores(int conjuntoValores[]); //imprime a lista de valores
//recebe endere�os de variaveis e faz a troca de valores entre elas
void troca(int *a,int *b);

void main() {
 clock_t tempoInicial, tempoFinal; //Variaveis para guardar o tempo de execucao
 srand(time(NULL)); //Cria uma semente para numeros aleatorios
 tempoInicial = clock(); //inicia contagem do tempo
 int conjuntoValores[TAMANHO] = {14,7,8,34,56,4,0,9,-8,100};
 printf("Lista de Valores N�o ordenados\n");
 getConjuntoValores(conjuntoValores);
 selectionSort(conjuntoValores,0);
 printf("Lista de Valores Ordenados\n");
 getConjuntoValores(conjuntoValores);
 tempoFinal = clock(); //finaliza contagem do tempo
 //calcula e mostra o tempo total de execucao
 printf("Tempo: %f s\n", (double) (tempoFinal - tempoInicial) / CLOCKS_PER_SEC);
}
/*fun��o aux que vai ajudar a buscar e retorna o indice do menor elemento do conjunto de valores n�o ordenados*/
/*vai procurar o menor elemento do conjunto de valores, a cada itera��o, se em uma das inicias ele for encontrado, ele e comparado com os proximos para ver se a elemento menor que ele,
se for encontrado no final n�o tem muito com quem compara*/
int getIndiceElemento(int conjuntoValores[],int tamanho,int posicaoInicial) {
 int indiceOriginal = posicaoInicial;
 int indice;
 for(indice = posicaoInicial + 1; indice < tamanho; indice++) {
     if(conjuntoValores[indiceOriginal] > conjuntoValores[indice]) {
        indiceOriginal = indice;//indice do menor elemento vai para inidiceOriginal
     }
 }
 return indiceOriginal; //retorna o indice do menor elemento
}

/*fun��o que vai fazer a ordena��o do conjunto de valores aplicando o metodo do selection sort*/
void selectionSort(int conjuntoValores[],int posicaoInicial) {
 int indiceMenor,indice,auxTroca;//variaveis auxiliares
 for(indice = 0; indice < TAMANHO; indice++) {
     indiceMenor = getIndiceElemento(conjuntoValores,TAMANHO,indice);//procura internamente na fun��o o indice do menor elemento do conjunto
     //faco a troca do menor elemento retornado pelo elemento que estou agora,isso vai acontecendo ate a itera��o termina, ate o tamanho do array
     troca(&conjuntoValores[indice],&conjuntoValores[indiceMenor]);
     /*
     auxTroca = conjuntoValores[indice];
     conjuntoValores[indice] = conjuntoValores[indiceMenor];
     conjuntoValores[indiceMenor] = auxTroca;
     */
 }
}

void getConjuntoValores(int conjuntoValores[]) {
 //imprime a lista de valores
 for(int i = 0; i < TAMANHO; i++) {
     printf("%d\t",conjuntoValores[i]);
 }
 printf("\n");
}

//porque usa *a ? porque estou trocando os valores de uma varivel para a outra, usando a referencia dos endere�os
//sem infrigir a integridade das variaveis, estou manipulando diretamente nelas, n�o nos endere�os mas no nivel de valores via ponteiro
void troca(int *a,int *b) {
 int aux = *a;
 *a = *b;
 *b = aux;
}
