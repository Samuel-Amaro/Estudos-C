/*
*ALGORITMO DE ORDENAÇÃO: INSERTION SORT
*APLICADO EM UM CONJUNTO DE VALORES EM UM VETOR
*PROBLEMA: ORDENAR UM CONJUNTO DE VALORES DE FORMA EFICIENTE E SEM CONSUMO DE MUITOS RECURSOS
*CRIADO E USADO: 16/03/2020
*ESTUDADO VIA SLIDE
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 4 //definido o tamanho do conjunto de valores que vou usar

/*ordena um conjunto de valores com o metodo de ordenação(Insertion Sort)*/
void insertionSort(int vetor[]);

//função que recebe duas variaveis via referencia e faz troca de valores entre elas
void troca(int *variavel_1,int *variavel_2);

//função que vai mostrar o conjunto de valores
void getValores(int vetor[]);

void main() {
 int vetor[TAMANHO];
 clock_t tempoInicial, tempoFinal; //Variaveis para guardar o tempo de execucao
 srand(time(NULL)); //Cria uma semente para numeros aleatorios
 tempoInicial = clock(); //inicia contagem do tempo
 for(int i = 0; i < TAMANHO; i++) {
  vetor[i] = rand() % 100; //Atribui um inteiro aleatorio entre 0 e 9
 }
 getValores(vetor);
 insertionSort(vetor);
 getValores(vetor);
 tempoFinal = clock(); //finaliza contagem do tempo
 //calcula e mostra o tempo total de execucao
 printf("Tempo: %f s\n", (double) (tempoFinal - tempoInicial) / CLOCKS_PER_SEC);
}
//implementação da ordenação
void insertionSort(int vetor[]) {
 int indice_externo,indice_interno;
 for(indice_externo = 1; indice_externo < TAMANHO; indice_externo += 1) {
     indice_interno = indice_externo;
     while(indice_interno > 0) {
           if(vetor[indice_interno - 1] > vetor[indice_interno]) {
              troca(&vetor[indice_interno - 1],&vetor[indice_interno]);
              indice_interno -= 1;
           }else
             break;
    }
 }
}

void troca(int *variavel_1,int *variavel_2) {
 int aux = *variavel_1; //recebe o valor da var1
 *variavel_1 = *variavel_2;
 *variavel_2 = aux;
}

void getValores(int vetor[]) {
 for(int i = 0; i < TAMANHO; i += 1)
    printf("%d\t",vetor[i]);
 printf("\n\n");
}
