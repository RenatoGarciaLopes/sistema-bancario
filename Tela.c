/*
Autor.: Renato Garcia Lopes
Data..: 20/11/2024
Equipe: RA:169479-2024 - Artur Bergamo
        RA:171270-2024 - Renato Lopes
Objetivo.: código base para criar telas
*/

#include "Funcoes.h"

// Função para posicionar o cursor na tela em uma posição (x, y)
void gotoxy(int x, int y) {

    COORD coord;  // Estrutura que armazena as coordenadas (x, y) do cursor

    // Definindo as coordenadas como do tipo short para evitar problemas de compatibilidade
    coord.X = (short)x;
    coord.Y = (short)y;

    // Muda a posição do cursor no console para a coordenada definida
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Função para imprimir a primeira linha de uma tela, com bordas
void imprimir_prim_linha(int linha) {
    int i;

    // Coloca o cursor na primeira posição da linha e imprime o caractere '201' (canto superior esquerdo)
    gotoxy(01, linha);
    printf("%c", 201);

    // Desenha uma linha horizontal de '205' (caractere de linha horizontal) até a coluna 80
    gotoxy(01, linha);
    for (i = 2; i < 80; i++) {
        gotoxy(i, linha);
        printf("%c", 205);
    }

    // Coloca o caractere '187' (canto superior direito) na posição final da linha
    gotoxy(80, linha);
    printf("%c", 187);
}

// Função para imprimir uma linha intermediária com bordas laterais, repetida em várias partes da tela
void imprimir_linha(int linha) {
    int i;

    // Imprime o caractere '204' (linha quebrada à esquerda)
    gotoxy(01, linha);
    printf("%c", 204);

    // Preenche a linha com o caractere '205' (linha horizontal)
    gotoxy(01, linha);
    for (i = 2; i < 80; i++) {
        gotoxy(i, linha);
        printf("%c", 205);
    }

    // Finaliza com o caractere '185' (linha quebrada à direita)
    gotoxy(80, linha);
    printf("%c", 185);
}

// Função para imprimir a última linha da tela, com bordas
void imprimir_ultm_linha(int linha) {
    int i;

    // Imprime o caractere '200' (canto inferior esquerdo)
    gotoxy(01, linha);
    printf("%c", 200);

    // Preenche a linha com o caractere '205' (linha horizontal)
    gotoxy(01, linha);
    for (i = 2; i < 80; i++) {
        gotoxy(i, linha);
        printf("%c", 205);
    }

    // Finaliza com o caractere '188' (canto inferior direito)
    gotoxy(80, linha);
    printf("%c", 188);
}

// Função para imprimir a estrutura de uma tela padrão com bordas, título e área de mensagens
void tela() {

    int i;
    system("cls");      // Limpa a tela do console
    system("color 0A"); // Muda a cor da tela para verde (fundo preto e texto verde)

    // Imprime a primeira linha com borda e escreve o título "Unicv" e o nome "Renato"
    imprimir_prim_linha(1);
    gotoxy(03, 02);
    printf("Unicv");

    gotoxy(73, 02);
    printf("Renato");
    gotoxy(73, 03);
    printf("Artur");

    // Desenha as bordas verticais da tela (caractere '186') entre as linhas 2 e 23
    for (i = 2; i < 24; i++) {
        gotoxy(01, i);
        printf("%c", 186);  // Borda esquerda

        gotoxy(80, i);
        printf("%c", 186);  // Borda direita
    }

    // Imprime as linhas intermediárias na parte superior (linha 4) e inferior (linha 22)
    imprimir_linha(4);
    imprimir_linha(22);

    // Espaço reservado para mensagens no rodapé da tela
    gotoxy(02, 23);
    printf("MSG.:");

    // Imprime a última linha da tela com borda
    imprimir_ultm_linha(24);
}

// Função para imprimir uma linha vertical dentro da tela
void imprimir_linha_vert(int linha) {
    int i;

    // Imprime o caractere '203' (quebra de linha no topo da coluna)
    gotoxy(linha, 4);
    printf("%c", 203);

    // Preenche a coluna com o caractere '186' (linha vertical) entre as linhas 5 e 21
    gotoxy(26, 4);
    for (i = 5; i < 22; i++) {
        gotoxy(linha, i);
        printf("%c", 186);
    }

    // Finaliza com o caractere '202' (quebra de linha na base da coluna)
    gotoxy(linha, 22);
    printf("%c", 202);
}

// Função que imprime a tela final com uma estrutura mais complexa (divisões internas)
void tela_fim() {

    int i;
    system("cls");      // Limpa a tela do console
    system("color 0A"); // Muda a cor da tela para verde

    // Imprime a primeira linha com borda e título
    imprimir_prim_linha(1);
    gotoxy(03, 02);
    printf("Unicv");

    gotoxy(73, 02);
    printf("Renato");

    // Imprime as bordas verticais da tela entre as linhas 2 e 23
    for (i = 2; i < 24; i++) {
        gotoxy(01, i);
        printf("%c", 186);  // Borda esquerda

        gotoxy(80, i);
        printf("%c", 186);  // Borda direita
    }

    // Imprime as linhas intermediárias (linhas 4 e 22)
    imprimir_linha(4);
    imprimir_linha(22);

    // Imprime linhas verticais dentro da tela, criando divisões internas (nas colunas 26 e 54)
    imprimir_linha_vert(26);
    imprimir_linha_vert(54);

    // Espaço reservado para mensagens no rodapé da tela
    gotoxy(02, 23);
    printf("MSG.:");

    // Imprime a última linha da tela com borda
    imprimir_ultm_linha(24);
}

void tela_conta()
{
    tela();

    gotoxy(30, 7);
    printf("codigo..............: ");

    gotoxy(30, 9);
    printf("1.Banco.............: ");

    gotoxy(30, 11);
    printf("2.Agencia...........: ");

    gotoxy(30, 13);
    printf("3.Numero da conta...: ");

    gotoxy(30, 15);
    printf("4.Tipo da conta.....: ");

    gotoxy(30, 17);
    printf("5.Saldo na conta....: ");

    gotoxy(30, 19);
    printf("6.Limite de credito.: ");
}