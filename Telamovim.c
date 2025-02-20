/*
Autor.: Renato Garcia Lopes
Data..: 20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo.: tela de seleçao das opcoes relacionadas a movimentaçoes
*/

#include "Funcoes.h"

void TelaMovim(TipoLista_movim *m, tipolista *l)
{

    int opcao = 0;

    do
    {

        tela();

        gotoxy(32, 3);
        printf("SISTEMA BANCARIO");

        gotoxy(29, 9);
        printf("1-Movimentacao de debito e credito");

        gotoxy(29, 11);
        printf("2-Transferencias entre contas bancarias");

        gotoxy(29, 13);
        printf("3-Consultas movimentacoes bancarias");

        gotoxy(29, 15);
        printf("4-Retornar ao menu anterior");

        // Leitura de dados

        gotoxy(8, 23);
        printf("                                        ");
        gotoxy(8, 23);
        printf("Digite o numero da opcao desejada: ");
        scanf("%d", &opcao);
        gotoxy(8, 23);
        printf("                               ");

        // Verificando se a opcao escolhida eh valida
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

        // Trabalhando a opcao escolhida
        switch (opcao)
        {
        case 1:
            movimCreDeb(m, l);

            break;

        case 2:

            TransConta(m, l);

            break;

        case 3:

            consultar_mov(l, m);

            break;

        case 4:

            break;

        default:
            break;
        }

    } while (opcao != 4);

    gotoxy(37, 25);
}