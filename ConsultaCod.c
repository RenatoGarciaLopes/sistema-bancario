/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: responsavel por consultar por ordem de codigo
*/


#include "Funcoes.h"

// Funcao pra mostrar os valores armazenados
int consultarCod(tipolista *l)
{

    int codigo;
    int teste;

    // Verifica se a lista está vazia (não há contas para consultar)
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
    do
    {
        tipoapontador p;

        tela_conta();

        gotoxy(30, 21);
        printf("7-Status da conta...: ");

        gotoxy(51, 7);
        scanf("%d", &codigo);

        p = pesquisa(l, codigo);

        // Verifica se a conta foi encontrada
        if (p == NULL)
        {
            gotoxy(8, 23);
            printf("Conta inexistente");
            getch();
            printf("                                               ");
        }
        else
        {

            amostra(p);

            getch();
        }

        gotoxy(8,23);
        printf("Deseja Consultar Outra conta? (1-SIM/2-NAO):  ");
        scanf("%d", &teste);

    } while (teste == 1);

    return 0;
}