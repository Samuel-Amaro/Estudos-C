#include <stdio.h>

/*
 *DECLARA��O DE CONSTANTES - (VALOR QUE NUNCA E MODIFICADO)
 *sintaxe:
 const tipo_dado nome_constante = valor_constante;
 vai ser como uma variavel que n�o pode ser manipulada

 *OUTRA MANEIRA DE DECLARAR UMA CONTANTE E USANDO DEFINE:
  #define nome_constante valor
  vai ser uma subtitui��o de um nome por valorss
*/
void main() {
 //exemplo
 const int salario = 1500;
 //n�o posso modificar minha constante:
 //salario = 100;
 //isso n�o existe
 printf("Constante = %d\n",salario);
}
