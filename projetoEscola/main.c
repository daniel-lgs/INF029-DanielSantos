#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#include "validacoes.h"
#include "navegacao.h"

#define tam_alunos 5
#define tam_professores 5
#define tam_disciplinas 5

#define tam_nome 102
#define tam_cpf 13
#define tam_nascimento 12
#define tam_sexo 3
#define tam_codigo 8
#define tam_semestre 8
#define tam_registrado 2

struct pessoa
{
	char nome[tam_nome];
	char cpf[tam_cpf];
	char nascimento[tam_nascimento];
	char sexo[tam_sexo];
	char registrado[tam_registrado];
	int matricula;
};

struct pessoa aluno[tam_alunos];
struct pessoa professor[tam_professores];

struct semestreLetivo
{
	char nome[tam_nome];
	char codigo[tam_codigo];
	char semestre[tam_semestre];
	char professor[tam_nome];
	char registrado[tam_registrado];
};

struct semestreLetivo disciplina[tam_disciplinas];

// Funções de cadastro para aluno e professor (2 funções em 1)
struct pessoa inserirPessoa(struct pessoa alunoOuProf[], int tamanho);
struct pessoa excluirPessoa(struct pessoa alunoOuProf[], int tamanho);
struct pessoa atualizarPessoa(struct pessoa alunoOuProf[], int tamanho);

// Funções de cadastro para disciplina
struct semestreLetivo inserirDisciplina(struct semestreLetivo disciplina[], int tamanho);
struct semestreLetivo excluirDisciplina(struct semestreLetivo disciplina[], int tamanho);
struct semestreLetivo atualizarDisciplina(struct semestreLetivo disciplina[], int tamanho);

// Relatórios
// Relacionado ao aluno
struct pessoa listarPessoas(struct pessoa alunoOuProf[], int tamanho);

// Relacionado a disciplina
struct semestreLetivo listarDisciplinas(struct semestreLetivo disciplina[], int tamanho);

