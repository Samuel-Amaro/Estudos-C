/*
75. Escreva um programa para:
a. pedir 10 números ao usuário e armazenar esses valores em um array
b. pedir um outro número ao usuário e calcular e mostrar quantos números do array são
inferiores a esse número.
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
