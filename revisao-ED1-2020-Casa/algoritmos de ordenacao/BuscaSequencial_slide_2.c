/*
*TRABALHAREMOS COM BUSCA EM ALGORITMOS
*O PROBLEMA DA BUSCA E QUE ELA SEJA EFICIENTE CONSUMINDO POUCO RECURSOS
*CONTEXTUALIZAÇÃO:Temos uma cole¸c˜ao de elementos, onde cada elemento possui um
identificador/chave ´unico, e recebemos uma chave para busca. Devemos
encontrar o elemento da cole¸c˜ao que possui a mesma chave ou identificar
que n˜ao existe nenhum elemento com a chave dada.
* COMEÇAREMOS PELA BUSCA LINEAR SEQUENCIAL.
*SE ACHAR O ELEMENTO NO CONJUNTO RETORNA SUA POSIÇÃO NO CONJUNTO.
*SE NÃO ACHAR RETORNA O VALOR -1 COMO DIZENDO NÃO ACHOU.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 1000


/*metodo da busca linear sequencial simples*/
int busca(int conjuntoValores[],int elementoProcurado);

/*metodo de visualizar valores*/
void getValores(int conjuntoVlaores[]);

void main() {
 int conjuntoValores[TAMANHO];
 clock_t tempoInicial, tempoFinal; //Variaveis para guardar o tempo de execucao
 srand(time(NULL)); //Cria uma semente para numeros aleatorios
 tempoInicial = clock(); //inicia contagem do tempo
 for(int i = 0; i < TAMANHO - 3; i++) {
  conjuntoValores[i] = rand() % 1000 + 1; //Atribui um inteiro aleatorio entre 0 e 10000
 }
 getValores(conjuntoValores);
 int elemento = busca(conjuntoValores,991);
 printf("Seu elemento foi Achado ? %d\n",elemento);
 tempoFinal = clock();//finaliza contagem do tempo
 //calcula e mostra o tempo total de execucao
 printf("Tempo final execucao Algoritmo de busca: %f s\n", (double) (tempoFinal - tempoInicial) / CLOCKS_PER_SEC);
}

int busca(int conjuntoValores[], int elementoProcurado) {
 for(int indice = 0; indice < TAMANHO; indice += 1) {
     if(conjuntoValores[indice] == elementoProcurado) {
        return indice; //se achar o elemento no conjunto retorna a posição do indice
     }
 }
 return -1; //se não achar retorna -1
}

void getValores(int conjuntoValores[]) {
 for(int i = 0; i < TAMANHO; i += 1) {
    printf("[%d]\t",conjuntoValores[i]);
 }
 printf("\n\n");
}
