#include <stdio.h>
#define tam 4

struct inteiros{
	int vetor[tam];
};

int main(void){

	struct inteiros ler4Numeros(void);

	struct inteiros y = ler4Numeros();

	for (int i = 0; i < tam; ++i)
	{
		printf("Valor %i -> %i\n", i+1, y.vetor[i]);
	}

	return 0;
}

struct inteiros ler4Numeros(void){
	struct inteiros x;

	for (int i = 0; i < tam; ++i)
	{
		printf("Insira o valor %i -> ", i+1);
		scanf("%i", &x.vetor[i]);
	}

	return x;
}

