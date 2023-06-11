#include <stdio.h>
#include <string.h>

void main()
{
char frase[100];
printf("Digite Uma Frase:");
gets(frase);
printf("Sua Frase e:%s\n",frase);
int tmFrase = strlen(frase);
printf("Tamanho Da Sua Frase:%d\n",tmFrase);
}
