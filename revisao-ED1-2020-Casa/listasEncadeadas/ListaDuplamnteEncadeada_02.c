/*LISTA DUPLAMENTE ENCADEADA*/
#include <stdio.h>
#include <stdlib.h>

//estrutura de um no da lista
struct no{
int information;
struct no *proximoNo;
struct no *noAnterior;
};

//apelido para um No
typedef struct no No;

//controlador de referencia da lista, de onde a lista paro com seu respectivo ultimo no
No *controlador = NULL;

//prototipo da função que cria a lista e adiciona dados na lista
void adicionaDado(int dado);

//função de imprimir a lista
void getLista();

//prototipo da função de excluir um dado da lista
void deleteNo(int dado);

//função que recebe a lista e formata ela em .dot para renderizar para png
void geraListaDot(FILE **arquivoDot);

//função que recebe um no e verifica se ele e valido e retorna seu valor
int getValorNo(No **no);
/*porque ponteiro para ponteiro ?
porque eu vou estar usando um ponteiro quando for passar o no para a função,
assim para acessar o valor do ponteiro passado, e tambem por questão de passar um dado por referencia para manter integridade
*/

//escreve o inicio da função .dot no arquivo
void escreveInicio(FILE **arquivoDot);

//escreve o final da função .dot no arquivo
void escreveFinal(FILE **arquivoDot);

void main()
{
 for(int i = 0; i < 5; i++)
    adicionaDado(i);
 getLista();
 FILE *arquivoDot = fopen("Arquivo.dot","w");
 escreveInicio(&arquivoDot);
 geraListaDot(&arquivoDot);
 escreveFinal(&arquivoDot);
 fclose(arquivoDot);
 system("dot -Tpng Arquivo.dot -o ListaDuplamenteEncadeada.png");//renderiza um arquivo .dot em png
}

//implementação da funçaõ que cria a lista
void adicionaDado(int dado)
{
 //o novo no e alocado dinamicamente
 No *novoNo = (No*)malloc(sizeof(No));
 //se for o primeiro no e para criar a lista
 if(controlador == NULL) {
    novoNo->information = dado;
    novoNo->proximoNo = NULL;
    novoNo->noAnterior = NULL;
    controlador = novoNo;
 }else{
      novoNo->information = dado;
      novoNo->proximoNo = controlador;
      controlador->noAnterior = novoNo;
      novoNo->noAnterior = NULL;
      controlador = novoNo;
 }
}

//implementação da função que imprimi a lista duplamente encadeada ok
void getLista()
{
 if(controlador == NULL)
    printf("Lista Vazia!\n");
 else{
    No *percorreLista = controlador;
    while(percorreLista != NULL){
          printf("---------------------------------------------\n");
          printf("A = %p D = %d E = %p P = %p|\n",percorreLista->noAnterior,percorreLista->information,percorreLista,percorreLista->proximoNo);
          printf("---------------------------------------------\n");
          int i = 0;
          if(percorreLista->proximoNo != NULL) {
            while(i < 3) {
               printf("\t\t\t\t\t|\n");
               i += 1;
            }
            printf("\t\t\t-----------------\n");
            printf("\t\t       \\/\n");
          }
          percorreLista = percorreLista->proximoNo;
    }
  }
 }

 //implementação da função excluir um no na lista encadeada
 void deleteNo(int dado) {
 if(controlador == NULL)
    printf("Lista Vazia\n");
 else{
     No *percorreLista = controlador;
     while(percorreLista != NULL) {
          if(percorreLista->information == dado) {
            //apagar o ultimo no da lista
            if(percorreLista == controlador) {
               controlador = controlador->proximoNo;//atualiza a lista
               controlador->noAnterior = NULL;
               free(percorreLista);
               percorreLista = controlador;
               return;//apos executar sair da função
            }else{
                 No *auxA = percorreLista->noAnterior;
                 No *auxP = percorreLista->proximoNo;
                 auxA->proximoNo =auxP;
                 auxP->noAnterior = auxA;
                 free(percorreLista);
                 controlador = auxA;
                 percorreLista = controlador;
                 return;

            }
          }else{
               percorreLista = percorreLista->proximoNo;
          }
     }
 }
}


//função que recebe a lista e formata ela em .dot para renderizar para png
void geraListaDot(FILE **arquivoDot) {
 if((*arquivoDot) == NULL) {
    printf("Impossivel De Usar o Arquivo!\n");
    return;
 }else{
      No *percorreLista = controlador;
      //escrevendo os dados da lista encadeada usando so os ponteiros de referencia,
      //proximoNo(isso e tipo do fim ate o inicio, seguindo a lista por ordem de dados inseridos em sequencia
      while(percorreLista != NULL) {
            fprintf((*arquivoDot),"%d->%d;\n",percorreLista->information,getValorNo(&percorreLista->proximoNo));
            percorreLista = percorreLista->proximoNo;
      }
      /*
      //escrevendo os dados da lista encadeada usando o ponteiro de referencia, os anteriores
      // isso e tipo do inicio ate fim
      No *percorreAnterior = percorreLista; //percorre lista foi storado ate chegar ao dado 1 tipo inico, agora faço o caminho contrario
      while(percorreAnterior != NULL) {
           fprintf((*arquivoDot),"%d->%d;\n",getValorNo(&percorreAnterior->noAnterior),percorreAnterior->information);
           percorreAnterior = percorreAnterior->noAnterior;
      }
      */
 }
}

//função que recebe um no e verifica se ele e valido e retorna seu valor
int getValorNo(No **no) {
 if((*no) == NULL)
    return -1;
 else
    return (*no)->information;
}

//escreve o inicio da função .dot no arquivo
void escreveInicio(FILE **arquivoDot) {
 if((*arquivoDot) == NULL)
    printf("Impossivel Escrever No arquivo!\n");
 else{
     fputs("digraph",(*arquivoDot));
     fputc('{',(*arquivoDot));
     fputc('\n',(*arquivoDot));
 }
}

//escreve o final da função .dot no arquivo
void escreveFinal(FILE **arquivoDot) {
 if((*arquivoDot) == NULL)
    printf("Impossivel Escrever No arquivo!\n");
 else{
     fputc('}',(*arquivoDot));
 }
}
