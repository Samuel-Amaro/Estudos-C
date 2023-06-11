#include <stdio.h>

/*CLASSES DE ARMAZENAMENTO NA LINGUAGEM C
CONJUNTO DE MODIFICADORES QUE PERMITEM ALTERAR A MANEIRA COMO O COMPILADOR VAI ARMAZENAR
UMA VARIAVEL
SÃO UTILIZADAS PARA DEFINIR O ESCOPO E O TEMPO DE VIDA
DAS VARIAVEIS DENTRO DO PROGRAMA

AS 4 CLASSES DE ARMAZENAMENTO:
AUTO
EXTERN
STATIC
REGISTER
*/


void main()
{
/*CLASSE DE ARMAZENAMENTO AUTO
- PERMITE DEFINIR VARIAVEIS LOCAIS
- AS VARIAVEIS SÃO AUTOMATICAMENTE ALOCADAS,
NO INICIO DE UMA FUNÇÃO/BLOCO DE COMANDOS,
E AUTOMATICAMENTE LIBERADAS QUANDO ESSA FUNÇÃO/BLOCO DE
COMANDOS TERMINA.
- MODO-PADRÃO DE DEFINIÇÃO DE VARIAVEIS E, POR ESSE MOTIVO, RARAMENTE USADO
*/
//AS VARIAVEIS A SEGUIR POSSUEM A MESMA CLASSE DE ARMAZENAMENTO
int x;
auto int y;

/*
extern
- permite definir variaveis globais que serão visiveis em mais de um arquivo
do programa
- ao colocar a palavra extern antes da declaração de uma variavel, não estamos declarando uma nova variavel,
mas apenas informando ao compilador que ela existe em outro local de armazenamento previamente definido. por esse motivo,
ele não pode ser inicializada.
*/
}
