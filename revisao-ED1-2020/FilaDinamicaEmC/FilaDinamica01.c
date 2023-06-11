#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
/*
*FILA DINAMICA(E ALOCADA SOB DEMANDA, SEM TAMANHO DEFINIDO
*EXPÇICAÇÕES:
*INSERÇÕES OCORREM NO FINAL DA FILA
*EXCLUSÕES OCORREM NO INICIO DA FILA

*UTILIZA A MESMA LOGICA DE UMA FILA DE PESSOAS

*A FILA VAI SER COSTITIUDA DE ELEMENTOS
*CADA ELEMENTO VAI TER UMA REFERENCIA DE QUE E O PROXIMO NA FILA
*VAI TER CONTROLADORES DO INICIO E DO FIM DA FILA

*EX DE UMA FILA:

 INICIO -> | -> | -> | -> | -> | -> | -> FIM
*/

//ESTRUTURA E TIPO DE UM ELEMENTO QUE VAI NA FILA
typedef struct elemento{
 struct elemento *prox_elem;
 int dado;
}Elemento;

//ESTRUTURA DE UMA PILHA
typedef struct fila{
  Elemento *inicio_fila;
  Elemento *final_fila;
}Fila;

//função que vai criar uma pilha vazia e aloca ela
Fila* criaFila(void);

//função que verifica se uma fila esta vazia ou não
int filaVazia(Fila *fila);

//função que vai inserir elemntos na fila dinamicamente sob demanda
void inserirFila(Fila *fila,int dado);

//função que vai mostrar a fila
void getFila(Fila *fila);

void main(void)
{
Fila *fila = criaFila();
for(int i = 0; i < 10; i++)
 inserirFila(fila,i);
getFila(fila);
}

Fila* criaFila(void){
 Fila *novaFila = (Fila*)malloc(sizeof(Fila));
 if(novaFila == NULL)
    printf("Erro Ao cria Fila\n");
 else{
      novaFila->inicio_fila = NULL;
      novaFila->final_fila = NULL;
      return novaFila;
 }
}

int filaVazia(Fila *fila){
 return fila->inicio_fila == NULL;
}

void inserirFila(Fila *fila,int dado) {
 if(fila == NULL)
    printf("Fila Não Existe\n");
 else{
      Elemento *novoElem = (Elemento*)malloc(sizeof(Elemento));
      novoElem->dado = dado;
      novoElem->prox_elem = NULL;
      //verifica se o inicio da fila esta vazio,(isso e, vou armazenar um elemento no inicio da fila)
      if(filaVazia(fila)) {
        fila->inicio_fila = novoElem;
      }else{
           fila->final_fila->prox_elem = novoElem;
      }
      fila->final_fila = novoElem;
 }
}


void getFila(Fila *fila){
 if(fila == NULL)
    printf("Fila Vazia\n");
 else{
      Elemento *e = fila->inicio_fila;
      while(e != NULL) {
           printf("dado = %d | E %p | P = %p -> \t",e->dado,e,e->prox_elem);
           e = e->prox_elem;
      }
 }
}
