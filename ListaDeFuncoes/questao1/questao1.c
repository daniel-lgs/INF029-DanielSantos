#include <stdio.h>
#include <stdlib.h>

int main()
{
	int valor1, valor2;

	int soma(int valor1, int valor2);

	printf("Digite dois valores : \n");
	scanf("%d%d", &valor1, &valor2);

	printf("Soma -> %d\n", soma(valor1, valor2));

	return 0;
}

int soma(int valor1, int valor2){
	int adicao = valor1 + valor2;
	return adicao;
}