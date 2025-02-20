/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: responsavel por ler as contas que estao em disco
*/

#include "Funcoes.h"

void lerArquivo(tipolista *l)
{
    FILE *arquivo = fopen("Contas.dat", "rb"); // Tenta abrir o arquivo para leitura binária
    if (arquivo == NULL)
    {
        // Se o arquivo não existir, cria um novo arquivo vazio
        arquivo = fopen("Contas.dat", "wb");
        if (arquivo == NULL)
        {
            gotoxy(8, 23);
            printf("Erro ao criar o arquivo!");
            getch();
            return;
        }
        fclose(arquivo); // Fecha o arquivo criado

        // Reabre o arquivo agora no modo de leitura
        arquivo = fopen("Contas.dat", "rb");
        if (arquivo == NULL)
        {
            gotoxy(8, 23);
            printf("Erro ao abrir o arquivo para leitura!");
            getch();
            return;
        }
    }

    reg_funcionario cont;
    while (fread(&cont, sizeof(reg_funcionario), 1, arquivo))
    {
        tipoapontador novo = (tipoapontador)malloc(sizeof(Tipoitem));
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
