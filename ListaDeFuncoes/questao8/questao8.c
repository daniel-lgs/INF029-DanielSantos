#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 1

struct cliente{
	char nome[22];
	char dataDeNascimento[12];
	char cpf[14]; 
	char sexo;
} dados[tam];

struct cliente cadastrarCliente(struct cliente x[]);
int limparString(char vetor[]);
void limparBuffer(int liga);

int main(){
	setlocale(LC_ALL,"portuguese");
	
	printf("**************************************************\n");
	printf("Seja bem-vindo ao programa de cadastro de clientes\n");
	printf("**************************************************\n");

	cadastrarCliente(dados);

	for (int i = 0; i < tam; ++i)
	{
		printf("Pessoa %i : \n", i+1);
		printf("Nome completo -> %s\n", dados[i].nome);
		printf("Data de nascimento -> %s\n", dados[i].dataDeNascimento);
		printf("CPF -> %s\n", dados[i].cpf);
		printf("Sexo -> %c\n", dados[i].sexo);
		printf("**************************************************\n");
		
	}

	printf("Pressione qualquer tecla para continuar . . . ");
	getchar();
	return 0;
}

struct cliente cadastrarCliente(struct cliente x[]){
	for (int i = 0; i < tam; ++i)
	{
		printf("Digite o nome completo -> ");
		fgets(x[i].nome, 22, stdin);
		limparBuffer(limparString(x[i].nome));

		printf("Digite data de nascimento -> ");
		fgets(x[i].dataDeNascimento, 12, stdin);
		limparBuffer(limparString(x[i].dataDeNascimento));

		printf("Digite seu CPF -> ");
		fgets(x[i].cpf, 14, stdin);
		limparBuffer(limparString(x[i].cpf));

		printf("Digite seu sexo (m/f) -> ");
		x[i].sexo = getchar();
		x[i].sexo == '\n' ? x[i].sexo = ' ' : limparBuffer(1);

		printf("**************************************************\n");
	}
}

int limparString(char vetor[]){
	for (int i = 0; vetor[i] != '\0'; ++i)
	{
		if (vetor[i] == '\n')
		{	
			vetor[i] = '\0';
			return 0;
		}
	}
	return 1;
}

void limparBuffer(int liga){
	char x = 'm';
	if(liga == 1)
	{
		while(x != '\n')
		{
			x = getchar();
		}
	}
}