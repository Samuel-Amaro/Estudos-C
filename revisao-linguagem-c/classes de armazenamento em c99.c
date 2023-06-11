#include <stdio.h>

/*CLASSES DE ARMAZENAMENTO NA LINGUAGEM C
CONJUNTO DE MODIFICADORES QUE PERMITEM ALTERAR A MANEIRA COMO O COMPILADOR VAI ARMAZENAR
UMA VARIAVEL
S�O UTILIZADAS PARA DEFINIR O ESCOPO E O TEMPO DE VIDA
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
- AS VARIAVEIS S�O AUTOMATICAMENTE ALOCADAS,
NO INICIO DE UMA FUN��O/BLOCO DE COMANDOS,
E AUTOMATICAMENTE LIBERADAS QUANDO ESSA FUN��O/BLOCO DE
COMANDOS TERMINA.
- MODO-PADR�O DE DEFINI��O DE VARIAVEIS E, POR ESSE MOTIVO, RARAMENTE USADO
*/
//AS VARIAVEIS A SEGUIR POSSUEM A MESMA CLASSE DE ARMAZENAMENTO
int x;
auto int y;

/*
extern
- permite definir variaveis globais que ser�o visiveis em mais de um arquivo
do programa
- ao colocar a palavra extern antes da declara��o de uma variavel, n�o estamos declarando uma nova variavel,
mas apenas informando ao compilador que ela existe em outro local de armazenamento previamente definido. por esse motivo,
ele n�o pode ser inicializada.
*/
}