int main()
{
	int opcao, continuar = true;

	// Inicializa a struct pessoa aluno
	for (int i = 0; i < tam_alunos; ++i)
	{
		strcpy(aluno[i].nome, "NULL");
		strcpy(aluno[i].cpf, "NULL");
		strcpy(aluno[i].nascimento, "NULL");
		strcpy(aluno[i].sexo, "0");
		strcpy(aluno[i].registrado, "n");
	}

	// Inicializa a struct pessoa professor
	for (int i = 0; i < tam_professores; ++i)
	{
		strcpy(professor[i].nome, "NULL");
		strcpy(professor[i].cpf, "NULL");
		strcpy(professor[i].nascimento, "NULL");
		strcpy(professor[i].sexo, "0");
		strcpy(professor[i].registrado, "n");
	}

	// Inicializa matricula de alunos
	for (int i = 0; i < tam_alunos; ++i)
	{
		aluno[i].matricula = 1110;
		aluno[i].matricula += i;
	}

	// Inicializa matricula de professores
	for (int i = 0; i < tam_professores; ++i)
	{
		professor[i].matricula = 2220;
		professor[i].matricula += i;
	}

	// Inicializa a struct semestreLetivo disciplinas
	for (int i = 0; i < tam_disciplinas; ++i)
	{
		strcpy(disciplina[i].nome, "NULL");
		strcpy(disciplina[i].codigo, "NULL");
		strcpy(disciplina[i].semestre, "NULL");
		strcpy(disciplina[i].professor, "NULL");
		strcpy(disciplina[i].registrado, "n");
	}

	while (continuar == true)
	{
		printf("****************************************************************\n");
		printf("*       Bem-vindo ao sistema escolar || by Daniel Santos       *\n");
		printf("****************************************************************\n");
		printf("_____________________________");
		printf("\n 1 - Cadastro de alunos     \n 2 - Cadastro de professores\n 3 - Cadastro de disciplinas\n 4 - Relatorios\n 5 - Sair\n");
		printf("-----------------------------");
		switch (opcao = escolherOpcao(5))
		{
		case 1:
			system("clear||cls");
			printf("1 - Inserir aluno\n2 - Excluir aluno\n3 - Atualizar aluno\n");
			opcao = escolherOpcao(3);
			if (opcao == 1)
			{
				system("clear||cls");
				inserirPessoa(aluno, tam_alunos);
			}
			else if (opcao == 2)
			{
				system("clear||cls");
				excluirPessoa(aluno, tam_alunos);
			}
			else if (opcao == 3)
			{
				system("clear||cls");
				atualizarPessoa(aluno, tam_alunos);
			}
			break;
		case 2:
			system("clear||cls");
			printf("1 - Inserir professor\n2 - Excluir professor\n3 - Atualizar professor\n");
			opcao = escolherOpcao(3);
			if (opcao == 1)
			{
				system("clear||cls");
				inserirPessoa(professor, tam_professores);
			}
			else if (opcao == 2)
			{
				system("clear||cls");
				excluirPessoa(professor, tam_professores);
			}
			else if (opcao == 3)
			{
				system("clear||cls");
				atualizarPessoa(professor, tam_professores);
			}
			break;
		case 3:
			system("clear||cls");
			printf("1 - Inserir disciplina\n2 - Excluir disciplina\n3 - Atualizar disciplina\n4 - Inserir aluno em uma disciplina\n5 - Excluir aluno de uma disciplina\n");
			opcao = escolherOpcao(5);
			if (opcao == 1)
			{
				system("clear||cls");
				inserirDisciplina(disciplina, tam_disciplinas);
			}
			else if (opcao == 2)
			{
				system("clear||cls");
				excluirDisciplina(disciplina, tam_disciplinas);
			}
			else if (opcao == 3)
			{
				system("clear||cls");
				atualizarDisciplina(disciplina, tam_disciplinas);
			}
			else if (opcao == 4)
			{
				system("clear||cls");
				// funcao de inserir aluno em uma disciplina
			}
			else if (opcao == 5)
			{
				system("clear||cls");
				// funcao de excluir aluno de uma disciplina
			}
			break;
		case 4:
			system("clear||cls");
			printf("1 - Relacionado ao aluno\n2 - Relacionado ao professor\n3 - Relacionado a disciplina\n4 - Aniversariantes do mes\n5 - Buscar pessoas\n");
			opcao = escolherOpcao(5);

			if (opcao == 1) // Se relacionado ao aluno
			{
				system("clear||cls");
				printf("1 - Listar alunos\n2 - Listar alunos por sexo\n3 - Listar alunos ordenados por nome\n4 - Listar alunos ordenados por data de nascimento\n5 - Listar alunos matriculados em menos de 3 disciplinas\n");
				opcao = escolherOpcao(5);
				if (opcao == 1)
				{
					system("clear||cls");
					listarPessoas(aluno, tam_alunos);
				}
				else if (opcao == 2)
				{
					system("clear||cls");
					// Listar alunos por sexo
				}
				else if (opcao == 3)
				{
					system("clear||cls");
					// Listar alunos ordenados por nome
				}
				else if (opcao == 4)
				{
					system("clear||cls");
					// 4 - Listar alunos ordenados por data de nascimento
				}
				else if (opcao == 5)
				{
					system("clear||cls");
					// 5 - Listar alunos matriculados em menos de 3 disciplinas
				}
			}
			else if (opcao == 2) // Se relacionado ao professor
			{
				system("clear||cls");
				printf("1 - Listar professores\n2 - Listar professores por sexo\n3 - Listar professores ordenados por nome\n4 - Listar professores ordenados por data de nascimento\n");
				opcao = escolherOpcao(4);
				if (opcao == 1)
				{
					system("clear||cls");
					listarPessoas(professor, tam_professores);
				}
				else if (opcao == 2)
				{
					system("clear||cls");
					// Listar professores por sexo
				}
				else if (opcao == 3)
				{
					system("clear||cls");
					// Listar professores ordenados por nome
				}
				else if (opcao == 4)
				{
					system("clear||cls");
					// 4 - Listar professores ordenados por data de nascimento
				}
			}
			else if (opcao == 3) // Se relacionado a disciplina
			{
				system("clear||cls");
				printf("1 - Listar disciplinas (sem os alunos)\n2 - Listar disciplinas (com alunos)\n3 - Listar disciplinas que extrapolam 40 vagas\n");
				opcao = escolherOpcao(3);
				if (opcao == 1)
				{
					system("clear||cls");
					listarDisciplinas(disciplina, tam_disciplinas);
				}
				else if (opcao == 2)
				{
					system("clear||cls");
					// Listar disciplinas (com alunos)
				}
				else if (opcao == 3)
				{
					system("clear||cls");
					// Listar disciplinas que extrapolam 40 vagas + nome do professor
				}
			}
			else if (opcao == 4) // Aniversariantes do mes
			{
				system("clear||cls");
				/* code */
			}
			else if (opcao == 5) // Buscar pessoas
			{
				system("clear||cls");
				/* code */
			}
			break;
		case 5:
			continuar = false;
			break;
		}
	}

	return 0;
}

