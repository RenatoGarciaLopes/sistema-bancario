/*
Autor.: Renato Garcia Lopes
Data..: 20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo.: tela de seleçao das opcoes relacionadas a remoçao de contas
*/

#include "Funcoes.h"

void TelaRemover(TipoLista_movim *m, tipolista *l)
{

    int opcao;

    do
    {

        tela();

        gotoxy(29, 3);
        printf("REMOVER CONTAS");

        gotoxy(29, 8);
        printf("1 - Remover do inicio da lista ");

        gotoxy(29, 10);
        printf("2 - Remover do final da lista ");

        gotoxy(29, 12);
        printf("3 - Remover de alguma posicao da lista ");

        gotoxy(29, 14);
        printf("4 - Sair ");

        opcao = validarNum("Digite o numero da opcao desejada: ", 8, 23);

        if (opcao > 4 || opcao <= 0)
        {
            gotoxy(8, 23);
            printf("                                        ");
            gotoxy(8, 23);
            printf("Digite um valor valido (1 a 4)");
            getch();
            gotoxy(8, 23);
            printf("                               ");
        }

        switch (opcao)
        {
        case 1:
            remover(m, l, opcao);

            break;

        case 2:
            remover(m, l, opcao);

            break;

        case 3:
            remover(m, l, opcao);

            break;

        case 4:

            break;

        default:
            break;
        }

    } while (opcao != 4);

    gotoxy(37, 25);
}
