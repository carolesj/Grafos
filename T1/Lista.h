//
// Created by caroles on 25/11/2018.
//

#ifndef T1_LISTA_H
#define T1_LISTA_H

struct no {
    int valor;
    struct no * proximo;
};

typedef no No;

No * cria_lista (int linhas);

void adiciona_elemento (No* lista, int destino, int elemento);

void remove_elemento (No * lista, int destino, int elemento);

// KKK EU VO MATA A LISTA
void mata_lista (No * lista, int linhas);

#endif //T1_LISTA_H
