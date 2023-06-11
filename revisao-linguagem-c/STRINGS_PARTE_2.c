#include <stdio.h>
#include <string.h>

/*
 *A LINGUAGEM C POSSUI UMA BIBLIOTECA PARA MANIPULAÇÃO DE STRINGS
 *BIBLIOTECA STRING.H

 *FUNÇÕES:

  * strlen - tamanho da string

  *strcpy - copiar uma string

  *strcat - concatenar duas strings

  *strcmp - comparar duas strings
*/
void main() {

 //EXEMPLO DE TAMANHO DE UMA STRING
 char palavra[20] = "Meu Notebook e Top";
 int tamanho = strlen(palavra);
 //retorna um valor inteiro para o tamanho
 //o strlen mede a qtd de caracteres que a string possui não o seu tamanho definido no array
 printf("String: %s -> tamanho: %d\n",palavra,tamanho);

 //COPIANDO UMA STRING
 char t[20] = "Uma Frase!";
 char copia[30];
 strcpy(copia,t);
 printf("Palavra: %s\t copia palavra: %s\n",t,copia);

 //CONCATENANDO UMA STRINGS
 char palavra1[10] = "Bom Dia ";
 char palavra2[10] = "Samuel!";
 strcat(palavra1,palavra2);
 //o conteudo da palavra 2 vai para o final da palavra 1
 printf("Concatena Palavra: %s\n",palavra1);

 //COMPARANDO SE PALAVRAS SÃO IGUAIS
 char p1[15] = "LINGUAGEM C";
 char p2[15] = "LINGUAGEM C";
 if(strcmp(p1,p2) == 0)
    printf("Strings Iguais\n");
 else
    printf("String Diferentes\n");
 //linguagem c e caseSensitive porque difere maiuscula de minuscula
 //isso e faz diferença
 // retorna 0 string são iguais
 // retorna 1 strings são diferentes
}
