/*
Fa�a um programa que modifique as vogais de uma frase. O programa deve ler uma frase (max. 100 caracteres) e armaze�-la num vetor.
Imprimir a frase lida trocando as vogais, isto �, trocar 'a' pelo 'u', 'e' pelo 'o', 'i' pelo 'u', 'o' pelo 'a' e o 'u' pelo 'e'.
Usar uma fun��o void (procedimento) para realizar a troca e uma fun��o para realizar a impress�o da frase trocada.
A fun��o deve ter como par�metro um ponteiro char referente ao vetor. Dica: Use a fun��o gets() da biblioteca string.h para realizar a leitura da frase.
use o switch para realizar as trocas. S� considere as letras min�sculas.
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
