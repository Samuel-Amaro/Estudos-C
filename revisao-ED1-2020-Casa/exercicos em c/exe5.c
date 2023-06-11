/*Fazer um programa que lê um conjunto de 10 valores e os imprime ordenados.*/
#include <stdio.h>
#include <string.h>

void main()
{
 int vetor[10];
 for(int i = 0; i < 10; i++) {
     printf("Digite um valor:");
     scanf("%d",&vetor[i]);
 }
 printf("Seu valore Digitados Foram:");
 for(int j = 0; j < 10; j++)
     printf("%d\t",vetor[j]);
 printf("\n");

 for(int i = 1; i < 10; i++) {
     for(int t = 0; t < 10 - 1; t++)
     {
         if(vetor[i] > vetor[t]){
            int aux = vetor[i];
            vetor[i] = vetor[t];
            vetor[t] = aux;
         }
     }
 }
 for(int j = 0; j < 10; j++)
     printf("%d\t",vetor[j]);
 printf("\n");
}
