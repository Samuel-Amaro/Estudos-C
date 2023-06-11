#include <stdio.h>

/*
 *DECLARAÇÃO DE CONSTANTES - (VALOR QUE NUNCA E MODIFICADO)
 *sintaxe:
 const tipo_dado nome_constante = valor_constante;
 vai ser como uma variavel que não pode ser manipulada

 *OUTRA MANEIRA DE DECLARAR UMA CONTANTE E USANDO DEFINE:
  #define nome_constante valor
  vai ser uma subtituição de um nome por valorss
*/
void main() {
 //exemplo
 const int salario = 1500;
 //não posso modificar minha constante:
 //salario = 100;
 //isso não existe
 printf("Constante = %d\n",salario);
}
