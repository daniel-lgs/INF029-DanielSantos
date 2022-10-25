#include <stdio.h>
#include <stdlib.h>

void mostrarPlacar(char matriz[3][3]);
void entradaComValidacao(char matriz[3][3], int vezDoJogador);
void verificarVitoria(char matriz[3][3], int vezDoJogador);

int main()
{
    char matriz[3][3];
    int final = 0;

    // Inicializa placar ------
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz[i][j] = '-';
        }
    }
    // ------------------------

    // Apresentação do jogo -----------------------
    printf("----------------------------------\n");
    printf("Jogo da velha | By : Daniel Santos\n");
    printf("----------------------------------\n");

    mostrarPlacar(matriz);

    printf("Tecle enter para iniciar o jogo...");
    if (getchar() != '\n')
    {
        while (getchar() != '\n')
        {
        }
    }
    system("clear||cls");
    // ------------------------------------------

    // Funcionamento do jogo
    while (final == 0)
    {
        mostrarPlacar(matriz);
        entradaComValidacao(matriz, 1);
        system("clear||cls");
        mostrarPlacar(matriz);
        entradaComValidacao(matriz, 2);
        system("clear||cls");
    }

    getchar();
    return 0;
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
                        if(vezDoJogador == 1){matriz[0][0] = 'X';} else {matriz[0][0] = 'O';}
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
                        if(vezDoJogador == 1){matriz[0][1] = 'X';} else {matriz[0][1] = 'O';}
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
                        if(vezDoJogador == 1){matriz[0][2] = 'X';} else {matriz[0][2] = 'O';}
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
                        if(vezDoJogador == 1){matriz[1][0] = 'X';} else {matriz[1][0] = 'O';}
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
                        if(vezDoJogador == 1){matriz[1][1] = 'X';} else {matriz[1][1] = 'O';}
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
                        if(vezDoJogador == 1){matriz[1][2] = 'X';} else {matriz[1][2] = 'O';}
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
                        if(vezDoJogador == 1){matriz[2][0] = 'X';} else {matriz[2][0] = 'O';}
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
                        if(vezDoJogador == 1){matriz[2][1] = 'X';} else {matriz[2][1] = 'O';}
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
                        if(vezDoJogador == 1){matriz[2][2] = 'X';} else {matriz[2][2] = 'O';}
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

void verificarVitoria(char matriz[3][3], int vezDoJogador)
{
   
}
