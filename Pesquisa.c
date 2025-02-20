/*
Autor.: Artur Ribeiro Bérgamo
Data..:20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo: Função implementada para encontrar os dados das contas
*/

#include "Funcoes.h"

tipoapontador pesquisa(tipolista *l, int cod)
{

    tipoapontador aux;

    // Inicia a pesquisa a partir do primeiro elemento da lista

    aux = l->primeiro;

    // Percorre a lista até encontrar o código ou chegar ao fim (NULL)

    while (aux != NULL)
    {
        if (aux->conteudo.codigo == cod)
        {
            return aux;
        }

        aux = aux->prox;
    }

    return NULL;
}