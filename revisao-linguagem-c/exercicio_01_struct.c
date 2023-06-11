#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>



typedef struct horario{
 int minuto;
 int hora;
 int segundos;
}Horario;

void getHorario(Horario *horas);

typedef struct data{
int dia;
int mes;
int ano;
}Data;

void getData(Data *data);

typedef struct endereco{
 char rua[20];
 int numero_casa;
 char complemento[50];
 char referencia[50];
 char bairro[30];
 int quadra;
}Endereco;

void setEndereco(Endereco *e);

typedef struct pessoa{
 int idade;
 char nome[30];
 float peso;
 char cpf[30];
 struct endereco meuEndereco;
}Pessoa;

void setPessoa(Pessoa *p);

void getPessoa(Pessoa *p,Horario *h,Data *d);

void main()
{
setlocale(LC_ALL,"Portuguese");
//struct necessaria para receber a data e hora do sistema vindo de uma biblioteca
struct tm *data_hora_atual;
//variavel do tipo para armazenar os segundos
time_t segundos;
//obtendo tempo em segundos
time(&segundos);
//tem que converte os segundos para o tempo local do brasil
data_hora_atual = localtime(&segundos);

//TRABALHANDO COM AS STRUCTS PARA OBTER HORAS ATUAIS
Horario horaAtual;
horaAtual.minuto = data_hora_atual->tm_min;
horaAtual.segundos = data_hora_atual->tm_sec;
horaAtual.hora = data_hora_atual->tm_hour;
//getHorario(&horaAtual);

//TRABALHANDO COM AS STRUCT PARA OBTER DATA
Data dataAtual;
dataAtual.dia = data_hora_atual->tm_mday;
dataAtual.mes = data_hora_atual->tm_mon + 1;
dataAtual.ano = data_hora_atual->tm_year + 1900;
//getData(&dataAtual);

//ENTRADA DE DADOS/SAIDA COM STRUCTS
int resposta = 0, indice = 0;
Pessoa p[indice];
printf("---------------------------------------\n");
 printf("Bem Vindo Ao Programa de Cadastro!     |\n");
 printf("Essas são as nossas opções de Serviços |\n");
 printf("(1) - Cadastrar Alguem!                |\n");
 printf("(2) - Visualizar Cadastro Recem Feito! |\n");
 printf("(3) - Mostrar Pessoas Cadastradas e Qtd|\n");
 printf("(4) - sair                             |\n");
 printf("--------------------------------------\n");
 printf("RESPOSTA -> ");
 scanf("%d",&resposta);
while(resposta >= 1 && resposta <= 4) {
 switch(resposta) {
  Pessoa pNova;
 case 1:
  setPessoa(&pNova);
  p[indice] = pNova;
  break;
 case 2:
  getPessoa(&pNova,&horaAtual,&dataAtual);
  break;
 case 3:
  printf("Pessoas Cadastradas\n");
  printf("Total = %d\n",indice);
  printf("Nome das pessoas\n");
  for(int i = 0; i < indice; i += 1)
      printf("%s\n",p[i].nome);
  break;
 default:
  printf("Opção Invalida\n");
 }
 printf("---------------------------------------\n");
 printf("Bem Vindo Ao Programa de Cadastro!     |\n");
 printf("Essas são as nossas opções de Serviços |\n");
 printf("(1) - Cadastrar Alguem!                |\n");
 printf("(2) - Visualizar Cadastro Recem Feito! |\n");
 printf("(3) - Mostrar Pessoas Cadastradas e Qtd|\n");
 printf("(4) - sair                             |\n");
 printf("--------------------------------------\n");
 printf("RESPOSTA -> ");
 scanf("%d",&resposta);
 if(resposta == 1)
    indice += 1;
}
}

/*implementações de funções*/

void getHorario(Horario *horas) {
printf("---------------------------------\n");
printf("Horas Atuais Obtidas do Sistema |\n");
printf("Hora-----------------------%d   |\n",horas->hora);
printf("Minuto---------------------%d   |\n",horas->minuto);
printf("Segundos-------------------%d   |\n",horas->segundos);
printf("---------------------------------\n");
}


void getData(Data *data) {
printf("----------------------------------\n");
printf("Data Atual Obtida Do Sistema!    |\n");
printf("%d'\''\'/%d/%d                        |\n",data->dia,data->mes,data->ano);
printf("----------------------------------\n");
}

void setEndereco(Endereco *e) {
printf("Digite sua Rua:");
fflush(stdin);
scanf("%20[^\n]",&e->rua);
printf("Digite Numero da casa:");
scanf("%d",&e->numero_casa);
fflush(stdin);
printf("Digite Seu Bairro:");
scanf("%30[^\n]",&e->bairro);
printf("Digite o Complemento:");
fflush(stdin);
scanf("%50[^\n]",&e->complemento);
printf("Digite a referencia:");
fflush(stdin);
scanf("%50[^\n]",&e->referencia);
printf("Digite Sua Quadra em numeros:");
fflush(stdin);
scanf("%d",&e->quadra);
printf("-------------------------------\n");
printf("Ok Endereço Obtido Com Sucesso!\n");
printf("-------------------------------\n");
}

void setPessoa(Pessoa *p) {
printf("Digite sua idade:");
scanf("%d",&p->idade);
printf("Digite Seu Nome:");
fflush(stdin);
scanf("%30[^\n]",&p->nome);
printf("Digite Seu Peso Atual:");
scanf("%f",&p->peso);
printf("Digite Seu CPF Separar por pontos:");
fflush(stdin);
scanf("%30[^\n]",&p->cpf);
setEndereco(&p->meuEndereco);
}

void getPessoa(Pessoa *p,Horario *h,Data *d) {
printf("\n");
printf("------------------------------------\n");
printf("Cadastro Efetuado [%d:%d:%d]\n",h->hora,h->minuto,h->segundos);
printf("DATA: %d\/%d\/%d\/\n",d->dia,d->mes,d->ano);
printf("Seu Dados Estão Abaixo!\n");
printf("NOME: %s\n",p->nome);
printf("IDADE: %d\n",p->idade);
printf("PESO: %.2f\n",p->peso);
printf("CPF: %s\n",p->cpf);
printf("RUA: %s\n",p->meuEndereco.rua);
printf("BAIRRO: %s\n",p->meuEndereco.bairro);
printf("NUMERO: %d\n",p->meuEndereco.numero_casa);
printf("REFERENCIA: %s\n",p->meuEndereco.referencia);
printf("COMPLEMENTO: %s\n",p->meuEndereco.complemento);
printf("QUADRA: %d\n",p->meuEndereco.quadra);
printf("-------------------------------------\n");
printf("Visualização Encerrada!\n");
}
