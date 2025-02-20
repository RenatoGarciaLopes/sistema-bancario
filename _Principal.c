/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: Programa principal
*/
#include "Funcoes.h"

int main()
{

    int opcao;

    tipolista l;
    TipoLista_movim m;

    m.primeiro = NULL;
    m.ultimo = NULL;

    l.primeiro = NULL;
    l.ultimo = NULL;

    lerArquivo(&l);
    lerArquivoMov(&m);

    do
    {
        // Construção da tela

        opcao = 0;

        tela();

        gotoxy(32, 3);
        printf("SISTEMA BANCARIO");


        gotoxy(29, 11);
        printf("1-Contas bancarias");

        gotoxy(29, 13);
        printf("2-Movimentacao bancaria");

        gotoxy(29, 15);
        printf("3-Sair do programa");


        // Leitura de dados
        opcao = validarNum("Digite o numero da opcao desejada: ", 8, 23);

        // Verificando se a opcao escolhida eh valida
        if (opcao > 3 || opcao <= 0)
        {
            gotoxy(8, 23);
            printf("                                        ");
            gotoxy(8, 23);
            printf("Digite um valor valido (1 a 3)");
            getch();
            gotoxy(8, 23);
            printf("                               ");
        }

        // Trabalhando a opcao escolhida
        switch (opcao)
        {
        case 1:
            TelaContas(&m, &l);
            gravarArquivo(&l);

            break;

        case 2:

            TelaMovim(&m, &l);
            gravarArquivoMov(&m);
            break;

        case 3:

            gravarArquivo(&l);
            gravarArquivoMov(&m);

            break;

        default:
            break;
        }

    } while (opcao != 3);

    gotoxy(37, 25);

    return 0;
}