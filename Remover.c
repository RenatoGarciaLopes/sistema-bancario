/*
Autor.: Artur Ribeiro Bérgamo
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: Logica que será utilizada nas opções de remoção de contas.
*/

#include "Funcoes.h" 

int remover(TipoLista_movim *m, tipolista *l, int opc)
{
    tipoapontador p;
    tipoapontador aux;
    int teste;
    int cont;
    int pos;
    int qtd;

     if (opc == 1)
        {
            gotoxy(32, 4);
            printf("REMOVER NO INICIO");
        }
        else if (opc == 2)
        {
            gotoxy(32, 4);
            printf("REMOVER NO FINAL");
        }
        else if (opc == 3)
        {
            gotoxy(31, 4);
            printf("REMOVER NA POSICAO");
        }

    // verifica se ha valor pra remover
    if (l->primeiro == NULL)
    {
        gotoxy(8, 23);
        printf("                                                       ");
        gotoxy(8, 23);
        printf("Nao ha nenhum valor para remover");
        getch();
        gotoxy(8, 23);
        printf("                                                       ");

        return 0;
    }

    // remover no inicio
    if (opc == 1)
    {

        amostra(l->primeiro);

        // verifica se realmente ira excluir
        gotoxy(8, 23);
        printf("                                        ");
        gotoxy(8, 23);
        printf("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ");
        scanf("%d", &teste);
        gotoxy(8, 23);
        printf("                               ");

        if (pesquisaMovim(m, l->primeiro->conteudo.codigo) != NULL)
        {
            gotoxy(8, 23);
            printf("Conta Bancaria com Movimentacoes Bancarias. Nao pode ser removida.");
            getch();
            gotoxy(8, 23);
            printf("                                                                    ");
            gotoxy(8, 23);
            printf("Deseja somente inativar a conta?(Sim = 1/Nao = 0)");
            scanf("%d", &teste);

            if (teste == 1)
            {
                strcpy(l->primeiro->conteudo.status, "Inativo");
            }

            return 0;
        }

        // verifica se o dado escolhido e o primeiro, pois o tratamento sera diferente
        if (teste == 1)
        {

            if (l->primeiro->prox == NULL)
            {

                free(l->primeiro);

                l->primeiro = NULL;
                l->ultimo = NULL;
            }
            else
            {
                p = l->primeiro;
                l->primeiro = p->prox;

                free(p);
            }
        }
        else
        {

            return 0;
        }
    }
    else if (opc == 2) // exclui no final
    {
        amostra(l->ultimo);

        gotoxy(8, 23);
        printf("                                              ");
        teste = validarNum("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ", 8, 23);

        if (pesquisaMovim(m, l->ultimo->conteudo.codigo) != NULL)
        {
            gotoxy(8, 23);
            printf("Conta Bancaria com Movimentacoes Bancarias. Nao pode ser removida.");
            getch();
            gotoxy(8, 23);
            printf("                                                                    ");
            teste = validarNum("Deseja somente inativar a conta?(Sim = 1/Nao = 0)", 8, 23);

            if (teste == 1)
            {
                strcpy(l->ultimo->conteudo.status, "Inativo");
            }

            return 0;
        }

        if (teste == 1)
        {

            if (l->primeiro->prox == NULL)
            {

                free(l->primeiro);

                l->primeiro = NULL;
                l->ultimo = NULL;
            }
            else
            {
                aux = l->primeiro;
                p = aux->prox;

                while (p->prox != NULL)
                {
                    p = p->prox;
                    aux = aux->prox;
                }

                free(p);
                aux->prox = NULL;
                l->ultimo = aux;
            }
        }
        else
        {
            return 0;
        }
    }
    else if (opc == 3) // exclui na posicao desejada
    {
        do
        {
            gotoxy(8, 23);
            printf("                                                       ");
            gotoxy(8, 23);
            printf("Digite a posicao a ser apagada: ");
            scanf("%d", &pos);
            gotoxy(8, 23);
            printf("                                                       ");

            qtd = contador(l);

            if (pos > qtd || pos < 1)
            {
                gotoxy(8, 23);
                printf("                                                       ");
                gotoxy(8, 23);
                printf("Posicao invalida");
                getch();
                gotoxy(8, 23);
                printf("                                                       ");
            }

        } while (pos > qtd || pos < 1);

        if (pos == 1)
        {
            amostra(l->primeiro);

            gotoxy(8, 23);
            printf("                                               ");
            teste = validarNum("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ", 8, 23);

            if (pesquisaMovim(m, l->primeiro->conteudo.codigo) != NULL)
            {
                gotoxy(8, 23);
                printf("Conta Bancaria com Movimentacoes Bancarias. Nao pode ser removida.");
                getch();
                gotoxy(8, 23);
                printf("                                                                    ");
                teste = validarNum("Deseja somente inativar a conta?(Sim = 1/Nao = 0)", 8, 23);

                if (teste == 1)
                {
                    strcpy(l->primeiro->conteudo.status, "Inativo");
                }

                return 0;
            }

            if (teste == 1)
            {
                p = l->primeiro;
                l->primeiro = l->primeiro->prox;
                free(p);

                if (l->primeiro == NULL)
                {
                    l->ultimo = NULL;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            aux = l->primeiro;
            p = aux->prox;
            cont = 1;

            while (cont < pos - 1 && p != NULL)
            {
                cont++;
                aux = p;
                p = p->prox;
            }

            if (p != NULL)
            {
                amostra(p);

                gotoxy(8, 23);
                printf("                                             ");
                gotoxy(8, 23);
                teste = validarNum("Deseja realmente apagar os dados(Sim = 1/Nao = 0): ", 8, 23);

                if (pesquisaMovim(m, l->primeiro->conteudo.codigo) != NULL)
                {
                    gotoxy(8, 23);
                    printf("Conta Bancaria com Movimentacoes Bancarias. Nao pode ser removida.");
                    getch();
                    gotoxy(8, 23);
                    printf("                                                                    ");
                    gotoxy(8, 23);
                    printf("Deseja somente inativar a conta?(Sim = 1/Nao = 0)");
                    scanf("%d", &teste);

                    if (teste == 1)
                    {
                        strcpy(p->conteudo.status, "Inativo");
                    }

                    return 0;
                }

                if (teste == 1)
                {
                    aux->prox = p->prox;
                    free(p);

                    if (aux->prox == NULL)
                    {
                        l->ultimo = aux;
                    }
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    return 0;
}