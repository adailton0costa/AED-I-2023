#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

ListaLinearSequencial criarLista(int capacidade) {
    ListaLinearSequencial lista;
    lista.elementos = (Elemento *)malloc(capacidade * sizeof(Elemento));
    lista.tamanho = 0;
    lista.capacidade = capacidade;
    return lista;
}

void inserirNoFinal(ListaLinearSequencial *lista, Elemento elemento) {
    if (lista->tamanho < lista->capacidade) {
        lista->elementos[lista->tamanho] = elemento;
        lista->tamanho++;
    } else {
        printf("A lista está cheia. Não é possível inserir mais elementos.\n");
    }
}

void inserirOrdenado(ListaLinearSequencial *lista, Elemento elemento) {
    int i, j;

    if (lista->tamanho == 0 || elemento.chave > lista->elementos[lista->tamanho - 1].chave) {
        inserirNoFinal(lista, elemento);
    } else {
        for (i = 0; i < lista->tamanho; i++) {
            if (elemento.chave < lista->elementos[i].chave) {
                for (j = lista->tamanho - 1; j >= i; j--) {
                    lista->elementos[j + 1] = lista->elementos[j];
                }
                lista->elementos[i] = elemento;
                lista->tamanho++;
                break;
            }
        }
    }
}

void eliminarElemento(ListaLinearSequencial *lista, int chave) {
    int i, j;

    for (i = 0; i < lista->tamanho; i++) {
        if (lista->elementos[i].chave == chave) {
            for (j = i; j < lista->tamanho - 1; j++) {
                lista->elementos[j] = lista->elementos[j + 1];
            }
            lista->tamanho--;
            break;
        }
    }
}

void imprimirLista(ListaLinearSequencial lista) {
    int i;

    printf("Elementos da lista:\n");
    for (i = 0; i < lista.tamanho; i++) {
        printf("%d ", lista.elementos[i].chave);
    }
    printf("\n");
}
