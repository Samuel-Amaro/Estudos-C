#include <stdio.h>
#include <stdlib.h>

/*ponteiro para ponteiro, um ponteiro que aponta para outro ponteiro*/

void main() {
//exemplo
 int x = 10;
 int *ponteiro_nivel_1 = &x;
 //ponteiro para um outro ponteiro de tipo inteiro
 int **ponteiro_nivel_2 = &ponteiro_nivel_1;
 //para entender
 printf("&p1 = %p\n",ponteiro_nivel_2);
 printf("&x atraves de p2 = %p\n",*ponteiro_nivel_2);
 printf("valor que a variavel x tem e = %d\n",**ponteiro_nivel_2);
 //p2 ---- > &p1 ----- > &x ------> x = 10;
 //(           )(usa nivel*)(usa nivel** )
}
