/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: responsavel por gravar as movimentaçoes em disco
*/

#include "Funcoes.h"


void gravarArquivoMov(TipoLista_movim *l)
{
    FILE *arquivo = fopen("Movimentacoes.dat", "wb"); // Abre o arquivo para escrita binária
    if (arquivo == NULL)
    {
        gotoxy(8, 23);
        printf("Erro ao abrir o arquivo!");
        getch();
        return;
    }

    tipoapontador_movim p = l->primeiro;
    while (p != NULL)
    {
        fwrite(&(p->conteudo), sizeof(reg_movimentos), 1, arquivo);
        p = p->prox;
    }

    fclose(arquivo);
}