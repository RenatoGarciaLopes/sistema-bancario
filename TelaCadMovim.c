/*
Autor.: Renato Garcia Lopes
Data..: 20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo.: tela de selaçao das opcoes relacionadas ao cadastro de movimentaçoes
*/


#include "Funcoes.h"

void TelaCadMovim(TipoLista_movim *l)
{

    tela();

    imprimir_linha(14);

    if (l->ultimo != NULL)
    {
        gotoxy(29, 6);
        printf("Sequencia movimentacao.: %d", l->ultimo->conteudo.sequencial + 1);
    }
    else
    {
        gotoxy(29, 6);
        printf("Sequencia movimentacao.: %d", 0);
    }
    gotoxy(29, 7);
    printf("Codigo da conta........:  ");

    gotoxy(29, 8);
    printf("Agencia................: ");

    gotoxy(29, 9);
    printf("Numero da conta........: ");

    gotoxy(29, 10);
    printf("Tipo da conta..........: ");

    gotoxy(29, 11);
    printf("Saldo..................: ");

    gotoxy(29, 12);
    printf("Limite.................: ");

    gotoxy(29, 13);
    printf("Total Saldo + Limite...: ");




    gotoxy(29, 15);
    printf("1-Data da movimentacao.:  ");

    gotoxy(29, 16);
    printf("2-Tipo de movimentacao.: ");

    gotoxy(29, 17);
    printf("3-Favorecido...........: ");

    gotoxy(29, 18);
    printf("4-Valor movimentacao...: ");

    gotoxy(29, 19);
    printf("5-Novo saldo...........: ");




   



    
}