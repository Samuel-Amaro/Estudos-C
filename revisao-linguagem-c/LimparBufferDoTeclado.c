#include <stdio.h>

/* LIMPANDO O BUFFER DO TECLADO
QUANDO USAMOS A FUNÇÃO SCANF(), ELA RECUPERA A INFORMAÇÃO
DO BUFFER. POREM, ELA PODE DEIXAR SUJEIRA NO BUFFER, COMPROMETENDO FUTURAS LEITURAS
*/



void main()
{
//PENSANDO NAS FUTURAS LEITURAS QUE AGENTE LIMPA O BUFFER
//EX DE NECESSIDADE DE LIMPAR O BUFFER:
 /*int i = 0;
 char caracter;
 for(i = 0; i < 5; i += 1) {
     printf("Digite %d caracter:",i + 1);
     scanf("%c",&caracter);
 }
 */
 /*EXISTEM MUITAS FORMAS DE LIMPAR O BUFFER DO TECLADO.
  A MAIS CERTA E UTILIZAR:
  setbuf(stdin,NULL);
 */
 //ex:
 int j = 0;
 char c;
 printf("Maneira Certa!\n");
 for(j = 0; j < 5; j += 1) {
     printf("Digite %d caracter:",j + 1);
     scanf("%c",&c);
     setbuf(stdin,NULL);
 }
}
