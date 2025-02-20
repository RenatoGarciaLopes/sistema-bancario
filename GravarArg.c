/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: responsavel por gravar as contas em disco
*/

#include "Funcoes.h"


void gravarArquivo(tipolista *l)
{
    FILE *arquivo = fopen("Contas.dat", "wb"); // Abre o arquivo para escrita binária
    if (arquivo == NULL)
    {
        gotoxy(8, 23);
        printf("Erro ao abrir o arquivo!");
        getch();
        return;
    }

    tipoapontador p = l->primeiro;
    while (p != NULL)
    {
        fwrite(&(p->conteudo), sizeof(reg_funcionario), 1, arquivo);
        p = p->prox;
    }

    fclose(arquivo);
}