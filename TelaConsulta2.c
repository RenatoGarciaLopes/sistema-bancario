/*
Autor.: Renato Garcia Lopes
Data..: 20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo.: tela de base das consultas das contas
*/
#include "Funcoes.h"

void TelaConsultaConta()
{
    
    tela();

    imprimir_linha(6);

    gotoxy(24, 3);
    printf("LISTA DE MOVIMENTACOES BANCARIAS");


    gotoxy(2, 5);
    printf("Cd Banco               Agenc Conta    Tipo Conta     Saldo       Limite     St");
   
   imprimir_linha(6);

    gotoxy(4, 6);
    printf(" ");

    gotoxy(24, 6);
    printf(" ");

    gotoxy(30, 6);
    printf(" ");

    gotoxy(39, 6);
    printf(" ");


    gotoxy(54, 6);
    printf(" ");


    gotoxy(66, 6);
    printf(" ");

    gotoxy(77, 6);
    printf(" ");

}