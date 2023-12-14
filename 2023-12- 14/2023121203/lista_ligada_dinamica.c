// lista_ligada_dinamica.c
#include "lista_ligada_dinamica.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarLista(ListaLigada* lista) {
    lista->cabeca = NULL;
}

void adicionarElemento(ListaLigada* lista, int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = lista->cabeca;
    lista->cabeca = novoNo;
}

void imprimirLista(ListaLigada* lista) {
    No* atual = lista->cabeca;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

ListaLigada copiarLista(ListaLigada* original) {
    ListaLigada copia;
    inicializarLista(&copia);

    No* atual = original->cabeca;
    while (atual != NULL) {
        adicionarElemento(&copia, atual->valor);
        atual = atual->proximo;
    }

    return copia;
}

ListaLigada concatenarListas(ListaLigada* l1, ListaLigada* l2) {
    ListaLigada resultado;
    inicializarLista(&resultado);

    // Copiar elementos de l1
    No* atual = l1->cabeca;
    while (atual != NULL) {
        adicionarElemento(&resultado, atual->valor);
        atual = atual->proximo;
    }

    // Copiar elementos de l2
    atual = l2->cabeca;
    while (atual != NULL) {
        adicionarElemento(&resultado, atual->valor);
        atual = atual->proximo;
    }

    return resultado;
}

ListaLigada intercalarListas(ListaLigada* l1, ListaLigada* l2) {
    ListaLigada resultado;
    inicializarLista(&resultado);

    No* atual1 = l1->cabeca;
    No* atual2 = l2->cabeca;

    while (atual1 != NULL || atual2 != NULL) {
        if (atual1 != NULL) {
            adicionarElemento(&resultado, atual1->valor);
            atual1 = atual1->proximo;
        }

        if (atual2 != NULL) {
            adicionarElemento(&resultado, atual2->valor);
            atual2 = atual2->proximo;
        }
    }

    return resultado;
}