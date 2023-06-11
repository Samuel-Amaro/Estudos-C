//ENTRADA E SAIDA DE DADOS NA LINGUAGEM C DE BIBLIOTECA PADRÃO VIA CONSOLE
//LENDO E ESCREVENDO CARACTERES
#include <stdio.h>
#include <conio.h>

void main(void)
{
//funções simples
//getchar() ler um caracter do teclado - entrada de dados
//espera uma tecla do teclado se digitada e retorna seu valor na tabela ASC2, a tecla digitada automaticamente e mostrada na tela
int getchar(void);
//putchar(int c); escreve um caracter na tela
printf("Digite um caracter para funcao getchar(): ");
setbuf(stdin,NULL); //limpando buffer para não perder os caracter na memoria
char caracter = getchar();
printf("Seu caracter digitado e: ");
putchar(caracter);
printf("\n");
//FUNÇÕES DE MESMO FUNCIONALIDADE DE GETCHAR - SERVE PARA LER UM TECLADO SO QUE DA BIBLIOTECA CONIO.H
printf("Digite um caracter para funcao(getch):");
setbuf(stdin,NULL);
char c2 = getch(); //essa função não mostra o caracter digitado quando esta digitando
printf("caracter lido com getch: ");
putchar(c2);
printf("\n");
printf("Digite um caracter para funcao(getche):");
setbuf(stdin,NULL);
char c3 = getche();
printf("\n");
printf("caracter lido com getche: ");
putchar(c2);
}
