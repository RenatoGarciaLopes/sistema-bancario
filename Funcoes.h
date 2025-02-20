/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: cabeçalho que contem as funçoes e as listas
*/

#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

typedef struct
{
    int codigo;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    char status[10];

} reg_funcionario;

typedef struct Tipoitem *tipoapontador;

typedef struct Tipoitem
{

    reg_funcionario conteudo;
    tipoapontador prox;

} Tipoitem;

typedef struct
{
    tipoapontador primeiro;
    tipoapontador ultimo;

} tipolista;

typedef struct 
{
    int sequencial;
    int codigo_conta;
    char dt_movimento[11];
    char tp_movimento[15];
    char ds_favorecido[50];
    float vl_movimento;
    float vl_saldo;

}reg_movimentos;

typedef struct Tipoitem_movim *tipoapontador_movim;

typedef struct Tipoitem_movim
{

    reg_movimentos conteudo;
    tipoapontador_movim prox;
    tipoapontador_movim ant;

} Tipoitem_movim;

typedef struct
{
    tipoapontador_movim primeiro;
    tipoapontador_movim ultimo;

}TipoLista_movim;

void gotoxy(int x, int y);

void tela();

void imprimir_ultm_linha(int linha);

void imprimir_prim_linha(int linha);

void tela_fim();

void imprimir_linha(int linha);

void tela_conta();

void telaCadastro(tipolista *l);

void gravarArquivo(tipolista *l);

void lerArquivo(tipolista *l);

int cadastro(tipolista *l, int opc);

int remover(TipoLista_movim *m, tipolista *l, int opc);

void TelaRemover(TipoLista_movim *m, tipolista *l);

int contador(tipolista *l);

void amostra(tipoapontador p);

int consultar(tipolista *l);

int consultarCod(tipolista *l);

float validarNum(char *mensagem, int x, int y);

void inserirMovim(TipoLista_movim *l, reg_movimentos cont);

tipoapontador pesquisa(tipolista *l, int cod);

void TelaCadMovim(TipoLista_movim *l);

void TelaContas(TipoLista_movim *m,tipolista *l);

void TelaMovim(TipoLista_movim *m, tipolista *l);

int movimCreDeb(TipoLista_movim *m, tipolista *l);

int validarECompararComLista(const char *novaDataStr, TipoLista_movim *m);

void tela_transferencia();

void TelaConsulta(tipolista *l);

int TransConta(TipoLista_movim *m, tipolista *l);

tipoapontador_movim pesquisaMovim(TipoLista_movim *l, int cod);

void TelaConsultaG();

void lerArquivoMov(TipoLista_movim *l);

void gravarArquivoMov(TipoLista_movim *l);

int consultar_mov(tipolista *l, TipoLista_movim *m);

void TelaConsultaConta();

int consultarAlfa(tipolista *l, int opc);

int alterar(tipolista *l);


#endif

