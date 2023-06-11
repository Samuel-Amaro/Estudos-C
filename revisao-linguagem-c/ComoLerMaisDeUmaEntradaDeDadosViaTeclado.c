#include <Stdio.h>

/*
 * COMO LER MAIS DE UMA ENTRADA DE DADOS EM UM MESMO SCANF,com valores numericos
*/
void main() {
 int valor_1;
 float valor_2;
 printf("Digite dois Valores o primeiro inteiro Apos digitar tecle enter,\ndigite o segundo com casa decimal e tecle enter = ");
 scanf("%d%f",&valor_1,&valor_2);
 printf("Valor_1: %d \t Valor_2: %.2f\n",valor_1,valor_2);
}
