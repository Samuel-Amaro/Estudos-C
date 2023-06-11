#include <stdio.h>
#include <string.h>

void main()
{
/*função que le uma string de um arquivo existente*/
//char* fgets(char *_ponteiro_para_guardar_a_string,int tamanho_qtd_caracteres_que_quero_ler,FILE *arquivo_que_possui_string);
//le uma string ate encontrar um \n

//em caso de erro retorna null
//em caso de sucesso retorna um ponteiro para o primeiro caractere da string

char string[20]; //guardar a string
FILE *arquivo;
arquivo = fopen("arquivo.txt","r"); //abrindo um arquivo existente para leitura
if(arquivo == NULL) {
   printf("Arquivo Não Existe!\n");
}else{
    char *result = fgets(string,20,arquivo);
    if(result == NULL) {
      printf("Erro Na Leitura\n");
    }else{
         printf("%s\n",result);
    }
}
fclose(arquivo);
}
