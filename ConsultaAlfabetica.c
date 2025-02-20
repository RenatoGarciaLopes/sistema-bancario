
/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: responsavel por consultar por ordem alfabetica
*/

#include "Funcoes.h"



void ordenarPorBanco(tipolista *l)
{
    tipoapontador atual, prox;
    reg_funcionario temp; // `temp` armazena apenas o conteúdo do nó
    int trocou;

    if (l->primeiro == NULL || l->primeiro->prox == NULL)
    {
        // Lista vazia ou com apenas um elemento; não é necessário ordenar
        return;
    }

    do
    {
        trocou = 0;
        atual = l->primeiro;

        while (atual->prox != NULL)
        {
            prox = atual->prox;

            // Comparar os nomes dos bancos
            if (strcmp(atual->conteudo.banco, prox->conteudo.banco) > 0)
            {
                // Trocar apenas os conteúdos
                temp = atual->conteudo;
                atual->conteudo = prox->conteudo;
                prox->conteudo = temp;

                trocou = 1; // Marcar que houve troca
            }

            atual = atual->prox; // Avançar para o próximo nó
        }

    } while (trocou);
}

void ordenarPorCodigo(tipolista *l)
{
    tipoapontador atual, prox;
    reg_funcionario temp; // `temp` armazena apenas o conteúdo do nó
    int trocou;

    if (l->primeiro == NULL || l->primeiro->prox == NULL)
    {
        // Lista está vazia ou contém apenas um elemento; não é necessário ordenar
        return;
    }

    do
    {
        trocou = 0;
        atual = l->primeiro;

        while (atual->prox != NULL)
        {
            prox = atual->prox;

            if (atual->conteudo.codigo > prox->conteudo.codigo)
            {
                // Trocar apenas os conteúdos
                temp = atual->conteudo;
                atual->conteudo = prox->conteudo;
                prox->conteudo = temp;

                trocou = 1; // Marcar que houve troca
            }

            atual = atual->prox; // Avançar para o próximo nó
        }

    } while (trocou);
}

int consultarAlfa(tipolista *l, int opc)
{
    tipoapontador aux;
    int conta = 0; // Inicializar o contador de linhas
    int status;
    double saldoTotal = 0.0, limiteTotal = 0.0; // Para somar saldos e limites

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

    TelaConsultaConta(); // Chamar a função de exibição da tela

    // Ordenar a lista conforme a opção (3 = por código, outro = por banco)
    if (opc == 3)
    {
        ordenarPorCodigo(l);
    }
    else
    {
        ordenarPorBanco(l);
    }

    aux = l->primeiro;

    while (aux != NULL)
    {
        // Determinar o status (1 = Ativo, 0 = Inativo)
        if (strcmp(aux->conteudo.status, "Ativo") == 0)
        {
            status = 1;
        }
        else
        {
            status = 0;
        }

        // Exibir o registro formatado
        gotoxy(2, conta + 7);
        printf("%-2d %-19s %-5s %-8s %-14s R$%9.2lf R$%8.2lf %-2d", aux->conteudo.codigo, aux->conteudo.banco, aux->conteudo.agencia, aux->conteudo.numero_conta, aux->conteudo.tipo_conta, aux->conteudo.vl_saldo, aux->conteudo.vl_limite, status);

        // Acumular saldos e limites
        saldoTotal += aux->conteudo.vl_saldo;
        limiteTotal += aux->conteudo.vl_limite;

        conta++;

        // Controle de paginação (15 linhas por página)
        if (conta == 15)
        {
            gotoxy(8, 23);
            printf("Pressione alguma tecla para continuar...");
            getch(); // Esperar o usuário pressionar uma tecla
            gotoxy(8, 23);
            printf("                                           ");

            // Limpar as linhas da tabela exibida
            for (int j = 0; j < 15; j++)
            {
                gotoxy(2, j + 7);
                printf("                                                                             ");
            }

            conta = 0; // Reiniciar o contador de linhas
        }

        aux = aux->prox;
    }

    // Exibir o saldo total e o limite total no final
    gotoxy(42, conta + 7);
    printf("%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c", 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);
    gotoxy(42, conta + 8);
    printf("Saldo Total: R$%10.2lf R$%8.2lf", saldoTotal, limiteTotal);

    getch(); // Esperar o usuário pressionar uma tecla antes de retornar
    return 0;
}
