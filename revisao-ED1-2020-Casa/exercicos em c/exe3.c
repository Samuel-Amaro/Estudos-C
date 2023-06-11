/*
Faça um programa que modifique as vogais de uma frase. O programa deve ler uma frase (max. 100 caracteres) e armazeá-la num vetor.
Imprimir a frase lida trocando as vogais, isto é, trocar 'a' pelo 'u', 'e' pelo 'o', 'i' pelo 'u', 'o' pelo 'a' e o 'u' pelo 'e'.
Usar uma função void (procedimento) para realizar a troca e uma função para realizar a impressão da frase trocada.
A função deve ter como parâmetro um ponteiro char referente ao vetor. Dica: Use a função gets() da biblioteca string.h para realizar a leitura da frase.
use o switch para realizar as trocas. Só considere as letras minúsculas.
*/
#include <stdio.h>
#include <string.h>

void trocaVogal(char *vetor,int tm);

void main()
{
char frase[100];
printf("Digite uma frase:");
gets(frase);
int tm = strlen(frase);
trocaVogal(frase,tm);
printf("Sua Frase Modificada: %s\n",frase);
}

void trocaVogal(char *vetor,int tm)
{
for(int i = 0; i < tm; i += 1) {
 switch(vetor[i]) {
  case 'a':
   vetor[i] = 'u';
   break;
  case 'e':
   vetor[i] = 'o';
   break;
  case 'i':
   vetor[i] = 'u';
   break;
  case 'o':
   vetor[i] = 'a';
   break;
  case 'u':
   vetor[i] = 'e';
  default:
   break;
 }
}
}
