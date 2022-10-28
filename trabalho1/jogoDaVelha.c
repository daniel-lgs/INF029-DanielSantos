#include <stdio.h>
#include <stdlib.h>

int playGame(char matriz[3][3]);
void mostrarPlacar(char matriz[3][3]);
void entradaComValidacao(char matriz[3][3], int vezDoJogador);
int verificarVitoria(char matriz[3][3]);

int main()
{
    char matriz[3][3];

    while (1)
    {
        // Inicializa placar ----------
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matriz[i][j] = '-';
            }
        }
        // ----------------------------

        // Apresentação do jogo -----------------------
        printf("----------------------------------\n");
        printf("Jogo da velha | By : Daniel Santos\n");
        printf("----------------------------------\n");
        //---------------------------------------------

        playGame(matriz);

        // Confirmação de próximo jogo ---------------------------------------
        printf("Tecle enter para um novo jogo ou clique no X para fechar...");
        if (getchar() != '\n')
        {
            while (getchar() != '\n')
            {
            }
        }
        system("clear");
        // -------------------------------------------------------------------
    }
}

int playGame(char matriz[3][3])
{
    int resultado = 0;

    mostrarPlacar(matriz);
    while (1)
    {
        entradaComValidacao(matriz, 1);
        system("clear");
        mostrarPlacar(matriz);
        resultado = verificarVitoria(matriz);
        if (resultado == 1)
        {
            printf("--------------------\n");
            printf("O jogador 1 venceu !\n");
            printf("--------------------\n");
            return 0;
        }
        else if (resultado == 2)
        {
            printf("-------------------\n");
            printf("Empate, deu velha !\n");
            printf("-------------------\n");
            return 0;
        }
        entradaComValidacao(matriz, 2);
        system("clear");
        mostrarPlacar(matriz);
        resultado = verificarVitoria(matriz);
        if (resultado == 1)
        {
            printf("--------------------\n");
            printf("O jogador 2 venceu !\n");
            printf("--------------------\n");
            return 0;
        }
        else if (resultado == 2)
        {
            printf("-------------------\n");
            printf("Empate, deu velha !\n");
            printf("-------------------\n");
            return 0;
        }
    }
}

void mostrarPlacar(char matriz[3][3])
{
    printf("   1     2     3     \n");
    printf("      |     |        \n");
    printf("a  %c  |  %c  |  %c  \n", matriz[0][0], matriz[0][1], matriz[0][2]);
    printf(" _____|_____|_____   \n");
    printf("      |     |        \n");
    printf("b  %c  |  %c  |  %c  \n", matriz[1][0], matriz[1][1], matriz[1][2]);
    printf(" _____|_____|_____   \n");
    printf("      |     |        \n");
    printf("c  %c  |  %c  |  %c  \n", matriz[2][0], matriz[2][1], matriz[2][2]);
    printf("      |     |        \n");
}

