#include <stdio.h>
#include <stdlib.h>

void main()
{
/*ponteiros*/
//variavel especial que armazenam endereços de memoria de alguma coisa(como outra variavel)

//como declarar um ponteiro
//tipo_ponteiro *nome_ponteiro; //ponteiro de tipo inteiro com o nome etc....
//ex
int *ponteiro;

//NULL == ENDEREÇO DE NENHUM LUGAR

//USANDO O PONTEIRO PARA APONTAR PARA UMA VARIAVEL EXISTENTE
int variavel = 10;
//ponteiro passa a apontar para a variavel inteira(sendo que a variavel e o ponteiro são de mesmo tipo)
ponteiro = &variavel;

//entendendo
printf("Endereco da variavel = %p\n",&variavel);
printf("endereco que o ponteiro esta apontando e = %p\n",ponteiro);
printf("Valor do conteudo da variavel e = %d,valor do conteudo do endereco que ponteiro aponta e = %d\n",variavel,*ponteiro);
//*ponteiro == acessar o endereço que p esta apontando e ir la e mostrar o conteudo desse endereço o valor que ele armazena
//ponteiro----- > &variavel -----> 10;
//(    ponteiro   )(   *ponteiro     )
//tambem posso modifiar o conteudo do endereço que o ponteiro aponta
// posso ir la e mudar o conteudo, escrever nesse endereço
//ex:
*ponteiro = 1000;
printf("variavel apos ponteiro modificala = %d \t ponteiro %d\n",variavel,*ponteiro);
}
