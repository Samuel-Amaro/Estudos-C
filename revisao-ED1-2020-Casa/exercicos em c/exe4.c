/*inserir valores na lista ordenadamente*/
#include <stdlib.h>
#include <stdio.h>

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

//void ordena lista
void ordenaLista();

void getListaOrdenada(int *vetor,int indice);

void main()
{
 //for(int i = 0; i < 5; i++)
    adicionaDado(3);
    adicionaDado(10);
    adicionaDado(100);
    adicionaDado(1);
    adicionaDado(90);
 getLista();
 ordenaLista();
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
 No *aux = controlador;
 if(aux == NULL)
    printf("Lista Vazia!\n");
 else{
    while(aux != NULL){
          printf("--------------------------------\n");
          printf("D = %d E = %p P = %p|\n",aux->information,aux,aux->proximoNo);
          printf("--------------------------------\n");
          int i = 0;
          if(aux->proximoNo != NULL) {
            while(i < 3) {
               printf("\t\t\t|\n");
               i += 1;
            }
            printf("              -----------\n");
            printf("\t      V\n");
          }
          aux = aux->proximoNo;
   }
 }
}

void ordenaLista()
{
 int indice = 0;
 int dadosLista[indice];
 if(controlador == NULL)
    printf("Lista Vazia Impossivel De Ordenar!\n");
 else{
     No *aux = controlador;
     while(aux !=  NULL){
           dadosLista[indice] = aux->information;
           aux = aux->proximoNo;
           indice += 1;
     }
 }
 printf("Dados no vetor\n");
 for(int i = 0; i < indice; i += 1)
    printf("%d\t",dadosLista[i]);
 printf("\n");

 //ordena vetor com os valores antes de passar para a lista original
 int aux;
 for(int i = 1; i < indice; i += 1) { //o for externo e so para controlar o numero de comparações do for interno
     for(int j = 0; j < indice - 1; j += 1) {
         if(dadosLista[j] > dadosLista[j+1]) {
            aux = dadosLista[j];
            dadosLista[j] = dadosLista[j+1];
            dadosLista[j+1] = aux;
         }
     }
 }
 printf("ordenado os Dados no vetor\n");
 for(int i = 0; i < indice; i += 1)
    printf("%d\t",dadosLista[i]);
 printf("\n");
 getListaOrdenada(dadosLista,indice);
}

void getListaOrdenada(int *vetor,int indice) {
 if(controlador == NULL)
    printf("Lista Vazia\n");
 else{
     //vou adicionar valores ordenados em um lista aux porque não quero mexer na original
     No *aux = controlador;
     int i = 0;
     while(aux != NULL && i < indice){
          aux->information = vetor[i];
          aux = aux->proximoNo;
          indice++;
     }
     No *aux2 = controlador;
     while(aux2 != NULL){
          printf("--------------------------------\n");
          printf("D = %d E = %p P = %p|\n",aux2->information,aux2,aux2->proximoNo);
          printf("--------------------------------\n");
          aux2 = aux2->proximoNo;
   }
 }
}
