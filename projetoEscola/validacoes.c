#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define tamNome 102

char limparBuffer(int liga);

int validarEntrada(char vetor[], int tamanho) //Tamanho da string sempre deve ser +2 ('\n','/0')
{
	int stringEstourada = true;

	//Valida se o usuário não digitou nada (teclou apenas enter)
	if (vetor[0] == '\n')
	{
		for (int i = 0; i < tamanho; ++i)
		{
			vetor[i] = 0;
		}
		return false;
	}

	//Valida se a string foi estourada
	for (int i = 0; i < tamanho; ++i)
	{
		if (vetor[i] == '\n')
		{	
			stringEstourada = false;
			vetor[i] = 0;
			return true;
		}
	}

	if (stringEstourada == true)
	{
		limparBuffer(true);
		for (int i = 0; i < tamanho; ++i)
		{
			vetor[i] = 0;
		}
		return false;
	}
}

char limparBuffer(int liga)
{	
	char x = 'm';
	char primeiroChar;
	int aux = 0;
	if(liga == 1)
	{
		while(x != '\n')
		{
			x = getchar();
			if(aux == 0)
			{
				primeiroChar = x;
			} 
			aux++;
		}
	}
	return primeiroChar;
}

int validarNome(char vetor[], int tamanho) //Função depende de "validarString" para funcionar corretamente
{	
	int aux = 0;

	//Valida se a string tem pelo menos uma letra
	for (int i = 0; vetor[i] != '\0'; ++i)
	{
		if (vetor[i] >= 65 && vetor[i] <= 90 || vetor[i] >= 97 && vetor[i] <= 122)
		{
			++aux;
		}
	}
	if (aux == 0)
	{	
		for (int i = 0; i < tamanho; ++i)
		{
			vetor[i] = 0;
		}
		return false;
	}

	//Valida se a string tem algo que não seja letra ou espaço
	for (int i = 0; vetor[i] != '\0'; ++i)
	{
		if (vetor[i] >= 65 && vetor[i] <= 90 || vetor[i] >= 97 && vetor[i] <= 122 || vetor[i] == ' ')
		{
			//ATENCÃO - ESSA CONDICIONAL NÃO ABARCA LETRAS COM ACENTUAÇÃO
		}
		else
		{
			for (int i = 0; i < tamanho; ++i)
			{
				vetor[i] = 0;
			}
			return false;
		}
	}

	//Antes de retornar true, transforma toda letra em maiúscula para padronização
	for (int i = 0; vetor[i] != '\0'; ++i)
	{
		if (vetor[i] != ' ')
		{	
			if (vetor[i] >= 97 && vetor[i] <= 122)
			{
				vetor[i] = vetor[i] - 32;
			}
		}
	}
	return true;
}

int validarCPF(char vetor[], int tamanho)
{	
	int ehUmNumero;
	int cpf_equacao = 0;
	int num, aux = 0;

	for (int i = 0; i < 11; ++i)
	{
		if (vetor[i] >= 48 && vetor[i] <= 57)
		{
			ehUmNumero = true;
		}
		else
		{
			ehUmNumero = false;
			for (int i = 0; i < tamanho; ++i)
			{
				vetor[i] = 0;
			}
			return false;
		}
	}

	//Validacao do primeiro digito
	for (int i = 10; i >= 2; --i)
	{
		num = vetor[aux] - 48;
		cpf_equacao = cpf_equacao + (num * i);
		++aux;
	}
	
	cpf_equacao = (cpf_equacao * 10) % 11;

	if (cpf_equacao == 10) 
	{
		cpf_equacao = 0;
	}

	if (cpf_equacao != (vetor[9] - 48))
	{	
		for (int i = 0; i < tamanho; ++i)
		{
			vetor[i] = 0;
		}
		return false;
	}

	//Validacao do segundo digito
	cpf_equacao = 0, num = 0, aux = 0;

	for (int i = 11; i >= 2; --i)
	{
		num = vetor[aux] - 48;
		cpf_equacao = cpf_equacao + (num * i);
		++aux;
	}

	cpf_equacao = (cpf_equacao * 10) % 11;

	if (cpf_equacao == 10) 
	{
		cpf_equacao = 0;
	}

	if (cpf_equacao != (vetor[10] - 48))
	{	
		for (int i = 0; i < tamanho; ++i)
		{
			vetor[i] = 0;
		}
		return false;
	}

	//Validacao de invalidos conhecidos (numeros repetidos)
	for (int i = 0; i < 11; ++i)
	{
		if ((vetor[0] - 48) != (vetor[i] - 48))
		{	
			return true;
		} 
	}

	for (int i = 0; i < tamanho; ++i)
	{
		vetor[i] = 0;
	}
	return false;
}

