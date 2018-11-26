//
// Created by caroles on 25/11/2018.
//

#include <stdlib.h>
#include "Matriz.h"

int ** cria_matriz (int linhas, int colunas) {
    int ** matriz;
    matriz = malloc(sizeof(int *) * linhas);
    for (int i = 0; i < linhas; i++) {
        *(matriz + i) = calloc(colunas, sizeof(int));
    }

    return matriz;
}

void insere_matriz (int ** matriz, int linha, int coluna, int valor) {
    *(*(matriz + linha) + coluna) = valor;
    return;
}

void remove_matriz (int ** matriz, int linha, int coluna) {
    *(*(matriz + linha) + coluna) = 0;
    return;
}

void mata_matriz (int ** matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(*(matriz + i));
    }
    free(matriz);
}