/*
Autor.: Renato Garcia Lopes
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: responsavel por cadastrar as movimentaçoes na lista
*/

#include "Funcoes.h"

void inserirMovim(TipoLista_movim *l, reg_movimentos cont)
{
    tipoapontador_movim p;
    tipoapontador_movim f;
    tipoapontador_movim F;

   
    cont.dt_movimento[strcspn(cont.dt_movimento, "\n")] = '\0';
    cont.ds_favorecido[strcspn(cont.ds_favorecido, "\n")] = '\0';


    // cria o no p
    p = (tipoapontador_movim)malloc(sizeof(Tipoitem_movim));

   p -> conteudo = cont;
   p ->prox = NULL;
   p ->ant = NULL;

    // adiciona no final

    if (l->primeiro == NULL)
    {
        l->primeiro = p;
        l->ultimo = p;
    }
    else
    {
        l -> ultimo -> prox = p;
        p->ant = l ->ultimo;
        l -> ultimo = p;
    }
}