int validarData(char vetor[], int tamanho)
{
	int ehNumero, ehBarra;

	int dia, mes, ano, ehBissexto;

	//Verifica se as duas barras existem e estão no lugar certo de uma data
	if (vetor[2] == '/' && vetor[5] == '/')
	{
		ehBarra = true;
	}
	else
	{	
		ehBarra = false;
		for (int i = 0; i < tamanho; ++i)
		{
			vetor[i] = 0;
		}
		return false;
	}

	//Verifica se tudo que nao for '/' é um número
	for (int i = 0; i < 10; ++i)
	{
		if (vetor[i] >= 48 && vetor[i] <= 57)
		{	
			ehNumero = true;
		}
		else
		{	
			ehNumero = false;
			for (int i = 0; i < tamanho; ++i)
			{
				vetor[i] = 0;
			}
			return false;
		}
		if (i == 1 || i == 4)
		{
			++i;
		}
	}
	
	//Captura os numeros em string e converte para inteiros
	dia = ((vetor[0] - 48) * 10) + (vetor[1] - 48);
	mes = ((vetor[3] - 48) * 10) + (vetor[4] - 48);
	ano = ((vetor[6] - 48) * 1000) + ((vetor[7] - 48) * 100) + ((vetor[8] - 48) * 10) + (vetor[9] - 48);

	//Valida se eh uma combinação de data real
	if (dia < 1 || dia > 31)
	{	
		for (int i = 0; i < tamanho; ++i)
		{
			vetor[i] = 0;
		}
		return false;
	}

	if (mes < 1 || mes > 12)
	{	
		for (int i = 0; i < tamanho; ++i)
		{
			vetor[i] = 0;
		}
		return false;
	}
	
	if (ano < 1900 || ano > 2100)
	{	
		for (int i = 0; i < tamanho; ++i)
		{
			vetor[i] = 0;
		}
		return false;
	}

	if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
	{
		if (dia > 30)
		{	
			for (int i = 0; i < tamanho; ++i)
			{
				vetor[i] = 0;
			}
			return false;
		}
	}

	if (ano % 4 == 0)
	{
		if (ano % 100 == 0)
		{
			if (ano % 400 == 0)
			{	
				ehBissexto = true;
			}
			else
			{	
				ehBissexto = false;
			}
		}
		else
		{	
			ehBissexto = true;
		}
	}
	else
	{	
		ehBissexto = false;
	}

	if (ehBissexto == true)
	{
		if (mes == 2 && dia > 29)
		{	
			for (int i = 0; i < tamanho; ++i)
			{
				vetor[i] = 0;
			}
			return false;
		}
	}
	else
	{
		if (mes == 2 && dia > 28)
		{	
			for (int i = 0; i < tamanho; ++i)
			{
				vetor[i] = 0;
			}
			return false;
		}
	}

	return true;
}

