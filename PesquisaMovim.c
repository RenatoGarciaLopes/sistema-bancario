/*
Autor.: Artur Ribeiro Bérgamo
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: Logica da parte de movimentação que é implementada em funções e codigos.
*/

#include "Funcoes.h"

tipoapontador_movim pesquisaMovim(TipoLista_movim *l, int cod)
{

    tipoapontador_movim aux;

    // Inicia a pesquisa a partir do primeiro elemento da lista

    aux = l->primeiro;

    // Percorre a lista até encontrar o código ou chegar ao fim (NULL)

    while (aux != NULL)
    {
        if (aux->conteudo.codigo_conta == cod)
        {
            return aux;
        }

        aux = aux->prox;
    }

    return NULL;
}