/*
* ENTENDENDO RECURSIVIDADE EM C.
* uma função pode chamar ela mesma.
* em uma função recursiva tem que sempre levar em conta uma maneira de como ela pode ser inteerropida quando atinge seu objetivo.
*  RECURSÃO = É um processo que quebra um problema em problemas menores, que serão quebrados em problemas menores ainda, até que chegamos no
  menor problema possível e na sua solução (caso básico), neste ponto começamos a retornar começando pelo caso básico.

*/

#include <stdio.h>
#include <stdlib.h>


//exemplo de uma função recursiva que imprime uma sequencia de valores
//so e interropida essa função quando um valor que vai ser imprimido seja menor que 0.
//a função chama ela mesma, mas a cada chamada, que não e interropida, vai continuar chamando ate ser interropida.
void imprime1(int n) {
 if (n < 0)
    return;
 printf("%2d, ", n);
 imprime1(n-1);
}
//função recursiva que imprime uma sequencia de valores, com uma condição de parada,
//quando o valor passado por parametro for menor que 0
void imprime2(int n) {
 if (n < 0)
    return;
  imprime2(n-1);
  printf("%2d, ", n);
}

//outro exemplo de função recursiva
//uma função que soma os elementos de um vetor de qualquer tamanho
int soma(int vetor[],int tamanho) {
 if(tamanho == 0)
    return;
 else
     vetor[tamanho - 1] + soma(vetor,tamanho - 1);
}
void main (void) {
 imprime1(10);
 printf("\n");
 imprime2(10);
 printf("\n");
 int vetor[10] = {3,9,74,21,90,73,21,32,89,100};
 soma(vetor,9);
 printf("")

}
