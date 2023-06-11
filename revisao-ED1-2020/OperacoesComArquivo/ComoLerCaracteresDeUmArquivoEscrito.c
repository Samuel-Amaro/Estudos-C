#include <stdio.h>
#include <string.h>

void main() {

//como ler caracteres de um arquivo escrito ?
//usa a fun��o fgetc
//le um so caracter por vez do arquivo
//int fgetc(FILE *arquivoEscrito);
//em caso de erro retorna EOF
//em sucesso retorna o valor inteiro do caracter correposndido na tabela ASC2

FILE *arquivoTeste;
arquivoTeste = fopen("Arquivo.txt","r"); //abri o arquivo existente para leitura

if(arquivoTeste == NULL) {
    printf("Arquivo n�o existe!\n");
}else {
       //exemplo de manipula��o da fun��o fgetc, para ler dados no arquivo
      char caracter;
      for(int i = 0; i < 40; i++)
      {
      caracter = fgetc(arquivoTeste);
      printf("%c",caracter); //convers�o do codigo inteiro do caracter da tabela ASC2 em CARACTER
      }
      fclose(arquivoTeste);
 }
}
