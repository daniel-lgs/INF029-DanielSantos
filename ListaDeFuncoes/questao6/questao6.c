#include <stdio.h>
#define tam 3

int main(){

	void ler3Letras(char vetor[]);

	char vetor[tam];

	ler3Letras(vetor);

	for (int i = 0; i < tam; ++i)
	{
		printf("Letra %i -> %c\n", i+1, vetor[i]);
	}

	return 0;
}

void ler3Letras(char vetor[]){

	for (int i = 0; i < tam; ++i)
	{
		printf("Digite a letra %i -> ", i+1);
		scanf("%c", &vetor[i]);
		getchar();
	}

}