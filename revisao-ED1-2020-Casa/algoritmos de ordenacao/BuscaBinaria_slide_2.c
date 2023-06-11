/*A busca binaria e um algoritmo um pouco mais sofisticado.
e mais efciente, mas requer que o vetor esteja ordenado pelos valores da chave de busca.
A ideia do algoritmo e a seguinte (assuma que o vetor esteja ordenado):
I Verifique se a chave de busca e igual ao valor da posicão do meio do vetor.
I Caso seja igual, devolva esta posicão I Caso o valor desta posicão seja maior, ent~ao repita o processo mas
considere que o vetor tem metade do tamanho, indo ate a posicão anterior a do meio.
I Caso o valor desta posicão seja menor, então repita o processo mas considere que o vetor tem metade do tamanho e inicia na posicão
seguinte a do meio.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAMANHO 10

//implementação da busca binaria
int buscaBinaria(int conjuntoValores[],int elemento);

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
 //ordena o conjunto de valores antes de aplicar busca
 insertionSort(vetor);
 getValores(vetor);
 int elemento = buscaBinaria(vetor,89); //aplica busca
 if(elemento != -1)
    printf("Seu elemento esta %d\n",elemento);
 else
    printf("Sua chave  não foi encontrada\n");
 tempoFinal = clock(); //finaliza contagem do tempo
 //calcula e mostra o tempo total de execucao
 printf("Tempo: %f s\n", (double) (tempoFinal - tempoInicial) / CLOCKS_PER_SEC);
}

//busca binaria que e aplicada em um conjunto de valores ja ordenados nãi importa a forma
int buscaBinaria(int conjuntoValores[],int elemento) {
 int inicio = 0,fim = TAMANHO - 1,meio;
 while(inicio <= fim) {
      meio = (inicio + fim) / 2;
      if(conjuntoValores[meio] == elemento)
         return elemento;
      else if(conjuntoValores[meio] > elemento)
              fim = meio - 1;
      else
          inicio = meio + 1;
 }
 return -1;
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

//ajuda na troca de valores entre variaveis
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
