#include <stdio.h>
/*
 *DIRETIVAS DE COMPILAÇÃO: São istruçoes que servem para fazer alterações no codigo-fonte
  antes de envia-lo para o compilador
 *DIRETIVA "define": essa diretiva informa ao compilador que ele deve procurar todas as
  ocorrencias de determinada expressão e sustituila por outra quando o programa for compilado

 *diretiva "define":
  premite tres sintaxes

   - Sintaxe 1:
     #define nome
      define um nome que podera ser testado com os comandos de inclusão condicional
      ex em main:
   - Sintaxe 2:
     #define nomeCostante ValorConstante
      informa ao compilador que ele deve procurar todas as ocorrencias de "nomecostante" e
      substituila por "valor constante" quando o programa for compilado
*/

#define Samuel_Amaro //ex de sintaxe 1
#define PI 3.141516 //ex de sintaxe 2


void main(void)
{
//ex1 de sintaxe 1:
//se tiver algo definido como Samuel_Amaro, Faça isso
#ifdef Samuel_Amaro
      printf("Samuel_Amaro foi Definido Na Sintaxe 1\n");
#endif // Samuel_Amaro
printf("Constante PI = %.6f\n",PI);
}
