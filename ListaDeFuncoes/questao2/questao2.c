#include <stdio.h>

int main()
{
	int valor1, valor2, valor3;
	int subtrai(int valor1, int valor2, int valor3);

	printf("Digite 3 valores :\n");
	scanf("%i%i%i", &valor1, &valor2, &valor3);

	printf("Subtracao -> %i\n", subtrai(valor1, valor2, valor3));

	return 0;
}

int subtrai(int valor1, int valor2, int valor3)
{
	int subtracao = valor1 - valor2 - valor3;
	return subtracao;
}