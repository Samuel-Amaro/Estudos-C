#include <stdio.h>

void main()
{
int j;
int soma = 0;
for(j = 2; j < 100; j += 1)
 {
   for(int i = 1; i < 100; i += 1) {

       if(j % i == 0)
          soma += i;
       if(j == soma)
         printf("Numero perfeito e: %d\n",j);
   }
   soma = 0;
 }
}
