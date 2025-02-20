/*
Autor.: Renato Garcia Lopes
Data..: 20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo.: tela de selaçao das opcoes relacionadas a consultas de contas
*/

#include "Funcoes.h"

void TelaConsulta(tipolista *l)
{

    int opcao = 0;

    do
    {

        tela();

        gotoxy(32, 3);
        printf("SISTEMA BANCARIO");

        gotoxy(29, 9);
        printf("1-Consuta geral");

        gotoxy(29, 11);
        printf("2-Consulta por codigo");

        gotoxy(29, 13);
        printf("3-Consulta por ordem de codigo");

        gotoxy(29, 15);
        printf("4-Consulta por ordem alfabetica");

        gotoxy(29, 17);
        printf("5-Retornar ao menu anterior");

        // Leitura de dados
        opcao = validarNum("Digite o numero da opcao desejada: ", 8, 23);

        // Verificando se a opcao escolhida eh valida
        if (opcao > 5 || opcao <= 0)
        {
            gotoxy(8, 23);
            printf("                                        ");
            gotoxy(8, 23);
            printf("Digite um valor valido (1 a 5)");
            getch();
            gotoxy(8, 23);
            printf("                               ");
        }

        // Trabalhando a opcao escolhida
        switch (opcao)
        {
        case 1:
            consultar(l);

            break;

        case 2:

            consultarCod(l);

            break;

        case 3:

            consultarAlfa(l, opcao);

            break;

        case 4:

            consultarAlfa(l, opcao);

            break;

        case 5:

            break;

        default:
            break;
        }

    } while (opcao != 5);

    gotoxy(37, 25);
}