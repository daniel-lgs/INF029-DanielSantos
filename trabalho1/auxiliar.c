#include "auxiliar.h"
#include <stdio.h> 

int validarData(int dia, int mes, int ano);
int calcularFinalDeUmMes(int dia, int mes, int ano);

int validarData(int dia, int mes, int ano)
{
    int anoBissexto;

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

int calcularFinalDeUmMes(int dia, int mes, int ano)
{
    dia = 0;

    for (int i = 0; i >= 0; i++)
    {
        if (validarData(dia + 1, mes, ano) == 1)
        {
            dia++;
        }
        else
        {
            break;
        }
    }
    
    return dia;
}