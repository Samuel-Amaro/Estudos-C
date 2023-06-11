#include <stdio.h>
#include <string.h>

void main()
{
/*tem como gravar varias strings em um arquivo escrever varias strings em um arquivo*/
//como escrever um string em um arquivo
//int fputs(char *str,FILE *arquivo);

//se der certo retorna um valor inteiro diferente de 0
// em caso de erro retorna EOF

//EX:
FILE *arquivo = fopen("arquivo.txt","w");
if(arquivo == NULL) {
   printf("Arquivo não existe!\n");
}else{
     char string[20] = {"Um Texto Para O Arquivo!\n"};
     //escrevendo toda a string no arquivo
     int retorno = fputs(string,arquivo);
     if(retorno == EOF)
        printf("Erro na Gravação da String\n");
     //fclose(arquivo);
}
//o fputs so grava a string, ela não acrecenta espaço,pula linha etc...
//o programador que tem que fazer issso
//ex:
fputs("Hello\n",arquivo);
fputs("Word\n",arquivo);

//ou

fputs("Samuel Amaro",arquivo);
fputc('\n',arquivo);//escreve so um caracter por vez
fputs("Vai Ser Um Programador De Sucesso,Se Deu Quiser",arquivo);
fclose(arquivo);
}