int validarMatricula(char vetor[], int tamanho)
{	
	int aux = 0;

	//Valida se a string tem pelo menos um numero
	for (int i = 0; vetor[i] != '\0'; ++i)
	{
		if (vetor[i] >= 48 && vetor[i] <= 57)
		{
			++aux;
		}
	}
	if (aux == 0)
	{	
		for (int i = 0; i < tamanho; ++i)
		{
			vetor[i] = 0;
		}
		return false;
	}

	//Valida se a matricula eh um numero ou um espaço
	for (int i = 0; vetor[i] != '\0'; ++i)
	{	
		if (vetor[i] >= 48 && vetor[i] <= 57 || vetor[i] == ' ')
		{
			//printf("Eh um numero ou um espaco\n");
		}
		else
		{	
			for (int i = 0; i < tamanho; ++i)
			{
				vetor[i] = 0;
			}
			return false;
		}
	}

	//Antes de retornar true, preenche todos os espaços em branco com 0
	for (int i = 0; i < tamanho-2; ++i)
	{
		if (vetor[i] == ' ')
		{
			vetor[i] = '0';
		}
	}
	
	return true;
}

int validarSexo(char vetor[], int tamanho)
{
	if (vetor[0] == 'm' || vetor[0] == 'M' || vetor[0] == 'f' || vetor[0] == 'F' || vetor[0] == 'o' || vetor[0] == 'O')
	{
		//Antes de retornar true, transforma toda letra em maiúscula para padronização
		if (vetor[0] >= 97 && vetor[0] <= 122)
		{
			vetor[0] = vetor[0] - 32;
		}
		return true;
	}
	
	else
	{	
		for (int i = 0; i < tamanho; ++i)
		{
			vetor[i] = 0;
		}
		return false;
	}
}

int validarCodigo(char vetor[], int tamanho)
{
	//Verifica se os 3 primeiros caracteres são letras
	for (int i = 0; i < 3; ++i)
	{
		if (vetor[i] >= 65 && vetor[i] <= 90 || vetor[i] >= 97 && vetor[i] <= 122)
		{
			//É uma letra
		}
		else
		{	
			for (int i = 0; i < tamanho; ++i)
			{
				vetor[i] = 0;
			}
			return false;
		}
	}

	//Verifica se os 3 últimos caracteres são números
	for (int i = 3; i < 6; ++i)
	{
		if (vetor[i] >= 48 && vetor[i] <= 57)
		{
			//É um número
		}
		else
		{
			for (int i = 0; i < tamanho; ++i)
			{
				vetor[i] = 0;
			}
			return false;
		}
	}

	//Antes de retornar true, transforma toda letra em maiúscula para padronização
	for (int i = 0; i < 3; ++i)
	{
		if (vetor[i] >= 97 && vetor[i] <= 122)
		{
			vetor[i] = vetor[i] - 32;
		}
	}

	return true;
}

int validarSemestre(char vetor[], int tamanho)
{	
	int ano;

	//Verifica se os 4 primeiros caracteres são numeros
	for (int i = 0; i < 4; ++i)
	{
		if (vetor[i] >= 48 && vetor[i] <= 57)
		{
			//É um número
		}
		else
		{
			for (int i = 0; i < tamanho; ++i)
			{
				vetor[i] = 0;
			}
			return false;
		}
	}

	//Verifica se é um ano válido (entre 1900 e 2100)
	ano = ((vetor[0] - 48) * 1000) + ((vetor[1] - 48) * 100) + ((vetor[2] - 48) * 10) + (vetor[3] - 48);

	if (ano >= 1900 && ano <= 2100)
	{
		//Ano verdadeiro
	}
	else
	{	
		for (int i = 0; i < tamanho; ++i)
		{
			vetor[i] = 0;
		}
		return false;
	}

	//Verifica se tem um ponto depois do ano
	if (vetor[4] == '.')
	{
		//Tem
	}
	else
	{
		for (int i = 0; i < tamanho; ++i)
		{
			vetor[i] = 0;
		}
		return false;
	}

	//Verifica se tem um semestre válido (1 ou 2) depois do ponto
	if (vetor[5] == '1')
	{
		return true;
	}
	else if (vetor[5] == '2')
	{
		return true;
	}
	else
	{
		for (int i = 0; i < tamanho; ++i)
		{
			vetor[i] = 0;
		}
		return false;
	}
}