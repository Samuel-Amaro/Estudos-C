#include <stdio.h>
#include <stdlib.h>

void main()
{
/*ponteiros*/
//variavel especial que armazenam endere�os de memoria de alguma coisa(como outra variavel)

//como declarar um ponteiro
//tipo_ponteiro *nome_ponteiro; //ponteiro de tipo inteiro com o nome etc....
//ex
int *ponteiro;

//NULL == ENDERE�O DE NENHUM LUGAR

//USANDO O PONTEIRO PARA APONTAR PARA UMA VARIAVEL EXISTENTE
int variavel = 10;
//ponteiro passa a apontar para a variavel inteira(sendo que a variavel e o ponteiro s�o de mesmo tipo)
ponteiro = &variavel;

//entendendo
printf("Endereco da variavel = %p\n",&variavel);
printf("endereco que o ponteiro esta apontando e = %p\n",ponteiro);
printf("Valor do conteudo da variavel e = %d,valor do conteudo do endereco que ponteiro aponta e = %d\n",variavel,*ponteiro);
//*ponteiro == acessar o endere�o que p esta apontando e ir la e mostrar o conteudo desse endere�o o valor que ele armazena
//ponteiro----- > &variavel -----> 10;
//(    ponteiro   )(   *ponteiro     )
//tambem posso modifiar o conteudo do endere�o que o ponteiro aponta
// posso ir la e mudar o conteudo, escrever nesse endere�o
//ex:
*ponteiro = 1000;
printf("variavel apos ponteiro modificala = %d \t ponteiro %d\n",variavel,*ponteiro);
}