void entradaComValidacao(char matriz[3][3], int vezDoJogador)
{
    char entrada[3];
    int entradaValida = 0, aux;

    while (entradaValida == 0)
    {
        aux = 0;

        if (vezDoJogador == 1)
        {
            printf("Vez do jogador 1 > ");
        }
        else
        {
            printf("Vez do jogador 2 > ");
        }

        fgets(entrada, 3, stdin);

        // Se tiver /n a entrada está errada
        for (int i = 0; entrada[i] != '\0'; i++)
        {
            if (entrada[i] == '\n')
            {
                aux = 1;
            }
        }

        // Se a entrada estiver certa
        if (aux == 0)
        {
            while (getchar() != '\n') // Limpa o buffer
            {
            }

            // Verifica se a string é uma coordenada válida
            if (entrada[0] == 'A' || entrada[0] == 'a')
            {
                if (entrada[1] == '1')
                {
                    if (matriz[0][0] == '-')
                    {
                        if (vezDoJogador == 1)
                        {
                            matriz[0][0] = 'X';
                        }
                        else
                        {
                            matriz[0][0] = 'O';
                        }
                        entradaValida = 1;
                    }
                    else
                    {
                        printf("Essa coordenada foi marcada anteriormente !\n");
                    }
                }
                else if (entrada[1] == '2')
                {
                    if (matriz[0][1] == '-')
                    {
                        if (vezDoJogador == 1)
                        {
                            matriz[0][1] = 'X';
                        }
                        else
                        {
                            matriz[0][1] = 'O';
                        }
                        entradaValida = 1;
                    }
                    else
                    {
                        printf("Essa coordenada foi marcada anteriormente !\n");
                    }
                }
                else if (entrada[1] == '3')
                {
                    if (matriz[0][2] == '-')
                    {
                        if (vezDoJogador == 1)
                        {
                            matriz[0][2] = 'X';
                        }
                        else
                        {
                            matriz[0][2] = 'O';
                        }
                        entradaValida = 1;
                    }
                    else
                    {
                        printf("Essa coordenada foi marcada anteriormente !\n");
                    }
                }
            }
            else if (entrada[0] == 'B' || entrada[0] == 'b')
            {
                if (entrada[1] == '1')
                {
                    if (matriz[1][0] == '-')
                    {
                        if (vezDoJogador == 1)
                        {
                            matriz[1][0] = 'X';
                        }
                        else
                        {
                            matriz[1][0] = 'O';
                        }
                        entradaValida = 1;
                    }
                    else
                    {
                        printf("Essa coordenada foi marcada anteriormente !\n");
                    }
                }
                else if (entrada[1] == '2')
                {
                    if (matriz[1][1] == '-')
                    {
                        if (vezDoJogador == 1)
                        {
                            matriz[1][1] = 'X';
                        }
                        else
                        {
                            matriz[1][1] = 'O';
                        }
                        entradaValida = 1;
                    }
                    else
                    {
                        printf("Essa coordenada foi marcada anteriormente !\n");
                    }
                }
                else if (entrada[1] == '3')
                {
                    if (matriz[1][2] == '-')
                    {
                        if (vezDoJogador == 1)
                        {
                            matriz[1][2] = 'X';
                        }
                        else
                        {
                            matriz[1][2] = 'O';
                        }
                        entradaValida = 1;
                    }
                    else
                    {
                        printf("Essa coordenada foi marcada anteriormente !\n");
                    }
                }
            }
            else if (entrada[0] == 'C' || entrada[0] == 'c')
            {
                if (entrada[1] == '1')
                {
                    if (matriz[2][0] == '-')
                    {
                        if (vezDoJogador == 1)
                        {
                            matriz[2][0] = 'X';
                        }
                        else
                        {
                            matriz[2][0] = 'O';
                        }
                        entradaValida = 1;
                    }
                    else
                    {
                        printf("Essa coordenada foi marcada anteriormente !\n");
                    }
                }
                else if (entrada[1] == '2')
                {
                    if (matriz[2][1] == '-')
                    {
                        if (vezDoJogador == 1)
                        {
                            matriz[2][1] = 'X';
                        }
                        else
                        {
                            matriz[2][1] = 'O';
                        }
                        entradaValida = 1;
                    }
                    else
                    {
                        printf("Essa coordenada foi marcada anteriormente !\n");
                    }
                }
                else if (entrada[1] == '3')
                {
                    if (matriz[2][2] == '-')
                    {
                        if (vezDoJogador == 1)
                        {
                            matriz[2][2] = 'X';
                        }
                        else
                        {
                            matriz[2][2] = 'O';
                        }
                        entradaValida = 1;
                    }
                    else
                    {
                        printf("Essa coordenada foi marcada anteriormente !\n");
                    }
                }
            }
        }
    }
}

int verificarVitoria(char matriz[3][3])
{
    int qtdXlinhas = 0, qtdOlinhas = 0, qtdXcolunas = 0, qtdOcolunas = 0;
    int qtdXdiagonal = 0, qtdOdiagonal = 0;
    int velha = 0; int aux = 0;

    // Verifica uma possível vitória em todas as colunas e linhas
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matriz[i][j] == 'X')
            {
                qtdXlinhas++;
            }
            else if (matriz[i][j] == 'O')
            {
                qtdOlinhas++;
            }
            if (matriz[j][i] == 'X')
            {
                qtdXcolunas++;
            }
            else if (matriz[j][i] == 'O')
            {
                qtdOcolunas++;
            }
        }
        if (qtdXlinhas == 3 || qtdOlinhas == 3 || qtdXcolunas == 3 || qtdOcolunas == 3)
        {
            return 1;
        }
        else
        {
            qtdXlinhas = 0;
            qtdOlinhas = 0;
            qtdXcolunas = 0;
            qtdOcolunas = 0;
        }
    }

    // Verifica uma possível vitória na diagonal principal
    for (int i = 0; i < 3; i++)
    {
        if (matriz[i][i] == 'X')
        {
            qtdXdiagonal++;
        }
        else if (matriz[i][i] == 'O')
        {
            qtdOdiagonal++;
        }
    }
    if (qtdXdiagonal == 3 || qtdOdiagonal == 3)
    {
        return 1;
    }
    else
    {
        qtdXdiagonal = 0;
        qtdOdiagonal = 0;
    }

    // Verifica uma possível vitória na diagonal secundária
    aux = 2;
    for (int i = 0; i < 3; i++)
    {
        if (matriz[i][aux] == 'X')
        {
            qtdXdiagonal++;
        }
        else if (matriz[i][aux] == 'O')
        {
            qtdOdiagonal++;
        }
        aux--;
    }
    if (qtdXdiagonal == 3 || qtdOdiagonal == 3)
    {
        return 1;
    }
    else
    {
        qtdXdiagonal = 0;
        qtdOdiagonal = 0;
        aux = 0;
    }

    // Identifica velha
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (matriz[i][j] != '-')
            {
                velha++;
            }
        }
    }
    if (velha == 9)
    {
        return 2;
    }
    
    return 0;
}
