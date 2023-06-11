#include <stdio.h>

void main() {

 //MOSTRANDO UMA STRING INVERTIDA NA TELA SEM REALMENTE NELA MESMA INVERTER SO ESTA MOSTRANDO ELA INVERTIDA.
 char string[30] = "PARALELEPIPIDO";
 int p;
 for(p = strlen(string) - 1; p >= 0; p -= 1)
    printf("%c",string[p]);
 printf("\n");

 //INVERTENDO UMA STRING REALMENTE
 char s1[30] = "O RATO ROEU A ROPA DO REI";
 char strInvertida[30];
 int i,j = 0;
 for(i = strlen(s1) - 1; i >= 0; i -= 1) {
     strInvertida[j] = s1[i];
     j += 1;
 }
 //mostrando que estou finalizando a string
 strInvertida[j] = '\0';
 printf("String Invertida: %s\n",strInvertida);
}
