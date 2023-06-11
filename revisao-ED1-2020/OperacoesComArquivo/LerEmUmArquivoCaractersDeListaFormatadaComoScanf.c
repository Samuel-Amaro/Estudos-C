#include <stdio.h>
#include <string.h>

void main()
{
/*a linguagem c tambem permite ler uma lista formatada de variaveis em um arquivo do mesmo modo como fazemos
na tela do computador com o scanf()*/
//usamos o fscand();
//forma geral:
//fscanf(FILE *arquivoExistente,"tipos de entrada",variaveis);
//ex: pegando um arquivo existente so para leitura

 FILE *arquivo = fopen("arquivoCadastroPessoa.txt","r");
 if(arquivo == NULL)
    printf("Arquivo Inexistente\n");
 else{
     char texto[20],nome[20]; //tem que criar as variaveis que vai receber os dados existentes da leitura
     int idade;
     float peso;
     printf("---------------------------\n");
     fscanf(arquivo,"%s",texto);
     printf("%s",texto);
     fscanf(arquivo,"%s",nome);
     printf("%s\n",nome);
     fscanf(arquivo,"%s %f",texto,&idade);
     printf("%s %.2f\n",texto,idade);
     fscanf(arquivo,"%s %f",texto,&peso);
     printf("%s %.2f\n",texto,peso);
     printf("---------------------------\n");
     fclose(arquivo);
 }

}
