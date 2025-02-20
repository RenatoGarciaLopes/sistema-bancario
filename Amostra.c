/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: responsavel por mostrar as informaçoes de uma lista conta
*/


#include "Funcoes.h"

void amostra(tipoapontador p)
{
    tela_conta();
    // Chama a função `tela_conta()` para exibir uma interface ou layout no terminal, relacionada às informações de conta.
    
    gotoxy(51, 7);
    printf("%d", p->conteudo.codigo);

    gotoxy(51, 9);
    printf("%s", p->conteudo.banco);

    gotoxy(51, 11);
    printf("%s", p->conteudo.agencia);

    gotoxy(51, 13);
    printf("%s", p->conteudo.numero_conta);

    gotoxy(51, 15);
    printf("%s", p->conteudo.tipo_conta);

    gotoxy(51, 17);
    printf("%.2lf", p->conteudo.vl_saldo);

    gotoxy(51, 19);
    printf("%.2lf", p->conteudo.vl_limite);

    gotoxy(30, 21);
    printf("7-Status da conta...: ");
    
    gotoxy(51, 21);
    printf("%s", p->conteudo.status);
}
