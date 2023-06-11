#include <stdio.h>
#include <stdlib.h>

//estrutura de um no da lista
struct no{
int information;
struct no *proximoNo;
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

void main()
{
 for(int i = 0; i < 5; i++)
    adicionaDado(i);
 getLista();
 deleteNo(4);
 getLista();
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
    controlador = novoNo;
 }else{
      novoNo->information = dado;
      novoNo->proximoNo = controlador;
      controlador = novoNo;
 }
}

//implementação da função que imprimi a lista
void getLista()
{
 if(controlador == NULL)
    printf("Lista Vazia!\n");
 else{
    while(controlador != NULL){
          printf("--------------------------------\n");
          printf("D = %d E = %p P = %p|\n",controlador->information,controlador,controlador->proximoNo);
          printf("--------------------------------\n");
          int i = 0;
          if(controlador->proximoNo != NULL) {
            while(i < 3) {
               printf("\t\t\t|\n");
               i += 1;
            }
            printf("              -----------\n");
            printf("\t      \\/\n");
          }
          controlador = controlador->proximoNo;
    }
  }
 }

 //implementação da função excluir um no
 void deleteNo(int dado) {
 if(controlador == NULL)
    printf("Lista Vazia\n");
 else{
     No *percorreLista = controlador,*anterior;
     while(percorreLista != NULL) {
          if(percorreLista->information == dado) {
            //apagar o ultimo no da lista
            if(percorreLista == controlador) {
               controlador = controlador->proximoNo;//atualiza a lista
               free(percorreLista);
               return;//apos executar sair da função
            }
          }else{
               anterior = percorreLista;
               percorreLista = percorreLista->proximoNo;
          }
     }
 }
}
