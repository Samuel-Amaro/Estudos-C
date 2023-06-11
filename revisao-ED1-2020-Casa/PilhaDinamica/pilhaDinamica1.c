/*
*implementação de uma pilha dinamica
*DINAMICA: porque ela não tem tamanho definido, a cada mais crece mais e exigida
*a inserção de um novo item na pilha, a remoção de um item ja existente na pilha e, tudo feito pelo topo da pilha

*ex: pilha de pratos
       -
       -
       -
       -
       -
para inseir um novo prato se insere no topo, para retirar o segundo prato, tem que retirar todos acima dele antes para depois retirar o segundo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*um item que vai na pilha um no*/
typedef struct no{
 int dado;
 struct no *proximo; //pensando do primeiro adicionado ate o ultimo o topo
}No;

/*implementação de uma pilha*/
typedef struct pilha{
 No *topo;
}Pilha;

/*função que cria uma estrutura de uma pilha, uma pilha vazia sem nenhuma informação e dado*/
Pilha* criaPilha(void);

/*inserir elementos em uma pilha existente*/
Pilha* inserirPilha(Pilha *p,int dado);

/*função que vai imprimir uma pilha*/
void getPilha(Pilha *p);

/*função que verifica se uma pilha e vazia*/
bool pilhaVazia(Pilha *p);

/*remove o topo e atualiza para um proximo*/
void removeTopo(Pilha *p);

/*função que vai receber uma pilha e escrever ela em um arquivo e gera um png ao executar*/
void geraPilhaPng(Pilha *p,FILE **arquivoDotPilha);
//porque ponteiro para ponteiro ? porque vou ter que escrever no arquivo, assim preciso manipular a escrita o acesso dela via ponteiro para manter integridade da referencia e poder acessar esse nivel via ponteiro

//porque ponteiro para ponteiro ? porque vou passa um endereço de um ponteiro para a função, para acessar o valor do endereço que esta no ponteiro e necessario usar ponteiro para ponteiro
int getValor(No **p);

/*apos achar um dado existente na pilha vai colorir ele para ser identificado*/
void coloriBusca(Pilha *p,FILE **arquivo,int dado);

/*função que vai remover um dado qualquer da pilha, lembrando das regras de como remover um dado da pilha*/
void removeDado(Pilha *p,int dadoExcluir);

/*função que vai escrever o inicio da função da linguagem dot no arquivo*/
void auxArquivoInicio(FILE **arquivo);

/*função que escreve o final da função no arquivo*/
void auxArquivoFinal(FILE **arquivo);

void main()
{
Pilha *p1 = criaPilha(); //cria a pilha vazia
for(int i = 0; i < 10; i++) //adiciona dados na pilha
    inserirPilha(p1,i); //inserindo o indice do for na pilha para criar elementos la
getPilha(p1); //vai imprimir a pilha
removeDado(p1,5); //remove um dado da pilha
printf("Pilha Modificada\n");
getPilha(p1);
FILE *arquivoDotPilha = fopen("arquivoPilha.dot","w");//crieo um arquivo para escrever a pilha nele em formato da linguagem .dot, e abro ele tambem para ser manipulado
/*escrevendo no arquivo os dados da função dot*/
auxArquivoInicio(&arquivoDotPilha); //escreve no arquivo o inicio da função diagraph .dot
geraPilhaPng(p1,&arquivoDotPilha);//escreve no arquivo os dados da pilha em formato dot
coloriBusca(p1,&arquivoDotPilha,3);//busca um dado na pilha e indentifica ele
auxArquivoFinal(&arquivoDotPilha); //escreve o final da função diagraph .dot
fclose(arquivoDotPilha); //fecha arquivo e salva os dados do arquivo
system("dot -Tpng arquivoPilha.dot -o pilhaDinamica.png"); //renderiza um arquivo .dot em png
printf("Pronto Pilha Formada em png!\n");
}

//função que vai criar uma pilha, vai alocar ela, e deixar ela vazia, e retorna ela
Pilha* criaPilha(void)
{
 Pilha *novaPilha;
 novaPilha = (Pilha*)malloc(sizeof(Pilha));
 novaPilha->topo = NULL;
 return novaPilha;
}

