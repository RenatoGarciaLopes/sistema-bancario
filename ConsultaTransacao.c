/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: responsavel por consultar as movimentações
*/

#include "Funcoes.h"

int consultar_mov(tipolista *l, TipoLista_movim *m)
{
    tipoapontador aux; // Ponteiro auxiliar para contas
    tipoapontador_movim auxm; // Ponteiro auxiliar para movimentações
    reg_movimentos cont; // Estrutura para armazenar os dados das movimentações
    int conta = 0; // Contador para controlar o número de movimentações exibidas
    int codigo; // Código da conta a ser consultada
    int teste; // Variável auxiliar para controle de fluxo

    TelaConsultaG();

    do
    {
        do
        {
            gotoxy(10, 5);
            printf("                                                                     ");
            gotoxy(8, 23);
            printf("Digite \"0\" para sair");
            gotoxy(8, 23);
            printf("                        ");
            gotoxy(10, 5);
            scanf("%d", &codigo);

            if (codigo == 0)
            {

                gotoxy(8, 23);
                printf("Deseja realmente sair (Sim = 1/Nao = 2): ");
                scanf("%d", &teste);
                gotoxy(8, 23);
                printf("                                            ");
                gotoxy(8, 23);

                if (teste == 1)
                {
                    return 0;
                }
            }

            aux = pesquisa(l, codigo);

            if (aux == NULL && codigo != 0)
            {
                gotoxy(8, 23);
                printf("Conta nao escontrada ou inexistente");
                getch();
                gotoxy(8, 23);
                printf("                                            ");
                gotoxy(8, 23);
                printf("Deseja tentar novamente? (Sim = 1/Nao = 2): ");
                scanf("%d", &teste);
                gotoxy(8, 23);
                printf("                                              ");
                gotoxy(8, 23);

                if (teste == 2)
                {
                    return 0;
                }
            }

        } while (aux == NULL);

        gotoxy(2, 5);
        printf("Codigo: %d - %s   Agencia: %s Cta: %s    Tp: %s", aux->conteudo.codigo, aux->conteudo.banco, aux->conteudo.agencia, aux->conteudo.numero_conta, aux->conteudo.tipo_conta);

        auxm = m->primeiro;

        // percorre a lista contando
        while (auxm != NULL)
        {

            if (auxm->conteudo.codigo_conta == codigo)
            {
                gotoxy(2, conta + 9);
                printf("%-10s %-29s %-13s R$%9.2f R$%9.2f", auxm->conteudo.dt_movimento, auxm->conteudo.ds_favorecido, auxm->conteudo.tp_movimento, auxm->conteudo.vl_saldo);
                gotoxy(2, conta + 10);
                conta++;
            }

            if (conta == 13)
            {
                gotoxy(8, 23);
                printf("Pressione alguma tecla para continuar...");
                getch();
                gotoxy(8, 23);
                printf("                                           ");

                for (int j = 0; j < 13; j++)
                {
                    gotoxy(2, j +  9);
                    printf("                                                                             ");
                }

                conta = 0;
            }

            auxm = auxm->prox;
        }

        if (conta == 0)
        {
            printf("                                            ");
            gotoxy(8, 23);
            printf("A conta nao possui movimentacoes");
            getch();
            printf("                                            ");
            gotoxy(8, 23);
            printf("Deseja tentar novamente? (Sim = 1/Nao = 2): ");
            scanf("%d", &teste);

            gotoxy(8, 23);
            printf("                                             ");

            if (teste == 2)
            {
                return 0;
            }
        }

        printf("                                            ");
        gotoxy(8, 23);
        printf("Deseja consultar novamente? (Sim = 1/Nao = 2): ");
        scanf("%d", &teste);
        gotoxy(8, 23);
        printf("                                                  ");

    } while (teste == 1);


}