// Parte1 - Cadastros

struct pessoa inserirPessoa(struct pessoa alunoOuProf[], int tamanho)
{
	int repetir = true;

	for (int i = 0; i < tamanho; ++i)
	{
		while (alunoOuProf[i].registrado[0] == 's')
		{
			++i;
		}

		printf("------------------------------------------------------------\n");
		printf("                      MATRICULA %i                           \n", alunoOuProf[i].matricula);
		printf("------------------------------------------------------------\n");

		printf("Digite o nome completo > ");

		while (repetir == true)
		{
			fgets(alunoOuProf[i].nome, tam_nome, stdin);

			if (validarEntrada(alunoOuProf[i].nome, tam_nome) == true)
			{
				if (validarNome(alunoOuProf[i].nome, tam_nome) == true)
				{
					repetir = false;
				}
				else
				{
					printf("Digite um nome valido > ");
				}
			}
			else
			{
				printf("Digite um nome valido > ");
			}
		}

		repetir = true;

		printf("Digite o CPF > ");

		while (repetir == true)
		{
			fgets(alunoOuProf[i].cpf, tam_cpf, stdin);

			if (validarEntrada(alunoOuProf[i].cpf, tam_cpf) == true)
			{
				if (validarCPF(alunoOuProf[i].cpf, tam_cpf) == true)
				{
					repetir = false;
				}
				else
				{
					printf("Digite um CPF valido > ");
				}
			}
			else
			{
				printf("Digite um CPF valido > ");
			}
		}

		repetir = true;

		printf("Digite a data de nascimento > ");

		while (repetir == true)
		{
			fgets(alunoOuProf[i].nascimento, tam_nascimento, stdin);

			if (validarEntrada(alunoOuProf[i].nascimento, tam_nascimento) == true)
			{
				if (validarData(alunoOuProf[i].nascimento, tam_nascimento) == true)
				{
					repetir = false;
				}
				else
				{
					printf("Digite uma data valida > ");
				}
			}
			else
			{
				printf("Digite uma data valida > ");
			}
		}

		repetir = true;

		printf("Digite o sexo (m/f/o) > ");

		while (repetir == true)
		{
			fgets(alunoOuProf[i].sexo, tam_sexo, stdin);

			if (validarEntrada(alunoOuProf[i].sexo, tam_sexo) == true)
			{
				if (validarSexo(alunoOuProf[i].sexo, tam_sexo) == true)
				{
					repetir = false;
				}
				else
				{
					printf("Digite um sexo valido > ");
				}
			}
			else
			{
				printf("Digite um sexo valido > ");
			}
		}

		repetir = true;

		alunoOuProf[i].registrado[0] = 's';

		system("clear||cls");

		printf("1 - Continuar cadastrando\n2 - Voltar ao menu\n");
		if (escolherOpcao(2) == 2)
		{
			system("clear||cls");
			break;
		}

		system("clear||cls");
	}
}

