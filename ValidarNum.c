/*
Autor.: Renato Garcia Lopes
Data..: 20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo.: responsavel por validar os caracteres nas entradas de numeros
*/

#include "Funcoes.h"

float validarNum(char *mensagem, int x, int y)
{
    char buffer[50];
    float valor;
    int resultado;

    do
    {
        gotoxy(x, y);
        printf("                                      ");
        gotoxy(x, y);
        printf("%s", mensagem);

        scanf(" %s", buffer);

        resultado = sscanf(buffer, "%f", &valor); // Converte a string para float

        size_t length = strlen(buffer);

        if (buffer[length - 1] == '\n')
        {
            buffer[length - 1] = '\0';
        }

        // Verifica se a conversão falhou (quando não há dígitos válidos)
        if (resultado != 1 || valor <= 0)
        {
            gotoxy(8, 23);
            printf("Entrada invalida, tente novamente (somente numeros positivos).");
            getch();
            gotoxy(8, 23);
            printf("                                                               ");
        }

    } while (resultado != 1 || valor <= 0); // Verifica se a entrada foi válida

    return valor;
}