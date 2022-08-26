#include <stdio.h>
#define TAM 3

int main()
{
	void ler3Numeros(int vetor[]);

	int vetorMain[TAM];

	ler3Numeros(vetorMain);

	for (int i = 0; i < TAM; ++i)
	{
		printf("Posicao %i -> %i\n", i, vetorMain[i]);
	}

	return 0;
}

void ler3Numeros(int vetor[]){
	for (int i = 0; i < TAM; ++i)
	{
		scanf("%i", &vetor[i]);
	}
}

