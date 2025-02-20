/*
Autor.: Artur Ribeiro Bérgamo
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: Tela que será utilizada para demonstrar os codigos na hora da transação entre contas bancarias.
*/

#include "Funcoes.h"

void tela_transferencia()
{
    int i;

    tela();

    // Desenha uma linha vertical no meio da tela, da posição 5 à posição 16
    for (i = 5; i < 16; i++)
    {
        gotoxy(40, i);
        printf("%c", 186);
    }

    gotoxy(40, 4);
    printf("%c", 203);

    imprimir_linha(16);

    gotoxy(40, 16);
    printf("%c", 202);

    gotoxy(11, 5);
    printf("Conta Origem");

    gotoxy(51, 5);
    printf("Conta Destino");


    // Informações relacionadas à conta de origem
    gotoxy(10, 7);
    printf("Numero da conta: ");
    gotoxy(10, 8);
    printf("Banco..........: ");
    gotoxy(10, 9);
    printf("Agencia........: ");
    gotoxy(10, 10);
    printf("Tipo da conta..: ");
    gotoxy(10, 11);
    printf("Saldo..........: ");
    gotoxy(10, 12);
    printf("Limite.........: ");
    gotoxy(10, 13);
    printf("Saldo + Limite.: ");
    gotoxy(10, 14);
    printf("Novo Saldo.....: ");


    // Informações relacionadas à conta de destino
    gotoxy(50, 7);
    printf("Numero da conta: ");
    gotoxy(50, 8);
    printf("Banco..........: ");
    gotoxy(50, 9);
    printf("Agencia........: ");
    gotoxy(50, 10);
    printf("Tipo da conta..: ");
    gotoxy(50, 11);
    printf("Saldo..........: ");
    gotoxy(50, 12);
    printf("Limite.........: ");
    gotoxy(50, 13);
    printf("Saldo + Limite.: ");
    gotoxy(50, 14);
    printf("Novo Saldo.....: ");


    // Campos para o valor e a data da transferência
    gotoxy(27, 18);
    printf("Valor a ser transferido: ");
    gotoxy(27, 19);
    printf("Data da transferencia..: ");

    
}
