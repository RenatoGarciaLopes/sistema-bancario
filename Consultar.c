/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: responsavel por consultar de maneira geral
*/


#include "Funcoes.h"

//Funcao pra mostrar os valores armazenados 
int consultar(tipolista *l)
{
    if (l->primeiro == NULL)
    {
        gotoxy(8, 23);
        printf("                                                       ");
        gotoxy(8, 23);
        printf("Nao ha nenhum valor para ler");
        getch();
        gotoxy(8, 23);
        printf("                                                       ");

        return 0;
    }

    tipoapontador p;

    p = l->primeiro;

    while (p != NULL)
    {
        amostra(p);

        p = p->prox;
        getch();
    }

    return 0;
}