-#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
//para escrever um unico caracter em um arquivo usa a fun��o
//int fputc(char caracter,FILE *arquivoParaEscrita);-

// em caso de erro retorna EOF
// em sucesso retorna o proprio caracter n�o convertido em ASC2
//ex:

FILE *arquivoTeste;
arquivoTeste = fopen("Arquivo.txt","w");

if(arquivoTeste == NULL) {
    printf("Arquivo n�o existe!\n");
}else {
       //exemplo de manipula��o da fun��o fputc, para escrever no arquivo
      char string[40] = {"Meu Primeiro Programa em C com Arquivo!\n"};
      for(int i = 0; i < 40; i++)
      {
      fputc(string[i],arquivoTeste);
      }
      fclose(arquivoTeste);
 }
}
