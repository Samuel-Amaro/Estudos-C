/*LISTA ENCADEADA SIMPLES, DINAMICAMENTE ALOCADA, ISSO E ? CRESCE A CADA VEZ MAIS QUE EXIGE DELA*/

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

//função de excluir um dado da lista
void deleteNo(int dado);

//função de receber um arquivo,e escrever nele a lista encadeada e depois renderizar em png
void geraArquivo(FILE **arquivo);

//função que retorna um valor que estiver dentro de um no
int getValorNo(No **no);

void main()
{
 FILE *arquivoDot = fopen("arquivo.dot","w");
 if(arquivoDot == NULL)
    printf("Printf Arquivo Vazio!\n");
 fputs("digraph",arquivoDot);
 fputc('{',arquivoDot);
 fputc('\n',arquivoDot);
 for(int i = 0; i < 5; i++)
    adicionaDado(i);
 geraArquivo(&arquivoDot);
 getLista();
 fputc('}',arquivoDot);
 fclose(arquivoDot);
 system("dot -Tpng arquivo.dot -o listaDinamica.png"); //renderiza um arquivo .dot em png
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

 //implementação da função de excluir um no
 void deleteNo(int dado) {
  No *aux = controlador;
  if(aux == NULL)
     printf("Lista Vazia!\n");
  else{
       No *anterior = controlador;
       while(aux != NULL) {
             if(aux->information == dado) {
                //apagar o ultimo no de referencia da lista
                if(aux == controlador) {
                   controlador = controlador->proximoNo;
                   free(aux);
                   aux = controlador;
                   return;
                }else{
                     //apagar um no que esta no meio de 2 nos e apagar o cabeça
                     anterior->proximoNo = aux->proximoNo;
                     free(aux);
                     return;

                }
             }else{
                   anterior = aux;
                   aux = aux->proximoNo;
             }
       }

  }
 }

//função que retorna um valor que estiver dentro de um no
int getValorNo(No **no) {
 if((*no) != NULL) //verifico se o endereço que recebe em meu cabeçalho, e um no valido, se for, retorno o valor dele
    return (*no)->information;
}

//função de receber um arquivo,e escrever nele a lista encadeada e depois renderizar em png
void geraArquivo(FILE **arquivo) {
 if((*arquivo) == NULL) {
    printf("Impossivel de Usar Arquivo\n");
    return;
 }
 No *escreve = controlador;
 while(escreve != NULL) {
       fprintf((*arquivo),"%d->%d;\n",escreve->information,getValorNo(&escreve->proximoNo));
       escreve = escreve->proximoNo;
 }
}
