#include <stdio.h>
#define tam 11

struct cadeia{
	char palavra[tam];
};

int main(){

	void ler4Palavras(struct cadeia x[]);

	struct cadeia item[4];

	ler4Palavras(item);

	for (int i = 0; i < 4; ++i)
	{
		printf("Palavra %i -> %s", i+1, item[i].palavra);
	}

	return 0;
}

void ler4Palavras(struct cadeia x[]){

	for (int i = 0; i < 4; ++i)
	{	
		printf("Insira a palavra %i -> ", i+1);
		fgets(x[i].palavra, tam, stdin);
	}
}



