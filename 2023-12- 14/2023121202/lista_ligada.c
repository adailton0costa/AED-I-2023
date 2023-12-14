// lista_ligada.c
#include "lista_ligada.h"
#include <stdio.h>

void adicionarElemento(ListaLigada* lista, int valor) {
    if (lista->tamanho < 100) {
        lista->elementos[lista->tamanho].valor = valor;
        lista->elementos[lista->tamanho].proximo = NULL;
        lista->tamanho++;
    } else {
        printf("Erro: lista está cheia.\n");
    }
}

void imprimirLista(ListaLigada* lista) {
    for (int i = 0; i < lista->tamanho; i++) {
        printf("%d ", lista->elementos[i].valor);
    }
    printf("\n");
}

ListaLigada construirL1(ListaLigada* lista) {
    ListaLigada l1;
    l1.tamanho = 0;

    for (int i = 1; i < lista->tamanho; i++) {
        adicionarElemento(&l1, lista->elementos[i].valor);
    }

    adicionarElemento(&l1, lista->elementos[0].valor);

    return l1;
}

ListaLigada construirL2(ListaLigada* lista) {
    ListaLigada l2;
    l2.tamanho = 0;

    for (int i = lista->tamanho - 1; i >= 0; i--) {
        adicionarElemento(&l2, lista->elementos[i].valor);
    }

    return l2;
}