struct pessoa excluirPessoa(struct pessoa alunoOuProf[], int tamanho)
{
	int repetir = true, ativo = true, matricula, encontrou = false, i;

	while (ativo == true)
	{
		printf("*** Busque a pessoa pela matricula ***\n");
		matricula = escolherOpcao(9999999);

		for (int x = 0; x < tamanho; ++x)
		{
			if (alunoOuProf[x].matricula == matricula && alunoOuProf[x].registrado[0] == 's')
			{
				encontrou = true;
				i = x;
			}
		}

		if (encontrou == true)
		{
			system("clear||cls");

			printf("-------------------------------------------------------------\n");
			printf("                      MATRICULA %i                           \n", alunoOuProf[i].matricula);
			printf("-------------------------------------------------------------\n");
			printf("Nome > %s\n", alunoOuProf[i].nome);
			printf("CPF > %s\n", alunoOuProf[i].cpf);
			printf("Data de nascimento > %s\n", alunoOuProf[i].nascimento);
			printf("Sexo > %s\n\n", alunoOuProf[i].sexo);

			while (repetir == true)
			{
				printf("Tem certeza que deseja excluir ?\n");
				printf("1 - Sim\n");
				printf("2 - Nao\n");
				if (escolherOpcao(2) == 1)
				{
					alunoOuProf[i].registrado[0] = 'n';
				}
				repetir = false;
			}

			repetir = true;

			system("clear||cls");

			printf("1 - Continuar excluindo\n2 - Voltar ao menu\n");
			if (escolherOpcao(2) == 2)
			{
				system("clear||cls");
				break;
			}

			system("clear||cls");
		}
		else
		{
			system("clear||cls");

			printf("Matricula nao encontrada\n");
			printf("1 - Continuar procurando\n2 - Voltar ao menu\n");
			if (escolherOpcao(2) == 2)
			{
				system("clear||cls");
				break;
			}
			system("clear||cls");
		}
	}
}

struct pessoa atualizarPessoa(struct pessoa alunoOuProf[], int tamanho)
{
	int repetir = true, ativo = true, matricula, encontrou = false, i;

	while (ativo == true)
	{
		printf("*** Busque a pessoa pela matricula ***\n");
		matricula = escolherOpcao(9999999);

		for (int x = 0; x < tamanho; ++x)
		{
			if (alunoOuProf[x].matricula == matricula && alunoOuProf[x].registrado[0] == 's')
			{
				encontrou = true;
				i = x;
			}
		}

		if (encontrou == true)
		{
			system("clear||cls");

			printf("------------------------------------------------------------\n");
			printf("                      MATRICULA %i                           \n", alunoOuProf[i].matricula);
			printf("------------------------------------------------------------\n");

			printf("Digite o nome completo > ");

			while (repetir == true)
			{
				fgets(alunoOuProf[i].nome, tam_nome, stdin);

				if (validarEntrada(alunoOuProf[i].nome, tam_nome) == true)
				{
					if (validarNome(alunoOuProf[i].nome, tam_nome) == true)
					{
						repetir = false;
					}
					else
					{
						printf("Digite um nome valido > ");
					}
				}
				else
				{
					printf("Digite um nome valido > ");
				}
			}

			repetir = true;

			printf("Digite o CPF > ");

			while (repetir == true)
			{
				fgets(alunoOuProf[i].cpf, tam_cpf, stdin);

				if (validarEntrada(alunoOuProf[i].cpf, tam_cpf) == true)
				{
					if (validarCPF(alunoOuProf[i].cpf, tam_cpf) == true)
					{
						repetir = false;
					}
					else
					{
						printf("Digite um CPF valido > ");
					}
				}
				else
				{
					printf("Digite um CPF valido > ");
				}
			}

			repetir = true;

			printf("Digite a data de nascimento > ");

			while (repetir == true)
			{
				fgets(alunoOuProf[i].nascimento, tam_nascimento, stdin);

				if (validarEntrada(alunoOuProf[i].nascimento, tam_nascimento) == true)
				{
					if (validarData(alunoOuProf[i].nascimento, tam_nascimento) == true)
					{
						repetir = false;
					}
					else
					{
						printf("Digite uma data valida > ");
					}
				}
				else
				{
					printf("Digite uma data valida > ");
				}
			}

			repetir = true;

			printf("Digite o sexo (m/f/o) > ");

			while (repetir == true)
			{
				fgets(alunoOuProf[i].sexo, tam_sexo, stdin);

				if (validarEntrada(alunoOuProf[i].sexo, tam_sexo) == true)
				{
					if (validarSexo(alunoOuProf[i].sexo, tam_sexo) == true)
					{
						repetir = false;
					}
					else
					{
						printf("Digite um sexo valido > ");
					}
				}
				else
				{
					printf("Digite um sexo valido > ");
				}
			}

			repetir = true;

			system("clear||cls");

			printf("1 - Continuar atualizando\n2 - Voltar ao menu\n");
			if (escolherOpcao(2) == 2)
			{
				system("clear||cls");
				break;
			}

			system("clear||cls");
		}
		else
		{
			system("clear||cls");

			printf("Matricula nao encontrada\n");
			printf("1 - Continuar procurando\n2 - Voltar ao menu\n");
			if (escolherOpcao(2) == 2)
			{
				system("clear||cls");
				break;
			}
			system("clear||cls");
		}
	}
}

