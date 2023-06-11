#include <stdio.h>
#include <string.h>

void main(void)
{
/*ler e escrever strings com funções do console*/
//função gets le uma string do teclado ate ser apertada a tecla enter para terminar a string
//char *gets(char *str);
//o argumento str e um vetor de caracteres vazio para, a função ler os caracteres e colocar no vetor
//ex:
printf("Digite uma String: ");
char string[100];
gets(string);
printf("Tamanho da sua String: %d\n",strlen(string));

//função puts ecreve string de caracteres na tela e pula linha, escreve so string não escreve outras saida de dados, so caracter.
//int puts(cost char *str); -- str e um vetor de caracteres preenchido com caracter para fazer a saida com strings
puts(string);
puts("Sua String Digitada Acima!\n");
}
