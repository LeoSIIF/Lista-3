#include <stdio.h>
#include <string.h>
#define MAX 10
typedef struct livros{
	char titulo[40];
	char autor[40];
	int ano;
	int prateleira;
}tlivro;

int qtd=0; 

int menu(){
	int op;
	printf("*** Sistema de Cadastro de Livros ***\n");
	printf("1- Adiciona livro\n");
	printf("2- Mostra livros\n");
	printf("3- Busca livro\n");
	printf("4- Busca livro pelo ano\n");
	printf("0- Sair\n");
	scanf("%d",&op);
	return op;
}
//------------------------------------------
int addLivro(tlivro li[]){
	if(qtd==MAX) // verificar se tem espaço
	  return 0;
	printf("Dados para o livro\n");
	printf("Titulo:");
	fflush(stdin); // limpa o buffer do teclado
	gets(li[qtd].titulo);
	printf("Autor:");
	fflush(stdin); 
	gets(li[qtd].autor);
	printf("Ano:");
	scanf("%d",&li[qtd].ano);
	printf("Prateleira:");
	scanf("%d",&li[qtd].prateleira);
	qtd++;
	return 1;  
}
//--------------------------------------
void mostraLivros(tlivro li[]){
	int i;
	printf("*** Livros cadastrados ****\n");
	for(i=0;i<qtd;i++){
		printf("Livro %d\n",i+1);
		printf("Titulo:%s\n",li[i].titulo);
		printf("Autor:%s\n",li[i].autor);
		printf("Ano:%d\n",li[i].ano);
		printf("Prateleira:%d\n",li[i].prateleira);
		printf("---------------------------------------\n");
	}// fim for
}
//------------------------------------------
void buscaLivro(tlivro li[], char nomeBusca[40]){
	int i, existe=0;
	char aux[40];	
	for(i=0;i<qtd;i++){
		strcpy(aux,li[i].titulo);
	 if(strcmp( strupr(aux)   ,  strupr(nomeBusca)    )==0){ //strupr faz a string ficar em caixa alta
		printf("Livro %d\n",i+1);
		printf("Titulo:%s\n",li[i].titulo);
		printf("Autor:%s\n",li[i].autor);
		printf("Ano:%d\n",li[i].ano);
		printf("Prateleira:%d\n",li[i].prateleira);
		printf("---------------------------------------\n");
		existe = 1;
	  }// fim if
	}// fim for
	if(!existe) // se nao existe
	   printf("Livro nao encontrado :(\n");   
}
//------------------------------------------
void buscaLivroAno(tlivro li[], int buscaAno)
{
    int i, encontrou = 0;
    for (i = 0; i < qtd; i++)
    {
        if (buscaAno > li[i].ano);
        {
            printf("--------- Livro %i -----------\n", i+1);
            printf("Titulo:%s\nAutor:%s\nAno:%dPrateleira:%d\n", li[i].titulo, li[i].autor,li[i].ano, li[i].prateleira);
            printf("----------------------------------------\n");
            encontrou = 1;
            break;
        }
    }
    if(!encontrou)
    {
        printf("Livro nao encontrado... :(");
    }
}
//------------------------------------------
int main(){
	tlivro livros[MAX];
	char busca[40];
	int buscaAno;
	int op;

	do{
		op = menu();
		switch(op){
			case 1: if(addLivro(livros)==1)
			 			printf("Livro adicionado :)\n");
			 		else
					 	printf("Limite atingido :(\n");
				break;
			case 2: mostraLivros(livros);
				break;
			case 3: printf("Nome do livro para buscar:");
					fflush(stdin); gets(busca);
					buscaLivro(livros,busca);
				break;
			case 4: printf("Ano do livro para buscar:");
					scanf("%d",&buscaAno);
					buscaLivroAno(livros,buscaAno);
				break;
			case 0: 
					printf("Saindo... \n");
				break;
			default: printf("Opcao invalida\n");			 	
		}// fim switch
	 	getch(); // esperar digitar uma tecla
		//system("pause");
		system("cls");
	}while(op!=0);	

	return 0;
}// fim main
