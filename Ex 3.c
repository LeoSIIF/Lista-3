#include <stdio.h>
#include <string.h>
#define MAX 100
typedef struct alunos{
	int matAluno;
	char nome[40],aprovacao[20];
	float np1;
	float np2;
	float np3;
}tAlunos;
int qtd=0;

int addAluno(tAlunos a[]){
	if(qtd==MAX) // verificar se tem espaço
	  return 0;
	printf("Dados para cadastro de aluno\n");
	printf("Insira a Matricula do aluno: ");
	scanf("%d",&a[qtd].matAluno);
	printf("Nome do aluno: ");
	fflush(stdin); // limpa o buffer do teclado
	gets(a[qtd].nome);
	printf("Nota da primeira Prova: ");
	scanf("%f",&a[qtd].np1);
	printf("Nota da segunda Prova: ");
	scanf("%f",&a[qtd].np2);
	printf("Nota da terceira Prova: ");
	scanf("%f",&a[qtd].np3);
	float media = 0;
	int i = 0;
	for(i=0;i<qtd;i++){
	media = (a[i].np1 + a[i].np2 + a[i].np3 / 3);
	if ( media > 6 ){
		a[qtd].aprovacao[0] = 'Aprovado';
	}
	else {
		a[qtd].aprovacao[0] = 'Reprovado';
	}
}
	printf("O Aluno foi: %s\n", a[qtd].aprovacao);
	qtd++;
	return 1;  
}

void buscaAluno(tAlunos a[], char nomeBusca[40]){
	int i, existe=0;
	char aux[40];	
	for(i=0;i<qtd;i++){
		strcpy(aux,a[i].nome); 
	 if(strcmp( strupr(aux)   ,  strupr(nomeBusca)    )==0){ //strupr faz a string ficar em caixa alta
		printf("Aluno %d\n",i+1);
		printf("Nome: %s\n",a[i].nome);
		printf("Matricula do aluno: %d\n",a[i].matAluno);
		printf("Nota da Primeira prova: %.1f\n",a[i].np1);
		printf("Nota da Segunda prova: %.1f\n",a[i].np2);
		printf("Nota da Terceira prova: %.1f\n",a[i].np3);
		existe = 1;
	  }// fim if
	}// fim for
	if(!existe) // se nao existe
	   printf("Aluno nao encontrado :(\n");   
}
void mostraAlunos(tAlunos a[]){
	int i;
	printf("*** Alunos cadastrados ****\n");
	for(i=0;i<qtd;i++){
		printf("Aluno %d\n",i+1);
		printf("Nome: %s\n",a[i].nome);
		printf("Matricula do aluno: %d\n",a[i].matAluno);
		printf("Nota da Primeira prova: %.1f\n",a[i].np1);
		printf("Nota da Segunda prova: %.1f\n",a[i].np2);
		printf("Nota da Terceira prova: %.1f\n",a[i].np3);
	}// fim for
}
void salvarAlunos(tAlunos a[]){
	int i;
	FILE *arq;
	arq = fopen("alunos.txt","w"); // w = write
	fprintf(arq,"%d\n",qtd); // qtd é variável global da qtde de bandas cadastradas
	for(i=0;i<qtd;i++){
		fprintf(arq,"%d\n",a[i].matAluno);
		fprintf(arq,"%s\n",a[i].nome);
		fprintf(arq,"%f\n",a[i].np1);
		fprintf(arq,"%f\n",a[i].np2);
		fprintf(arq,"%f\n",a[i].np3);
	}
	printf("Dados salvos com sucesso :)\n");
	fclose(arq);
}
void carregaAlunos(tAlunos a[]){
	FILE *arq;
	int i;
	arq = fopen("alunos.txt","r"); // r = leitura
	if(arq==NULL){
		printf("Arquivo nao foi encontrado :(\n");
		return;
	}// fim if
	fscanf(arq,"%d",&qtd);
	printf("Carregando dados");
	for(i=0;i<qtd;i++){
		fscanf(arq,"%d",&a[i].matAluno);
		fscanf(arq,"%s",&a[i].nome);
		fscanf(arq,"%f",&a[i].np1);
		fscanf(arq,"%f",&a[i].np2);
		fscanf(arq,"%f",&a[i].np3);
		printf("...");// enfeite
		_sleep(500);// enfeite
	}// fim for
	fclose(arq);
	system("cls"); // enfeite
}

float maiormedia(tAlunos a[]){
	int i;
	float totalmedia = 0;
	for(i=0;i<qtd;i++){
		totalmedia += (a[i].np1 + a[i].np2 + a[i].np3 / 3);
	}
	return totalmedia;
}
//---------------------------
int menu(){
	int op;
	printf(" Sistema de Cadastro de Alunos \n");
	printf("1- Adiciona Aluno\n");
	printf("2- Mostra Alunos\n");
	printf("3- Busca Aluno por nome\n");
	printf("4- Aluno com maior media geral\n");
	printf("0- Sair\n");
	scanf("%d",&op);
	return op;
}
//------------------------------------------
int main(){
	tAlunos a[MAX];
	char busca[40];
	int op;
	int i;
	carregaAlunos(a);
	do{
		op = menu();
		switch(op){
			case 1: if(addAluno(a)==1)
			 			printf("Aluno adicionado :)\n");
			 		else
					 	printf("Limite de Alunos atingido :(\n");
				break;
			case 2: mostraAlunos(a);
				break;
			case 3: printf("Nome do Aluno para buscar:");
					fflush(stdin); gets(busca);
					buscaAluno(a,busca);
				break;
			case 4: for(i=0;i<qtd;i++){
			printf("\n%.1f Aluno %s com maior media geral \n",maiormedia(a),a[i].nome);
		}
				break;				
			case 0: salvarAlunos(a);
					printf("Saindo... \n");
				break;
			default: printf("Opcao invalida\n");			 	
		}// fim switch
		getch(); // esperar digitar uma tecla
		system("cls");
	}while(op!=0);	

	return 0;
}// fim main
