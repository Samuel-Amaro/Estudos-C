-#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
//para escrever um unico caracter em um arquivo usa a função
//int fputc(char caracter,FILE *arquivoParaEscrita);-

// em caso de erro retorna EOF
// em sucesso retorna o proprio caracter não convertido em ASC2
//ex:

FILE *arquivoTeste;
arquivoTeste = fopen("Arquivo.txt","w");

if(arquivoTeste == NULL) {
    printf("Arquivo não existe!\n");
}else {
       //exemplo de manipulação da função fputc, para escrever no arquivo
      char string[40] = {"Meu Primeiro Programa em C com Arquivo!\n"};
      for(int i = 0; i < 40; i++)
      {
      fputc(string[i],arquivoTeste);
      }
      fclose(arquivoTeste);
 }
}