struct semestreLetivo inserirDisciplina(struct semestreLetivo disciplina[], int tamanho)
{
	int repetir = true;

	for (int i = 0; i < tamanho; ++i)
	{
		while (disciplina[i].registrado[0] == 's')
		{
			++i;
		}

		printf("------------------------------------------------------------\n");
		printf("                      DISCIPLINA N%i                        \n", i + 1);
		printf("------------------------------------------------------------\n");

		printf("Digite o nome da disciplina > ");

		while (repetir == true)
		{
			fgets(disciplina[i].nome, tam_nome, stdin);

			if (validarEntrada(disciplina[i].nome, tam_nome) == true)
			{
				if (validarNome(disciplina[i].nome, tam_nome) == true)
				{
					repetir = false;
				}
				else
				{
					printf("Digite um nome valido > ");
				}
			}
			else
			{
				printf("Digite um nome valido > ");
			}
		}

		repetir = true;

		printf("Digite o codigo da disciplina > ");

		while (repetir == true)
		{
			fgets(disciplina[i].codigo, tam_codigo, stdin);

			if (validarEntrada(disciplina[i].codigo, tam_codigo) == true)
			{
				if (validarCodigo(disciplina[i].codigo, tam_codigo) == true)
				{
					repetir = false;
				}
				else
				{
					printf("Digite um codigo valido > ");
				}
			}
			else
			{
				printf("Digite um codigo valido > ");
			}
		}

		repetir = true;

		printf("Digite o semestre de aulas > ");

		while (repetir == true)
		{
			fgets(disciplina[i].semestre, tam_semestre, stdin);

			if (validarEntrada(disciplina[i].semestre, tam_semestre) == true)
			{
				if (validarSemestre(disciplina[i].semestre, tam_semestre) == true)
				{
					repetir = false;
				}
				else
				{
					printf("Digite um semestre valido > ");
				}
			}
			else
			{
				printf("Digite um semestre valido > ");
			}
		}

		repetir = true;

		printf("Digite o nome do professor > ");

		while (repetir == true)
		{
			fgets(disciplina[i].professor, tam_nome, stdin);

			if (validarEntrada(disciplina[i].professor, tam_nome) == true)
			{
				if (validarNome(disciplina[i].professor, tam_nome) == true)
				{
					repetir = false;
				}
				else
				{
					printf("Digite nome valido > ");
				}
			}
			else
			{
				printf("Digite um nome valido > ");
			}
		}

		repetir = true;

		disciplina[i].registrado[0] = 's';

		system("clear||cls");

		printf("1 - Continuar cadastrando\n2 - Voltar ao menu\n");
		if (escolherOpcao(2) == 2)
		{
			system("clear||cls");
			break;
		}

		system("clear||cls");
	}
}

