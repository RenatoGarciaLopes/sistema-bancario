/*
Autor.: Renato Garcia Lopes
Data..: 20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo.: responsavel por validar as datas
*/

#include "Funcoes.h"

int extrairData(const char *dataStr, int *dia, int *mes, int *ano) {
    return sscanf(dataStr, "%d/%d/%d", dia, mes, ano) == 3;
}

int validarData(int dia, int mes, int ano) {
    if (ano < 1900 || ano > 2100) return 0; // Ano válido
    if (mes < 1 || mes > 12) return 0;     // Mês válido

    // Dias máximos por mês
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))) {
        diasPorMes[1] = 29; // Ano bissexto
    }

    return dia >= 1 && dia <= diasPorMes[mes - 1];
}

int converterParaNumero(int dia, int mes, int ano) {
    return ano * 10000 + mes * 100 + dia;
}

int validarECompararComLista(const char *novaDataStr, TipoLista_movim *m) {
    int diaNova, mesNova, anoNova;
    int diaUltima, mesUltima, anoUltima;

    // Verificar se a nova data é válida
    if (!extrairData(novaDataStr, &diaNova, &mesNova, &anoNova) || 
        !validarData(diaNova, mesNova, anoNova)) {
        return 0; // Nova data inválida
    }

    // Verificar se a lista está vazia (sem movimentações)
    if (m->ultimo == NULL) {
        return 1; // Aceitar a nova data como válida, pois não há movimentações anteriores
    }

    // Obter a última data da lista
    const char *ultimaDataStr = m->ultimo->conteudo.dt_movimento;

    // Verificar se a última data é válida
    if (!extrairData(ultimaDataStr, &diaUltima, &mesUltima, &anoUltima) || 
        !validarData(diaUltima, mesUltima, anoUltima)) {
        return 0; // Última data inválida
    }

    // Comparar as datas
    int novaDataNum = converterParaNumero(diaNova, mesNova, anoNova);
    int ultimaDataNum = converterParaNumero(diaUltima, mesUltima, anoUltima);

    return novaDataNum >= ultimaDataNum; // Retorna 1 se nova data for maior, 0 caso contrário
}