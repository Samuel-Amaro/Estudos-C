/*implementa um metodo de remover um no da arvore*/
#include <stdio.h>
#include <stdlib.h>

//estrutura de um no da arvore
typedef struct No{
  int dado;
  struct No* direita;
  struct No* esquerda;
} No;

//cria a arvore
No* criarArvore(){
  return NULL;
}

//verifica se um no e vazio
int NoVazia(No* raiz){
  // 1 se a arvore for vazia
  // 0 caso contrario
  return raiz == NULL;
}

//vai mostrar a arvore no console
void exibirArvore(No* raiz){
  if(!NoVazia(raiz)){ //No nao vazio
    printf("%p<-%d(%p)->%p\n", raiz->esquerda, raiz->dado, raiz, raiz->direita);
    exibirArvore(raiz->esquerda);//esquerda (subNo)
    exibirArvore(raiz->direita); //direita (subNo)
  }
}

//inserir um dado na arvore
void inserirDado(No** raiz, int dado){
    //cria a arvore e adiciona dado a um no vazio
    if(*raiz == NULL){
      *raiz = (No*)malloc(sizeof(No));
      (*raiz)->esquerda = NULL;
      (*raiz)->direita = NULL;
      (*raiz)->dado = dado;
    } else {
        if(dado < (*raiz)->dado){ //dado menor? vai pra esquerda
            //percorrer subNo da esquerda
            inserirDado(&(*raiz)->esquerda, dado);
        }
        if(dado > (*raiz)->dado){ //dado maior? vai pra direita
            //percorrer subNo da direita
            inserirDado(&(*raiz)->direita, dado);
        }
    }
}

void gerarArquivoDot(FILE **arquivoDot,No *arvore);
int getValorNo(No **no);
void buscarDado(No *arvore,int dado,FILE **arquivoDot);
void removeNo(No **arvore,int dado);

void main(){
  No* raiz = criarArvore();
  inserirDado(&raiz,50);
  inserirDado(&raiz, 25);
  inserirDado(&raiz, 75);
  inserirDado(&raiz, 5);
  exibirArvore(raiz);
  removeNo(&raiz,5);
  exibirArvore(raiz);
  //abrindo arquivo
  FILE *arquivoDot = fopen("ArvoreBinaria.dot","w");
  if(arquivoDot == NULL)
     printf("Erro Na Abertura Do Arquivo!\n");
  //escrevendo no arquivo
  fputs("digraph",arquivoDot);
  fputc('{',arquivoDot);
  fputc('\n',arquivoDot);
  gerarArquivoDot(&arquivoDot,raiz);
  buscarDado(raiz,75,&arquivoDot);
  fputc('}',arquivoDot);
  fclose(arquivoDot);
  //comando para renderiza o arquivo .dot em um png
  system("dot -Tpng ArvoreBinaria.dot -o arvoreBinaria.png");
}

/*metodo que vai gerar uma arvore em um arquivo.dot e depois renderizar para um png*/
void gerarArquivoDot(FILE **arquivoDot,No *arvore)
{
 //verifico se o no atual existe, e na primeira execução verifica se a raiz existe
 if(arvore != NULL) {
    //verifico se a esquerda do no atual existe
    if(getValorNo(&arvore->esquerda) != 0) {
       //escrevendo diretamaente no arquivo para a função diagraph
       fprintf((*arquivoDot),"%d->%d;\n",arvore->dado,getValorNo(&arvore->esquerda));
       //verifico se a direita do no atual avalido existe
    }if(getValorNo(&arvore->direita) != 0) {
        //escrevendo diretamente no arquivo para a função diagraph
        fprintf((*arquivoDot),"%d->%d;\n",arvore->dado,getValorNo(&arvore->direita));
    }
    //apos verificar o no atual e seus filhos a esquerda e direita, eu passo os filhos para a propria função fazer o mesmo com os filhos, ate achar um no folha
    gerarArquivoDot(arquivoDot,arvore->direita);
    gerarArquivoDot(arquivoDot,arvore->esquerda);
 }
}


//verifica se um no não e nullo e retorna o seu valor
int getValorNo(No **no) {
 if((*no) != NULL)
    return (*no)->dado;
}

//metodo para buscar um dado na arvore apos achalo, colorir ele no arquivo .dot
void buscarDado(No *arvore,int dado,FILE **arquivoDot) {
 if(arquivoDot == NULL)
    printf("Arquivo Inexistente!\n");
 if(arvore != NULL){
    if(arvore->dado == dado) {
       int dadoAchado = arvore->dado;
       fprintf((*arquivoDot),"%d",dadoAchado);
       fprintf((*arquivoDot),"%s","[color = blue,style = filled];"); //vai colorir o dado achado em azul, no stilo preenchido
       fputc('\n',(*arquivoDot));
       return;
    }else{
         if(dado > arvore->dado) {
            buscarDado(arvore->direita,dado,arquivoDot);
         }else{
               buscarDado(arvore->esquerda,dado,arquivoDot);
         }
    }
 }
}

//função para remover um no qualquer da lista
void removeNo(No **arvore,int dado) {
 No *anterior;
 if((*arvore) != NULL) {
    if((*arvore)->dado == dado) {
       //PARA REMOVER UM NO FOLHA SEM FILHO
       if((*arvore)->esquerda == NULL && (*arvore)->direita == NULL) {
           free(arvore);
           (*arvore) = NULL;
           printf("Removido!\n");
           return;
       }
 }
}else{
        if(dado > (*arvore)->dado) {
            anterior = *arvore;
            removeNo(&(*arvore)->direita,dado);
         }if(dado < (*arvore)->dado){
             anterior = *arvore;
             removeNo(&(*arvore)->esquerda,dado);
         }
 }
}
