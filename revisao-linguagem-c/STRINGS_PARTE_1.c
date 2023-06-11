#include <stdio.h>

/*
 *STRINGS: um array de caracteres em c
 *vai ter uma quantidade especifica de caracteres adjacentes no array
 *armazenar palavras ou frases.
*/
void main() {
 //SINTAXE:
 //char nome_string[qtd_caracteres];

 //exemplo:
 char palavra[20];

 //lendo uma entrada de uma string via teclado com scanf
 printf("Digite uma palavra:");
 scanf("%s",palavra);
 //não a necessidade de passar o e comercial para a variavel(porque e um array ja e indexado naturalmente).
 //vai se lido caracteres de uma palvra ou frase ate encontrar um espeço em branco na frase ou se digitar enter oque ocorrer primeiro.
 //não se consegue ler varias palavras com o scanf
 //%s ler uma string do teclado
 printf("Palavra lida com scanf = %s\n",palavra);

 fflush(stdin);

 //LENDO UMA ENTRADA DE DADOS DE UMA STRING VIA TECLADO COM FUNÇÃO GETS
 printf("Digite outra Palavra:");
 gets(palavra);
 //ler varias palavras ate digitar um enter pode ter varias espeços em brancos entre as palavras porque so para de ler quando digita enter.
 printf("Palavra Lida com gets = %s\n",palavra);
 //como saida de um string inteira usa o caracter de escape %s


 //COMO INICIALIZAR UMA STRING DE FORMA CONVENCIONAL
 char p[15] = {'S','a','M','U','e','L','/0'};
 /*
  *tem que haver o contra barra 0 no final para dizer que e o final da string
 */
 printf("Inicializacao de forma convencional: %s\n",p);

 //INICIALIZANDO STRING DE FORMA DIRETA SEM ENROLACAO O C PERMITE:
 char t[15] = "Teste De Uma String";
 /*
  *abra as aspas duplas e digite sua string com quantidade certa de acordo com o array de caracteres
 */
 printf("Inicializando de forma Rapida: %s\n",t);
}
