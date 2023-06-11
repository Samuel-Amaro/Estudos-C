/*
*ALGORITMO DE ORDENAÇÃO 01 NOME DO ALGORITMO: (BUBBLE SORT)
*IMPLEMENTAÇÃO PROFESSOR MENDES ED1
*COMO FUNCIONA O BUBBLE SORT ?
*COMO ELE ORDENA ?
*OBS: ORDENAÇÃO DESSE ALGORITMO E APLICADA EM UM NUMERO DEFINIDO DE VALORES, NÃO E ORDENAÇÃO SOB DEMANDA LIVRE.
 E EM UM NUMERO DE VALORES DEFINIDOS QUE TENHO, EM UM CONJUNTO DE VALORES VOU APLICAR A ORDENAÇÃO.

*SOBRE A ORDENAÇÃO: CADA VALOR E COMPARADO COM SEUS PROXIMOS VALORES.
*SEMPRE O VALOR MAIOR DE CADA COMPARAÇÃO VAI SE DESLOCANDO PARA O FINAL ASSIM ORDENAÇÃO EM CRESCENTE
* SO VER A FIGURA 4.1 DO PDF livro_algoritmo_estrutura_De_Dados.
*/
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#define TAMANHO 10 //UMA CONSTANTE COM VALOR 4



/*função que vai ordena o conjunto de valores armazenados em um array dimensional*/
void ordena(int array[]);

/*mostrar conjunto de valores*/
void getValores(int array[]);


void main() {
 clock_t tempoInicial, tempoFinal; //Variaveis para guardar o tempo de execucao do programa
 srand(time(NULL)); //Cria uma semente para numeros aleatorios
 tempoInicial = clock(); //inicia contagem do tempo
 int conjuntoValores[TAMANHO]; //LOCAL PARA OS VALORES SEREM ARMAZENADOS
 for(int i = 0; i < TAMANHO; i++)
     conjuntoValores[i] = rand() % 100 + 1; //Atribui um inteiro aleatorio entre 0 e 100
 getValores(conjuntoValores);
 ordena(conjuntoValores);
 getValores(conjuntoValores);
 tempoFinal = clock(); //finaliza contagem do tempo
 printf("Tempo da execucao: [%.4f]Segundos\n",(double) (tempoFinal - tempoInicial) / CLOCKS_PER_SEC);
}

/*função que vai ordena o conjunto de valores armazenados em um array dimensional*/
void ordena(int array[]) {
 printf("Começando ordenação!\n");
 int aux = 0,indice_1,indice_2;
 for(indice_1 = 0; indice_1 < TAMANHO; indice_1 += 1) {
     for(indice_2 = 0; indice_2 < TAMANHO - 1; indice_2 += 1) {
         if(array[indice_2] > array[indice_2 + 1]) {
            printf("%d > %d ? - S - TROCA -  i = %d - j = %d\n",array[indice_2],array[indice_2 + 1],indice_1,indice_2);
            aux = array[indice_2];
            array[indice_2] = array[indice_2 + 1];
            array[indice_2 + 1] = aux;
         }else{
              printf("%d > %d ? - S - Nao TROCA -  i = %d - j = %d\n",array[indice_2],array[indice_2 + 1],indice_1,indice_2);
         }
     }
 }
}


/*mostrar conjunto de valores*/
void getValores(int array[]) {
 for(int i = 0; i < TAMANHO; i += 1)
     printf("[%d]\t",array[i]);
}
