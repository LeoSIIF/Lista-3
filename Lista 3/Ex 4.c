#include <stdio.h>
#include <string.h>
#define MAX 10
typedef struct {
	char nome[40];
	float potencia, horas;}telet;
int qtd=0;
 
void add(telet e[]){
	if(qtd==MAX){ // verificar se tem espaço
	  printf("Memoria cheia\n");
}
	printf("Dados para o eletrodomestico\n");
	printf("Nome do eletrodomestico: ");
	fflush(stdin); // limpa o buffer do teclado
	gets(e[qtd].nome);
	printf("Potencia: ");
	fflush(stdin); 
	scanf("%f",&e[qtd].potencia);
	printf("Tempo medio ativo por dia(em horas): ");
	scanf("%f",&e[qtd].horas);
	qtd++;
	printf(" Eletrodomestico adicionado :)\n");
}
void listar(telet e[]){
	int i;
	printf("** Eletrodomesticos cadastrados **\n");
	for(i=0;i<qtd;i++){
		printf("Eletrodomestico %d\n",i+1);
		printf("Nome:%s\n",e[i].nome);
		printf("Potencia: %.2f\n",e[i].potencia);
		printf("Tempo medio ativo por dia: %.2f hora(s)\n",e[i].horas);
	}// fim for
}
void buscaEletrodomestico(telet e[], char buscaNome[])
{
    int i, encontrou = 0;
    for (i = 0; i < qtd; i++)
    {
        if (strcmp(strupr(e[i].nome), strupr(buscaNome)))
        {
            printf("--------- Eletrodomestico %i -----------\n", i+1);
            printf("Nome:%s\nPotencia:%.2f\nTempo Medio ativo por dia:%.2f Horas\n", e[i].nome, e[i].potencia,e[i].horas);
            encontrou = 1;
            break;
        }
    }
    if(!encontrou)
    {
        printf("Eletrodomestico nao foi encontrado... :(");
    }
}
void consumoTotal(telet e[], float valorkwh){
	int i;
	float consumoDiariokw=0;
	for(i=0; i<qtd; i++){
		consumoDiariokw += e[i].potencia * e[i].horas;
	}
	printf("\nConsumo diario em KW: %.2f\nConsumo diario em R$:%.2f\n", consumoDiariokw,consumoDiariokw * valorkwh);
	printf("\nConsumo mensal em KW: %.2f\nConsumo mensal em R$:%.2f\n", consumoDiariokw * 30,(consumoDiariokw * 30)* valorkwh);
}
int menu(){
	int op;
	printf("* Sistema de Cadastro de Eletrodomestico *\n");
	printf("1- Adicionar Eletrodomestico\n");
	printf("2- Mostrar Eletrodomesticos\n");
	printf("3- Buscar Eletrodomestico por nome\n");
	printf("4- Consumo\n");
	printf("0- Sair\n");
	scanf("%d",&op);
	return op;
}
int main(){
	int op;
	telet e[MAX];
	char busca[40];
	float valorkwh;
	do{
		op = menu();
		switch(op){
			case 1: add(e);
				break;
			case 2: listar(e);
				break;
			case 3: printf("Nome do Eletrodomestico para buscar:");
					fflush(stdin); gets(busca);
					buscaEletrodomestico(e,busca);
				break;
			case 4: printf("Qual o valor para buscar: ");
					scanf("%f", &valorkwh);
					consumoTotal(e,valorkwh);
				break;			
			case 0: printf("Saindo... \n");
				break;
			default: printf("Opcao invalida\n");			 	
		}// fim switch
		getch(); // esperar digitar uma tecla
		system("cls");
	}while(op!=0);	
	return 0;
}// fim main
