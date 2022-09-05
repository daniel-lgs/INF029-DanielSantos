#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define tam_struct 1
#define tam_nome 22
#define tam_nascimento 12
#define tam_cpf 14

//Declaração e definição da struct principal
struct cliente
{
	char nome[tam_nome];
	char dataDeNascimento[tam_nascimento];
	char cpf[tam_cpf]; 
	char sexo;
}dados[tam_struct];
//------------------------------------------

//Todas as funções do programa----------------------
struct cliente cadastrarCliente(struct cliente x[]);
void validarNome(char nome[]);
void validarNascimento(char nascimento[]);
void validarCPF(char cpf[]);
int validarSexo(char sexo[]);
int charParaInt(int num);
int limparString(char vetor[], int tam);
void limparBuffer(int liga);
//--------------------------------------------------

int main()
{
	setlocale(LC_ALL,"portuguese");
	
	printf("**************************************************\n");
	printf("Seja bem-vindo ao programa de cadastro de clientes\n");
	printf("**************************************************\n");

	cadastrarCliente(dados);

	for (int i = 0; i < tam_struct; ++i)
	{
		printf("Pessoa %i : \n", i+1);
		printf("Nome completo -> %s\n", dados[i].nome);
		printf("Data de nascimento -> %s\n", dados[i].dataDeNascimento);
		printf("CPF -> %s\n", dados[i].cpf);
		printf("Sexo -> %c\n", dados[i].sexo);
		printf("-------------------------------------------------\n");
	}

  printf("\nNa ausência de #, o cadastro foi realizado com sucesso !\n");
  
	printf("\nPressione qualquer tecla para continuar . . . ");
	getchar();
	return 0;
}

struct cliente cadastrarCliente(struct cliente x[])
{	
	//Iniciliza variaveis---------------------
	for (int i = 0; i < tam_struct; ++i)
	{
		strcpy(x[i].nome, "NULL");
		strcpy(x[i].dataDeNascimento, "NULL");
		strcpy(x[i].cpf, "NULL");
		x[i].sexo = '\0';
	}
	//----------------------------------------

	for (int i = 0; i < tam_struct; ++i)
	{
		printf("Digite o nome completo -> ");
		fgets(x[i].nome, tam_nome, stdin);
		validarNome(x[i].nome);
		limparBuffer(limparString(x[i].nome, tam_nome));

		printf("Digite data de nascimento -> ");
		fgets(x[i].dataDeNascimento, tam_nascimento, stdin);
		limparBuffer(limparString(x[i].dataDeNascimento, tam_nascimento));
		validarNascimento(x[i].dataDeNascimento);

		printf("Digite seu CPF -> ");
		fgets(x[i].cpf, tam_cpf, stdin);
		validarCPF(x[i].cpf);
		limparBuffer(limparString(x[i].cpf, tam_cpf));

		printf("Digite seu sexo (m/f) -> ");
		x[i].sexo = getchar();
		x[i].sexo == '\n' ? x[i].sexo = ' ' : limparBuffer(1);
		if(validarSexo(x[i].sexo) == 0){x[i].sexo = '#';}

		printf("-------------------------------------------------\n");
	}
}

void validarNome(char nome[])
{	
	int nomeValido = 0;

	for (int i = 0; i < tam_nome; ++i)
	{
		if (nome[i] == '\n')
		{
			nomeValido = 1;
		} 
	}

	if (nomeValido == 0)
	{
		for (int i = 0; i < tam_nome-1; ++i)
		{
			nome[i] = '#';
		}
	}
}

void validarNascimento(char nascimento[]){
	int valido;
	int dia, mes, ano;
	char erro[tam_nascimento] = "########";
	
	dia = (charParaInt(nascimento[0]) * 10) + (charParaInt(nascimento[1]));

	mes = (charParaInt(nascimento[3]) * 10) + (charParaInt(nascimento[4]));

	ano = (charParaInt(nascimento[6]) * 1000) + (charParaInt(nascimento[7]) * 100) +
          (charParaInt(nascimento[8]) * 10) + (charParaInt(nascimento[9]));

    //Verifica se os dias vão de 0 a 31, meses de 1 a 12 e ano de 1900 a 3000 
    if (dia > 0 && dia < 32)
    {
    	if (mes > 0 && mes < 13)
    	{
    		if (ano > 1899 && ano < 3001)
    		{
    			valido = 1;
    		}
    		else
    		{
    			valido = 0;
    		}
    	}
    	else
    	{
    		valido = 0;
    	}
    }
    else
    {
    	valido = 0;
    }
    //-----------------------------------------------------------------------

    //Verifica se foi digitado uma barra depois de dias, meses e anos
    if (nascimento[2] == '/')
    {
    	if (nascimento[5] == '/')
    	{
    		valido = 1;
    	}
    	else
    	{
    		valido = 0;
    	}
    }
    else
    {
    	valido = 0;
    }
    //---------------------------------------------------------------

    if (valido == 0)
    {
    	for (int i = 0; i < tam_nascimento; ++i)
		{
			nascimento[i] = erro[i];
		}
    }
}

void validarCPF(char cpf[])
{
	int cpfValido = 0, i = 0;
	
	if (cpf[11] == '\n')
	{
		cpfValido = 1;
		for (i = 0; i < 11; ++i)
		{
			if (cpf[i] >= 48 && cpf[i] <= 57)
			{
				cpfValido = 1;
			}
			else
			{
				cpfValido = 0;
				break;
			}
		}	
	}
	else
	{
		for (i = 0; i < tam_cpf; ++i)
		{
			if (cpf[i] == '\n')
			{	
				i = 100;
				for (int x = 0; x < tam_cpf-1; ++x)
				{
					cpf[x] = '#';
				}
				cpf[12] = '\n';
				cpf[13] = '\0';
				break;
			}
		}
		if (i != 100)
		{
			for (int x = 0; x < tam_cpf-1; ++x)
			{
				cpf[x] = '#';
			}
		}
	}
	if (cpfValido == 0)
	{
		for (i = 0; i < tam_cpf-1; ++i)
		{
			if (cpf[i] == '\n')
			{	
				i = 100;
				for (int x = 0; x < tam_cpf-1; ++x)
				{
					cpf[x] = '#';
				}
				cpf[12] = '\n';
				cpf[13] = '\0';
				break;
			}
		}
		if (i != 100)
		{
			for (int x = 0; x < tam_cpf-1; ++x)
			{
				cpf[x] = '#';
			}
		}
	}
}

int validarSexo(char sexo[]){
	if (sexo == 'M' || sexo == 'm' || sexo == 'F' || sexo == 'f' || sexo == 'O' || sexo == 'o')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int charParaInt(int num)
{
	switch(num)
	{
		case 48 :
			num = 0;
		break;

		case 49 :
			num = 1;
		break;

		case 50 :
			num = 2;
		break;

		case 51 :
			num = 3;
		break;

		case 52 :
			num = 4;
		break;

		case 53 :
			num = 5;
		break;

		case 54 :
			num = 6;
		break;

		case 55 :
			num = 7;
		break;

		case 56 :
			num = 8;
		break;

		case 57 :
			num = 9;
		break;
	}

	return num;
}

int limparString(char vetor[], int tam) //Tira qualquer \n de uma string
{
	for (int i = 0; i < tam; ++i)
	{
		if (vetor[i] == '\n')
		{	
			vetor[i] = '\0';
			return 0;
		}
	}
	return 1;
}

void limparBuffer(int liga) //Limpa o buffer até encontrar um \n
{
	char x = 'm';
	if(liga == 1)
	{
		while(x != '\n')
		{
			x = getchar();
		}
	}
}