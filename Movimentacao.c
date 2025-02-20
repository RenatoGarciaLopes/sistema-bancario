/*
Autor.: Artur Ribeiro Bérgamo
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: Logica utilizada para movimentação de dados das contas, caso seja credito ou debito.
*/

#include "Funcoes.h"

int movimCreDeb(TipoLista_movim *m, tipolista *l)
{
    int codigo;          // Código da conta para movimentação
    tipoapontador aux;   // Apontador auxiliar para localizar a conta
    reg_movimentos cont; // Estrutura que armazena dados da movimentação
    int tp_movim;        // Tipo de movimentação: 1 = Débito, 2 = Crédito
    int teste;           // Variável de controle para validações
    double saldo;        // Saldo disponível (saldo + limite)
    double restante;     // Valor restante em caso de débito superior ao saldo
    int resultado;       // Resultado da validação de data
    int confirmacao;     // Variável para confirmação de saída

    gotoxy(34, 2);
    printf("MOVIMENTACAO");

    TelaCadMovim(m);
    do
    {

        gotoxy(8, 23);
        printf("Digite \"0\" para sair");
        gotoxy(54, 7);
        printf("              ");
        gotoxy(54, 7);
        scanf("%d", &codigo);

        cont.codigo_conta = codigo;

        if (cont.codigo_conta == 0)
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

        // Pesquisa pela conta na lista
        aux = pesquisa(l, codigo);

        if (aux == NULL)
        {

            gotoxy(8, 23);
            printf("                                                     ");
            gotoxy(8, 23);
            printf("Conta nao encontrada ou inexistente");
            getch();
            gotoxy(8, 23);
            printf("                                                     ");
        }
        else if (aux->conteudo.status == "Inativo")
        {

            gotoxy(8, 23);
            printf("                                                     ");
            gotoxy(8, 23);
            printf("Conta inativa");
            getch();
            gotoxy(8, 23);
            printf("                                                     ");
        }

    } while (aux == NULL || aux->conteudo.status == "Inativo");

    // Exibe os dados da conta encontrada
    gotoxy(54, 8);
    printf("%s", aux->conteudo.agencia);

    gotoxy(54, 9);
    printf("%s", aux->conteudo.numero_conta);

    gotoxy(54, 10);
    printf("%s", aux->conteudo.tipo_conta);

    gotoxy(54, 11);
    printf("%.2lf", aux->conteudo.vl_saldo);

    gotoxy(54, 12);
    printf("%.2lf", aux->conteudo.vl_limite);

    gotoxy(54, 13);
    printf("%.2lf", aux->conteudo.vl_limite + aux->conteudo.vl_saldo);

    // Valida a data da movimentação
    do
    {

        gotoxy(8, 23);
        printf("Data da Movimentacao (DD/MM/YYYY)");
        gotoxy(54, 15);
        printf("                      ");
        gotoxy(54, 15);
        getchar();
        fflush(stdin);
        fgets(cont.dt_movimento, 11, stdin);

        resultado = validarECompararComLista(cont.dt_movimento, m);

        if (resultado != 1)
        {

            gotoxy(8, 23);
            printf("                                                     ");

            if (m->primeiro == NULL)
            {
                gotoxy(8, 23);
                printf("Data invalida. Tente novamente. ");
                getch();
            }
            else
            {
                gotoxy(8, 23);
                printf("Data da Movimentacao Invalida, ultima data: %s ", m->ultimo->conteudo.dt_movimento);
                getch();
                gotoxy(8, 23);
                printf("                                                     ");
            }
        }

    } while (resultado != 1);

    // Determina o tipo de movimentação
    do
    {
        gotoxy(8, 23);
        printf("                                   ");
        gotoxy(8, 23);
        printf("Utilizar.: 1=Debito / 2=Credito");

        gotoxy(54, 16);
        printf("                       ");
        gotoxy(54, 16);
        scanf("%d", &tp_movim);

        gotoxy(8, 23);
        printf("                                   ");
        gotoxy(8, 23);

        if (tp_movim != 1 && tp_movim != 2)
        {
            gotoxy(8, 23);
            printf("                                   ");
            gotoxy(8, 23);
            printf("Tipo de movimentacao Invalido");
            getch();
            gotoxy(8, 23);
            printf("                                   ");
        }

        if (tp_movim == 1)
        {
            strcpy(cont.tp_movimento, "Debito");
        }

        if (tp_movim == 2)
        {
            strcpy(cont.tp_movimento, "Credito");
        }

        gotoxy(8, 23);
        printf("                    ");

    } while (tp_movim != 1 && tp_movim != 2);

    gotoxy(54, 17);
    printf("                        ");
    gotoxy(54, 17);
    getchar();
    fflush(stdin);
    fgets(cont.ds_favorecido, 50, stdin);

    saldo = aux->conteudo.vl_limite + aux->conteudo.vl_saldo;

    // Valida o valor da movimentação
    do
    {
        cont.vl_movimento = validarNum("4-Valor movimentacao...: ", 29, 18);

        if (tp_movim == 1 && cont.vl_movimento > saldo)
        {
            gotoxy(8, 23);
            printf("                                                  ");
            gotoxy(8, 23);
            printf("Valor Movimentacao Invalido ou Saldo Insuficiente");
            getch();
            gotoxy(8, 23);
            printf("                                                  ");
            gotoxy(8, 23);
        }
    } while (tp_movim == 1 && cont.vl_movimento > saldo);

    if (tp_movim == 1)
    { // Débito

        if (cont.vl_movimento <= saldo)
        {

            aux->conteudo.vl_saldo -= cont.vl_movimento;
        }
        else
        {

            restante = cont.vl_movimento - saldo;
            aux->conteudo.vl_saldo = 0;
            aux->conteudo.vl_limite -= restante;
        }
    }
    else
    { // Crédito

        aux->conteudo.vl_saldo += cont.vl_movimento;
    }

    cont.vl_saldo = aux->conteudo.vl_limite + aux->conteudo.vl_saldo;

    gotoxy(54, 19);
    printf("%.2f", cont.vl_saldo);

    getch();

    if (m->ultimo == NULL)
    {
        cont.sequencial = 1;
    }
    else
    {
        cont.sequencial = m->ultimo->conteudo.sequencial + 1;
    }

    // Insere a movimentação na lista de movimentações

        teste = validarNum("Deseja gravar (Sim = 1/Nao = 2): ", 8,23);

    if (teste == 1)
    {
        inserirMovim(m, cont);
    }

    return 0;
}