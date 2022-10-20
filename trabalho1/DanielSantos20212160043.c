//  ################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Daniel Leite Gonçalves dos Santos
//  email: danleitegoncalves@gmail.com
//  Matrícula: 20212160043
//  Semestre: 2022.2

//  Copyright © 2016 Renato Novais. All rights reserved.
//  Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include "DanielSantos20212160043.h" // Substitua pelo seu arquivo de header renomeado
#include "auxiliar.h"
#include <stdio.h>
#include <stdlib.h>

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */

int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
*/

int fatorial(int x)
{ // função utilizada para testes
    int i, fat = 1;

    for (i = x; i > 1; i--)
        fat = fat * i;

    return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

DataQuebrada quebraData(char data[])
{
    DataQuebrada dq;
    char sDia[3];
    char sMes[3];
    char sAno[5];
    int i;

    for (i = 0; data[i] != '/'; i++)
    {
        sDia[i] = data[i];
    }
    if (i == 1 || i == 2)
    {                   // testa se tem 1 ou dois digitos
        sDia[i] = '\0'; // coloca o barra zero no final
    }
    else
    {
        dq.valido = 0;
        return dq;
    }

    int j = i + 1; // anda 1 cada para pular a barra
    i = 0;

    for (; data[j] != '/'; j++)
    {
        sMes[i] = data[j];
        i++;
    }

    if (i == 1 || i == 2)
    {                   // testa se tem 1 ou dois digitos
        sMes[i] = '\0'; // coloca o barra zero no final
    }
    else
    {
        dq.valido = 0;
        return dq;
    }

    j = j + 1; // anda 1 cada para pular a barra
    i = 0;

    for (; data[j] != '\0'; j++)
    {
        sAno[i] = data[j];
        i++;
    }

    if (i == 2 || i == 4)
    {                   // testa se tem 2 ou 4 digitos
        sAno[i] = '\0'; // coloca o barra zero no final
    }
    else
    {
        dq.valido = 0;
        return dq;
    }

    dq.iDia = atoi(sDia);
    dq.iMes = atoi(sMes);
    dq.iAno = atoi(sAno);

    dq.valido = 1;

    return dq;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */

int q1(char data[])
{
    int dia = 0, mes = 0, ano = 0;

    int barras = 0, granDecimal = 1, anoBissexto = 0;

    // Conta as barras e transforma os números que são string em números int separados por dia, mês e ano
    for (int i = 0; data[i] != '\0'; i++)
    {
        if (data[i] >= 48 && data[i] <= 57)
        {
            if (barras == 0)
            {
                if (data[i + 1] == '/')
                {
                    for (int j = i; j >= 0; j--)
                    {
                        dia += (data[j] - 48) * granDecimal;
                        granDecimal *= 10;
                    }
                }
            }
            else if (barras == 1)
            {
                granDecimal = 1;
                if (data[i + 1] == '/')
                {
                    for (int j = i; data[j] != '/'; j--)
                    {
                        mes += (data[j] - 48) * granDecimal;
                        granDecimal *= 10;
                    }
                }
            }
            else if (barras == 2)
            {
                granDecimal = 1;
                if (data[i + 1] == '\0')
                {
                    for (int j = i; data[j] != '/'; j--)
                    {
                        ano += (data[j] - 48) * granDecimal;
                        granDecimal *= 10;
                    }
                }
            }
        }
        else
        {
            if (data[i] != '/')
            {
                return 0;
            }
            else
            {
                barras++;
            }
        }
    }

    // Valida se tem 2 barras
    if (barras != 2)
    {
        return 0;
    }

    // Verifica se é um ano válido e se é bissexto
    if (ano >= 1 && ano <= 3000)
    {
        if (ano % 4 == 0)
        {
            if (ano % 100 == 0)
            {
                if (ano % 400 == 0)
                {
                    anoBissexto = 1;
                }
                else
                {
                    anoBissexto = 0;
                }
            }
            else
            {
                anoBissexto = 1;
            }
        }
        else
        {
            anoBissexto = 0;
        }
    }
    else
    {
        return 0;
    }

    // Verifica se é um mês válido
    if (mes < 1 || mes > 12)
    {
        return 0;
    }

    // Verifica se é um dia válido
    if (dia >= 1 && dia <= 31)
    {
        // Verifica se o dia está certo em relação ao mês e ao ano
        if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
        {
            if (dia > 30)
            {
                return 0;
            }
        }
        if (anoBissexto == 1 && mes == 2 && dia > 29 || anoBissexto == 0 && mes == 2 && dia > 28)
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }

    return 1;
}

/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */

DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    // calcule os dados e armazene na struct a seguir
    DiasMesesAnos resultado;
    resultado.qtdAnos = 0;
    resultado.qtdMeses = 0;
    resultado.qtdDias = 0;

    // structs para armazenar as datas de forma quebrada em inteiros
    DataQuebrada inicial;
    DataQuebrada final;

    if (q1(datainicial) == 0)
    {
        resultado.retorno = 2;
        return resultado;
    }
    else if (q1(datafinal) == 0)
    {
        resultado.retorno = 3;
        return resultado;
    }
    else
    {
        // quebrando as datas
        inicial = quebraData(datainicial);
        final = quebraData(datafinal);

        // verifique se a data final não é menor que a data inicial
        if (inicial.iAno > final.iAno)
        {
            resultado.retorno = 4;
            return resultado;
        }
        else if (inicial.iAno == final.iAno)
        {
            if (inicial.iMes > final.iMes)
            {
                resultado.retorno = 4;
                return resultado;
            }
            else if (inicial.iMes == final.iMes)
            {
                if (inicial.iDia > final.iDia)
                {
                    resultado.retorno = 4;
                    return resultado;
                }
            }
        }

        // calcule a distancia entre as datas
        int contDias = 0, maxDoMesPassado = 0, i = 0;

        maxDoMesPassado = calcularFinalDeUmMes(inicial.iDia, inicial.iMes, inicial.iAno);

        while (i == 0)
        {
            if (inicial.iDia == final.iDia && inicial.iMes == final.iMes && inicial.iAno == final.iAno)
            {
                break;
            }

            if (validarData(inicial.iDia + 1, inicial.iMes, inicial.iAno) == 1)
            {
                inicial.iDia++;
                contDias++;
            }
            else
            {
                inicial.iDia = 1;

                contDias++;

                if (validarData(inicial.iDia, inicial.iMes + 1, inicial.iAno) == 1)
                {
                    inicial.iMes++;
                }
                else
                {
                    inicial.iMes = 1, inicial.iAno++;
                }
            }

            if (contDias == maxDoMesPassado)
            {
                maxDoMesPassado = calcularFinalDeUmMes(inicial.iDia, inicial.iMes, inicial.iAno);

                contDias = 0;
                resultado.qtdDias = 0;
                resultado.qtdMeses++;

                if (resultado.qtdMeses == 12)
                {
                    resultado.qtdMeses = 0;
                    resultado.qtdAnos++;
                }
            }
            else
            {
                resultado.qtdDias = contDias;
            }
        }

        // se tudo der certo
        resultado.retorno = 1;
        return resultado;
    }
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;

    for (int i = 0; texto[i] != '\0'; i++)
    {
        if (isCaseSensitive != 1)
        {
            if (texto[i] >= 65 && texto[i] <= 90)
            {
                if (texto[i] == c || texto[i] + 32 == c)
                {
                    qtdOcorrencias++;
                }
            }
            else if (texto[i] >= 97 && texto[i] <= 122)
            {
                if (texto[i] == c || texto[i] - 32 == c)
                {
                    qtdOcorrencias++;
                }
            }
        }
        else
        {
            if (texto[i] == c)
            {
                qtdOcorrencias++;
            }
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */

int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0, aux = 1;

    for (int i = 0; strTexto[i] != '\0'; i++)
    {
        for (int j = 0; strBusca[j] != '\0'; j++)
        {
            if (strTexto[i + j] == strBusca[j])
            {
                if (strBusca[j + 1] == '\0')
                {
                    qtdOcorrencias++;
                    posicoes[aux] = i + j + 1;
                    posicoes[aux-1] = posicoes[aux] - j;
                    aux += 2;
                }
            }
            else
            {
                break;
            }
        }
    }
    
    return qtdOcorrencias;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int grandeza = 1, numInvertido = 0;
    
    for (int i = 1; (num / i) / 10 != 0; i*=10)
    {
        grandeza *= 10;
    }
    while(grandeza != 0)
    {
        numInvertido += (num % 10) * grandeza;
        grandeza /= 10;
        num /= 10;
    }
    num = numInvertido;
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias;
    return qtdOcorrencias;
}