struct semestreLetivo excluirDisciplina(struct semestreLetivo disciplina[], int tamanho)
{
	int encontrou = false, repetir = true, aux = 0;
	char busca[tam_codigo];

	while (repetir == true)
	{
		printf("*** Pesquise a disciplina pelo codigo ***\n");

		while (repetir == true)
		{
			printf("\nDigite uma opcao valida > ");
			fgets(busca, tam_codigo, stdin);

			if (validarEntrada(busca, tam_codigo) == true)
			{
				if (validarCodigo(busca, tam_codigo) == true)
				{
					for (int i = 0; i < tamanho; i++) // Faz uma busca para descobrir se o codigo digitado existe
					{
						aux = 0;

						for (int y = 0; disciplina[i].codigo[y] != '\0'; y++)
						{
							if (disciplina[i].codigo[y] == busca[y])
							{
								++aux;
							}
						}

						if (aux == 6 && disciplina[i].registrado[0] == 's')
						{
							encontrou = true;
							aux = i;
							break;
						}
					}

					system("clear||cls");
					repetir = false;
				}
			}
		}

		if (encontrou == false)
		{
			printf("Codigo nao encontrado\n");
			printf("1 - Continuar procurando\n2 - Voltar ao menu\n");
			if (escolherOpcao(2) == 1)
			{
				repetir = true;
				system("clear||cls");
			}
			else
			{
				system("clear||cls");
			}
		}
	}

	if (encontrou == true)
	{
		printf("------------------------------------------------------------\n");
		printf("                      DISCIPLINA N%i                        \n", aux + 1);
		printf("------------------------------------------------------------\n");
		printf("Nome > %s\n", disciplina[aux].nome);
		printf("Codigo > %s\n", disciplina[aux].codigo);
		printf("Semestre > %s\n", disciplina[aux].semestre);
		printf("Professor > %s\n\n", disciplina[aux].professor);

		repetir = true;

		while (repetir == true)
		{
			printf("Tem certeza que deseja excluir ?\n");
			printf("1 - Sim\n");
			printf("2 - Nao\n");
			if (escolherOpcao(2) == 1)
			{
				disciplina[aux].registrado[0] = 'n';
			}
			repetir = false;
		}

		system("clear||cls");
	}
}

struct semestreLetivo atualizarDisciplina(struct semestreLetivo disciplina[], int tamanho)
{
	int encontrou = false, repetir = true, aux = 0;
	char busca[tam_codigo];

	while (repetir == true)
	{
		printf("*** Pesquise a disciplina pelo codigo ***\n");

		while (repetir == true)
		{
			printf("\nDigite uma opcao valida > ");
			fgets(busca, tam_codigo, stdin);

			if (validarEntrada(busca, tam_codigo) == true)
			{
				if (validarCodigo(busca, tam_codigo) == true)
				{
					for (int i = 0; i < tamanho; i++) // Faz uma busca para descobrir se o codigo digitado existe
					{
						aux = 0;

						for (int y = 0; disciplina[i].codigo[y] != '\0'; y++)
						{
							if (disciplina[i].codigo[y] == busca[y])
							{
								++aux;
							}
						}

						if (aux == 6 && disciplina[i].registrado[0] == 's')
						{
							encontrou = true;
							aux = i;
							break;
						}
					}

					system("clear||cls");
					repetir = false;
				}
			}
		}

		if (encontrou == false)
		{
			printf("Codigo nao encontrado\n");
			printf("1 - Continuar procurando\n2 - Voltar ao menu\n");
			if (escolherOpcao(2) == 1)
			{
				repetir = true;
				system("clear||cls");
			}
			else
			{
				system("clear||cls");
			}
		}
	}

