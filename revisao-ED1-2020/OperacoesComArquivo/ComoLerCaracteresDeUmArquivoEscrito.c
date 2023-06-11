#include <stdio.h>
#include <string.h>

void main() {

//como ler caracteres de um arquivo escrito ?
//usa a função fgetc
//le um so caracter por vez do arquivo
//int fgetc(FILE *arquivoEscrito);
//em caso de erro retorna EOF
//em sucesso retorna o valor inteiro do caracter correposndido na tabela ASC2

FILE *arquivoTeste;
arquivoTeste = fopen("Arquivo.txt","r"); //abri o arquivo existente para leitura

if(arquivoTeste == NULL) {
    printf("Arquivo não existe!\n");
}else {
       //exemplo de manipulação da função fgetc, para ler dados no arquivo
      char caracter;
      for(int i = 0; i < 40; i++)
      {
      caracter = fgetc(arquivoTeste);
      printf("%c",caracter); //conversão do codigo inteiro do caracter da tabela ASC2 em CARACTER
      }
      fclose(arquivoTeste);
 }
}
