#include <stdio.h>
#include <string.h>

#define TAM 5

typedef struct
{
  int idade;
  char nome[10];
}Pessoa;

Pessoa item[TAM];

int main(){

  int media = 0;
  
  for(int i = 0; i < TAM; ++i)
  {
    printf("\nDigite as informacoes da pessoa %i :\n", i+1);
    printf("Nome -> ");
    fgets(item[i].nome, 10, stdin);
    printf("Idade -> ");
    scanf("%i", &item[i].idade);
    getchar();
  }

  //Limpa lixo das strings
  for (int i = 0; i < TAM; ++i)
  {
    for (int j = 0; j < 10; ++j)
    {
      if (item[i].nome[j] == 10)
      {
        item[i].nome[j] = 0;
      }
    }
  }
  //----------------------

  for(int i = 0; i < TAM; ++i)
  {
    media = media + item[i].idade;
  }

  media = media / TAM;

  printf("\nMedia geral de idade > %i", media);
  
  printf("\n\nPessoas com idade maior que a media :\n");
  for(int i = 0; i < TAM; ++i)
  {
    if(item[i].idade > media)
    {
      printf("%s - Idade > %i anos\n", item[i].nome, item[i].idade);
    }
  }

  return 0;
}