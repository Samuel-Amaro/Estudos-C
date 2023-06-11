#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


//ESTRUTURA DE UMA PESSOA
typedef struct pessoa{
 char nome[30];
 int idade;
 char cpf[30];
 float peso;
 double salario;
 char profissao[100];
}Pessoa;

//ESTRUTURA DE UM NO NA LISTA ENCADEADA
typedef struct no{
 Pessoa p;
 struct no *proximaPessoa;
}No;

//CONTROLADOR DA REFERENCIA DAS ULTIMAS PESSOAS
No *controladorPessoas = NULL;

//ADICIONADO UMA PESSOA
void addPessoa();

//OBTENDO A ENTRADA DE DADOS DE UMA PESSOA SENDO POR REFERENCIA
void setPessoa(Pessoa *p);

//MOSTRANDO DADOS DE UMA PESSOA
void getLista();

void main()
{
setlocale(LC_ALL,"Portuguese");
for(int i = 0; i < 3; i += 1)
{
  addPessoa();
}
getLista(controladorPessoas);
}


//IMPLEMENTAÇÃO DAS FUNÇÕES
void setPessoa(Pessoa *p)
{
printf("----------------------------------------\n");
printf("Bem Vindo ao Cadastro De Profissionais!|\n");
printf("OBS: ao terminar de digitar seu dado,  |\n");
printf("Tecle Enter Para Passar Para o Proximo.|\n");
printf("----------------------------------------\n");
printf("Digite Seu Nome Abaixo:");
fflush(stdin);
scanf("%30[^\n]",&p->nome);
printf("Digite sua Idade(numero):");
fflush(stdin);
scanf("%d",&p->idade);
printf("Digite Seu CPF(SEPARADO POR PONTOS):");
fflush(stdin);
scanf("%30[^\n]",&p->cpf);
printf("Digite Seu Peso:");
fflush(stdin);
scanf("%f",&p->peso);
printf("Digite Sua Proffisão:");
fflush(stdin);
scanf("%100[^\n]",&p->profissao);
printf("Digite Seu Salario(numeros pode separar(.)):");
fflush(stdin);
scanf("%f",&p->salario);
printf("-----------------------------\n");
printf("Cadastro Obtido Com Sucesso!|\n");
printf("-----------------------------\n");
}


void addPessoa() {
 No *pessoaNova = (No*)malloc(sizeof(No));
 if(controladorPessoas == NULL) {
    setPessoa(&pessoaNova->p);
    pessoaNova->proximaPessoa = NULL;
    controladorPessoas = pessoaNova;
 }else{
      setPessoa(&pessoaNova->p);
      pessoaNova->proximaPessoa = controladorPessoas;
      controladorPessoas = pessoaNova;
 }
}

void getLista()
{
 if(controladorPessoas == NULL)
    printf("Lista Vazia! Sem Cadastro.\n");
 else{
     No *percorreLista = controladorPessoas;
     while(percorreLista->proximaPessoa != NULL) {
           printf("[E = %p|%s|P = %p]\n",percorreLista,percorreLista->p.nome,percorreLista->proximaPessoa);
           percorreLista = percorreLista->proximaPessoa;
     }

 }
}


