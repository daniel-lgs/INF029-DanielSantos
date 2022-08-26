#include <stdio.h>

int main()
{
	int calculaFatorial(int numero);

	int numero, fatorial;

	printf("Digite um numero para calcular\n");
	scanf("%i", &numero);

	fatorial = calculaFatorial(numero);

	fatorial > 0 ? printf("Fatorial -> %i\n", fatorial) : printf("Nao foi possivel calcular o fatorial.\n");

	return 0;
}

int calculaFatorial(int numero){
	int fatorial;

	if (numero == 0)
	{
		fatorial = 1;
	}
	else if (numero > 0)
	{	
		fatorial = numero;
		for (int i = numero-1; i >= 1; --i)
		{
			fatorial *= i;
		}
	}
	else
	{
		fatorial = 0;
	}

	return fatorial;
}