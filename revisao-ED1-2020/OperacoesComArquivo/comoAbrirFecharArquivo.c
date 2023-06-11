#include <stdio.h>
#include <stdlib.h>

void main(){
/*como abrir e fechar arquivo na linguagem c*/
/*USA A FUN��O fopen para abrir determinado arquivo num modo de leitura ou escrita*/
//ex:

FILE *fopen(char *nome,char *modo);

//ex:
//ponteiro para manipular arquivo e guardalo como uma variavel
FILE *arquivoNovo;
arquivoNovo = fopen("Arquivo.dot","w"); //para abrir arquivo e escrever usa o w, ao dar o nome do arquivo no fopen em que colocar sua extens�o
//aqui e .dot porque e para usar o graphivs para ver a aarvore binaria

//abriu arquivo ? verifica se deu certo
if(arquivoNovo == NULL) {
  printf("Arquivo n�o existe!\n");

}

//observa��es sobre a fun��o fopen();
//ao informar so nome do arquivo a fun��o, e dizendo que ele vai ficar salvo aonde o program .c esta salvo caminho relativo, o arquivo so pode ser usado quando o programa que ele foi criado esta sendo compilado

//mas se n�o quer salva ele na mesmo local do .c pode informar um caminho e no final da um nome
//ex:
FILE *arquivoTeste = fopen("C:Documents/arquivo.dot","w");

//tipos de abertura de arquivo
//"r" leitura de arquivo
//"w" escrita de arquivo texto

//apos terminar de usar um arquivo sempre tem que lembrar de fechar o arquivo
// fechar um arquivo e como saber que os dados foram gravados no arquivo
fclose(arquivoTeste);
fclose(arquivoNovo);
}
