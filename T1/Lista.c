//
// Created by caroles on 25/11/2018.
//

#include <stdlib.h>
#include <stdio.h>
#include "Lista.h"

No * cria_lista (int linhas) {
    No * lista;
    lista = malloc(sizeof(No) * linhas);
    for (int i = 0; i < linhas; i++){
        (lista + i) -> valor = i;
        (lista + i) -> proximo = NULL;
    }

    return lista;
}

void adiciona_elemento (No* lista, int destino, int elemento) {
    No * atual = (lista + destino);
    No * auxiliar = atual -> proximo;
    while(auxiliar != NULL && auxiliar -> valor <= elemento) {
        atual = atual -> proximo;
        auxiliar = auxiliar -> proximo;
    }
    No * novo =  malloc(sizeof(No));
    novo -> valor = elemento;
    novo -> proximo = NULL;
    atual -> proximo = novo;

    return;
}

void remove_elemento (No * lista, int destino, int elemento) {
    No * atual = (lista + destino);
    No * auxiliar = atual -> proximo;
    No * alvo;

    while (auxiliar != NULL && auxiliar -> valor != elemento) {
        atual = atual-> proximo;
        auxiliar = auxiliar -> proximo;
    }
    if (auxiliar == NULL) {
        printf("O no a ser removido não existe");
        return;
    } else if (auxiliar -> proximo == NULL) {
        free(auxiliar);
        atual -> proximo = NULL;
        return;
    }
    alvo = auxiliar;
    auxiliar = auxiliar -> proximo;
    atual -> proximo = auxiliar;
    free(alvo);

    return;
}

void mata_lista (No * lista, int linhas) {
    No * atual, * proximo;
    for (int i = 0; i < linhas; i++){
        atual = (lista + i);
        proximo = (lista + i) -> proximo;
        while (proximo -> proximo != NULL) {
            free(atual);
            atual = proximo;
            proximo = proximo -> proximo;
        }
    }
    free(lista);
    return;
}