/*função que vai receber uma pilha existente, e um dado, para inserir na pilha*/
Pilha* inserirPilha(Pilha *p,int dado) {
 if(p == NULL)
    printf("Pilha Vazia!\n");
 else{
     //aloco um novo elemento da pilha
     No *aux = (No*)malloc(sizeof(No));
     aux->dado = dado;
     aux->proximo = p->topo;//faco o novo elemento ter como seu anterior o topo, vai exergar o topo
     p->topo = aux;//e esse novo cara vai ser o meu topo, vai ser o ultimo elemento
     return p;
 }
}

/*imprime uma pilha*/
void getPilha(Pilha *p)
{
 if(p->topo == NULL)
    printf("Lista Vazia!\n");
 else{
     No *aux = p->topo;
     while(aux != NULL) {
          printf("%d | E = %p | A = %p\n",aux->dado,aux,aux->proximo);
          aux = aux->proximo;
     }
 }
}

bool pilhaVazia(Pilha *p)
{
 if(p->topo == NULL)
    return true;
 else
     return false;
}

/*remove o topo e atualiza para um proximo*/
void removeTopo(Pilha *p) {
 No *aux = p->topo;
 if(aux != NULL) {
    No *aux2 = p->topo->proximo;
    free(aux);
    p->topo = aux2;
 }else{
      printf("Vou Remover Que Topo?\n");
 }
}

int getValor(No **p) {
 if((*p) != NULL)
    return (*p)->dado;
  return 0;
}

/*função que vai receber uma pilha e escrever ela em um arquivo e gera um png ao executar*/
void geraPilhaPng(Pilha *p,FILE **arquivoDotPilha){
 if(p->topo == NULL) {
    printf("Não Tem como Forma Png com essa pilha\n");
    return;
 }
 if(arquivoDotPilha == NULL)
    return;
 No *percorrePilha1 = p->topo;
 while(percorrePilha1 != NULL) {
      //função que vai escevendo no arquivo os dados da pilha so que em formato dot
      fprintf((*arquivoDotPilha),"%d->%d;\n",percorrePilha1->dado,getValor(&percorrePilha1->proximo));
      percorrePilha1 = percorrePilha1->proximo;
 }
}

/*FUNÇÃO QUE COLORI UMA DADO NO ARQUIVO SE ACHAR ELE, E NO PNG FICA DESTACADO E IDENTIFICADO*/
void coloriBusca(Pilha *p,FILE **arquivo,int dado) {
 if(p->topo == NULL) {
    printf("Sem Pilha Para Haver Busca!\n");
    return;
 }
 if((*arquivo) == NULL) {
    printf("Sem Condição para Colorir!\n");
    return;
 }
 No *percorrePilha = p->topo;
 while(percorrePilha != NULL) {
       if(getValor(&percorrePilha) == dado) {
         fprintf((*arquivo),"%d",getValor(&percorrePilha));
         fprintf((*arquivo),"%s","[shape = box,color = blue,style = filled];"); //vai colorir o dado achado em azul, no stilo preenchido
         fputc('\n',(*arquivo));
       }
       percorrePilha = percorrePilha->proximo;
 }
}

/*função que vai remover um dado qualquer da pilha, lembrando das regras de como remover um dado da pilha*/
void removeDado(Pilha *p, int dadoExcluir) {
 if(p->topo != NULL) {
    No *no = p->topo,*aux = NULL,*aux1 = NULL;
    while(no != NULL) {
          //removendo o que quero
          if(getValor(&no) == dadoExcluir) {
             aux1 = no->proximo;
             free(no);
             no = aux1;
             p->topo = aux1;
             return;
          }//removendo oque esta antes do que quero(os topos anteriores da pilha)
               aux = no->proximo;
               free(no);
               no = aux;
    }
 }
}

/*função que escreve o inicio da função diagraph no arquivo para a pilha dinamica em formato dot*/
void auxArquivoInicio(FILE **arquivo) {
 if((*arquivo) != NULL) {
    fputs("digraph",(*arquivo));
    fputc('{',(*arquivo));
    fputc('\n',(*arquivo));
 }
}

/*função que escreve o final da função no arquivo*/
void auxArquivoFinal(FILE **arquivo) {
 if((*arquivo) != NULL) {
    fputc('}',(*arquivo));
    fputc('\n',(*arquivo));
 }
}
