#include <stdio.h>
#include <string.h>
#include <locale.h>


int main() {
 setlocale(LC_ALL,"Portuguese");
 /*ao final de cada string, dentro da matriz tem que existir um \n, para mostrar que e o final da string*/

 //quando faço essa atribuição direta de string ao vetor ja automaticamente e inserido o \n
 char nome[20] = "Samuel Amaro";
 //atribuindo caracter por caracter ao vetor
 char n[20] = {'S','A','M','U','E','L',' ','A','M','A','R','O','\n'};

 //COMO SABER O TAMANHO DE UMA STRING
 int tm = strlen(nome);
 puts(tm);






 return 0;
}
