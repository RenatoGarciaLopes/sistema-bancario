/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: responsavel por ler as movimentaçoes que estao em disco
*/

#include "Funcoes.h"

void lerArquivoMov(TipoLista_movim *l)
{
    FILE *arquivo = fopen("Movimentacoes.dat", "rb"); // Tenta abrir o arquivo para leitura binária
    if (arquivo == NULL)
    {
        // Se o arquivo não existir, cria um novo arquivo vazio
        arquivo = fopen("Movimentacoes.dat", "wb");
        if (arquivo == NULL)
        {
            gotoxy(8, 23);
            printf("Erro ao criar o arquivo!");
            getch();
            return;
        }
        fclose(arquivo); // Fecha o arquivo criado

        // Reabre o arquivo agora no modo de leitura
        arquivo = fopen("Movimentacoes.dat", "rb");
        if (arquivo == NULL)
        {
            gotoxy(8, 23);
            printf("Erro ao abrir o arquivo para leitura!");
            getch();
            return;
        }
    }

    reg_movimentos cont;
    while (fread(&cont, sizeof(reg_movimentos), 1, arquivo))
    {
        tipoapontador_movim novo = (tipoapontador_movim)malloc(sizeof(Tipoitem_movim));
        novo->conteudo = cont;
        novo->prox = NULL;

        if (l->primeiro == NULL)
        {
            l->primeiro = novo;
            l->ultimo = novo;
        }
        else
        {
            l->ultimo->prox = novo;
            l->ultimo = novo;
        }
    }

    fclose(arquivo);
}
