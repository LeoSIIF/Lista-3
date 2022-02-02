#include <stdio.h>
#include <string.h>
#include<time.h>
#define MAX 100
typedef struct n{
	char mes[10];
	int ano;
}tnascimento;

typedef struct {
	char codigo[15], abate[1];
	float leite, alimento;
	struct n dataNasc;
}tgado;

anoatual = 2022;
int qtd=0; 

void cadastrar(tgado g[]){
	printf("\n ##Cadastro para Cabecas de gado##\n");
	printf("Codigo da cabeca de gado: ");
	fflush(stdin); // limpa o buffer do teclado
	gets(g[qtd].codigo);
	printf("Litros de leite por semana: ");
	fflush(stdin); 
	scanf("%f",&g[qtd].leite);
	printf("quantidade de alimento por semana:");
	scanf("%f",&g[qtd].alimento);
	printf("Data de nascimento");
	printf(" Mes (por extenso): ");
	fflush(stdin); // limpa o buffer do teclado
	gets(g[qtd].dataNasc.mes);
	printf("Ano(0000): ");
	scanf("%d",&g[qtd].dataNasc.ano);
	
	int idade = anoatual - g[qtd].dataNasc.ano;
	if (idade > 5 || g[qtd].leite < 40){
		g[qtd].abate[0] = 's';
	}
	else {
		g[qtd].abate[0] = 'n';
	}
	printf("Abate: %s", g[qtd].abate);
	qtd++; 
}

void mostragados(tgado gad[]){
	int i;
	if(qtd > 0) {
	printf("\n*** %d Cabeca(s) de gado cadastradas ***\n", qtd);
	for(i=0;i<qtd;i++){
		printf("Cabeca de gado %d\n",i+1);
		printf("Codigo: %s\n",gad[i].codigo);
		printf("Litros de leite por semana: %.1f\n",gad[i].leite);
		printf("Quantidade de alimento por semana: %.1f\n",gad[i].alimento);
		printf("Data de nascimento:%s/%d\n",gad[i].dataNasc.mes,gad[i].dataNasc.ano);
		printf("Abate: %s\n",gad[i].abate);
	}// fim for
} else{
	printf("**SEM CABECAS DE GADOS CADASTRADAS!**\n");
}
}
float producaoTotaldeLeite(tgado gad[]){
	int i;
	float total = 0;
	for(i=0;i<qtd;i++){
		total += gad[i].leite;
	}
	return total;
}
int menu(){
	int op;
	printf("^^^ Sistema de Cadastro de Cabecas de gado ^^^\n");
	printf("1- Adiciona cabeca de gado\n");
	printf("2- Mostrar cabecas de gado cadastradas\n");
	printf("3- Leite produzido por semana\n");
	printf("0- Sair\n");
	scanf("%d",&op);
	return op;
}
int main(){
	tgado g[MAX];
	int op;
	do{
		op = menu();
		switch(op){
			case 1: cadastrar(g);
				break;
			case 2: mostragados(g);
				break;
			case 3: printf("\n%.1f Litros de leite produzidos por semana\n",producaoTotaldeLeite(g));
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
