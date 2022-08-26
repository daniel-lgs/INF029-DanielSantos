#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define tam 2

struct cliente{
	char nome[61];
	char dataDeNascimento[12];
	char cpf[14]; 
	char sexo;
} dados[tam];

struct cliente cadastrarCliente(struct cliente x[]);
void limparString(char vetor[]);
void limparBuffer(void);

int main(){
  setlocale(LC_ALL, "Portuguese");
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
		fgets(x[i].nome, 61, stdin);
		limparString(x[i].nome);

		printf("Digite data de nascimento -> ");
		fgets(x[i].dataDeNascimento, 12, stdin);
		limparString(x[i].dataDeNascimento);

		printf("Digite seu CPF -> ");
		fgets(x[i].cpf, 14, stdin);
		limparString(x[i].cpf);

		printf("Digite seu sexo (m/f) -> ");
		x[i].sexo = getchar();
		limparBuffer();
		printf("**************************************************\n");
	}
}

void limparBuffer(void){
	char c;
	while ((c = getchar()) != '\n' && c != EOF);
}

void limparString(char vetor[]){
	for (int i = 0; vetor[i] != '\0'; ++i)
	{
		if (vetor[i] == '\n')
		{
			vetor[i] = '\0';
		}
	}
}