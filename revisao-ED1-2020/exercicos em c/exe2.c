/*
75. Escreva um programa para:
a. pedir 10 n�meros ao usu�rio e armazenar esses valores em um array
b. pedir um outro n�mero ao usu�rio e calcular e mostrar quantos n�meros do array s�o
inferiores a esse n�mero.
*/
#include <stdio.h>
#include <string.h>

void main()
{
int vetor[10],i;
for(i = 0; i < 10; i += 1) {
    printf("Digite um valor Inteiro qualquer:");
    scanf("%d",&vetor[i]);
}
}
