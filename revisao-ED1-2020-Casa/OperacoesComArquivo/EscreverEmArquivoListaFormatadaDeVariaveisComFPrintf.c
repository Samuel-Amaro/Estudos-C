#include <stdio.h>
#include <string.h>

void main()
{
/*a linguagem c tambem permite escever uma lista formatada de variaveis em um arquivo do mesmo modo como fazemos
na tela do computador com o printf()*/
//para isso usamos a função printf

//forma geral
// fprintf(FILE *arquivo,"TIPOS DE SAIDA",variaveis);
// nos tipo de saida pode escrever uma string com as saidas de formatação
//ex:

 int idade = 19;
 char nome[] = {"Samuel Amaro do Nascimento"};
 float peso = 63.200;

 FILE *arquivo = fopen("arquivoCadastroPessoa.txt","w");
 if(arquivo == NULL)
    printf("Arquivo Não Criado\n");
 else{
    fprintf(arquivo,"DADOS CADASTRAIS:\n Nome: %s\n Idade = %d\n Peso = %.2f\n",nome,idade,peso);
    fclose(arquivo);
 }
}