	if (encontrou == true)
	{
		repetir = true;

		printf("------------------------------------------------------------\n");
		printf("                      DISCIPLINA N%i                        \n", aux + 1);
		printf("------------------------------------------------------------\n");

		printf("Digite o nome da disciplina > ");

		while (repetir == true)
		{
			fgets(disciplina[aux].nome, tam_nome, stdin);

			if (validarEntrada(disciplina[aux].nome, tam_nome) == true)
			{
				if (validarNome(disciplina[aux].nome, tam_nome) == true)
				{
					repetir = false;
				}
				else
				{
					printf("Digite um nome valido > ");
				}
			}
			else
			{
				printf("Digite um nome valido > ");
			}
		}

		repetir = true;

		printf("Digite o codigo da disciplina > ");

		while (repetir == true)
		{
			fgets(disciplina[aux].codigo, tam_codigo, stdin);

			if (validarEntrada(disciplina[aux].codigo, tam_codigo) == true)
			{
				if (validarCodigo(disciplina[aux].codigo, tam_codigo) == true)
				{
					repetir = false;
				}
				else
				{
					printf("Digite um codigo valido > ");
				}
			}
			else
			{
				printf("Digite um codigo valido > ");
			}
		}

		repetir = true;

		printf("Digite o semestre de aulas > ");

		while (repetir == true)
		{
			fgets(disciplina[aux].semestre, tam_semestre, stdin);

			if (validarEntrada(disciplina[aux].semestre, tam_semestre) == true)
			{
				if (validarSemestre(disciplina[aux].semestre, tam_semestre) == true)
				{
					repetir = false;
				}
				else
				{
					printf("Digite um semestre valido > ");
				}
			}
			else
			{
				printf("Digite um semestre valido > ");
			}
		}

		repetir = true;

		printf("Digite o nome do professor > ");

		while (repetir == true)
		{
			fgets(disciplina[aux].professor, tam_nome, stdin);

			if (validarEntrada(disciplina[aux].professor, tam_nome) == true)
			{
				if (validarNome(disciplina[aux].professor, tam_nome) == true)
				{
					repetir = false;
				}
				else
				{
					printf("Digite nome valido > ");
				}
			}
			else
			{
				printf("Digite um nome valido > ");
			}
		}

		repetir = true;

		system("clear||cls");
	}
}

// Parte2 - Relatórios

// Relacionado ao aluno/professor
struct pessoa listarPessoas(struct pessoa alunoOuProf[], int tamanho)
{
	for (int i = 0; i < tamanho; ++i)
	{
		if (alunoOuProf[i].registrado[0] == 's')
		{
			printf("-------------------------------------------------------------\n");
			printf("                      MATRICULA %i                           \n", alunoOuProf[i].matricula);
			printf("-------------------------------------------------------------\n");
			printf("Nome > %s\n", alunoOuProf[i].nome);
			printf("CPF > %s\n", alunoOuProf[i].cpf);
			printf("Data de nascimento > %s\n", alunoOuProf[i].nascimento);
			printf("Sexo > %s\n\n", alunoOuProf[i].sexo);
		}
	}

	printf("1 - Voltar ao menu\n");
	if (escolherOpcao(1) == 1)
	{
		system("clear||cls");
	}
}


//Relacionado a disciplina
struct semestreLetivo listarDisciplinas(struct semestreLetivo disciplina[], int tamanho)
{
	for (int i = 0; i < tamanho; ++i)
	{
		if (disciplina[i].registrado[0] == 's')
		{
			printf("-------------------------------------------------------------\n");
			printf("                      DISCIPLINA N%i                           \n", i + 1);
			printf("-------------------------------------------------------------\n");
			printf("Nome > %s\n", disciplina[i].nome);
			printf("Codigo > %s\n", disciplina[i].codigo);
			printf("Semestre > %s\n", disciplina[i].semestre);
			printf("Professor > %s\n\n", disciplina[i].professor);
		}
	}

	printf("1 - Voltar ao menu\n");
	if (escolherOpcao(1) == 1)
	{
		system("clear||cls");
	}
}