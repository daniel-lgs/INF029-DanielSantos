#include <stdio.h>
#include <stdbool.h>
#include "validacoes.h"
#include <string.h>

int escolherOpcao(int op_disponiveis)
{	
	int opcao_int = 0, casaDecimal = 1, tudoEhNumero;

	char opcao[9];

	int continuar = true, autenticacao, pedirEntrada = true;

	while(continuar == true)
	{	
		autenticacao = true;
		tudoEhNumero = true;
		casaDecimal = 1;
		opcao_int = 0;

		while(autenticacao == true)
		{
	
			printf("\nEscolha uma opcao valida > ");
			fgets(opcao, 9, stdin);
			
			if (validarEntrada(opcao, 9) == true)
			{
				for (int i = 0; opcao[i] != '\0'; ++i)
				{
					casaDecimal = casaDecimal * 10;
					if (opcao[i] != '0' && opcao[i] != '1' && opcao[i] != '2' && opcao[i] != '3' && opcao[i] != '4' && opcao[i] != '5' && opcao[i] != '6' && opcao[i] != '7' && opcao[i] != '8' && opcao[i] != '9')
					{	
						tudoEhNumero = false;
					}
				}

				if (tudoEhNumero == true)
				{
					if (opcao[0] != '0')
					{
						for (int i = 0; opcao[i] != '\0'; ++i)
						{
							casaDecimal = casaDecimal / 10;
							opcao_int = opcao_int + ((opcao[i] - 48) * casaDecimal);
						}
						if (opcao_int <= op_disponiveis)
						{
							return opcao_int;
						}
						else
						{	
							//printf("Opcao eh maior que disponiveis\n");
							autenticacao = false;
						}
					}
					else
					{	
						//printf("O primeiro digito foi 0\n");
						autenticacao = false;
					}
				}
				else
				{	
					//printf("Voce digitou algo que nao eh um numero positivo\n");
					autenticacao = false;
				}
			}
			else
			{	
				//printf("Voce nao digitou nada ou ultrapassou o limite de caracteres\n");
				autenticacao = false;
			}
		}
	}
}