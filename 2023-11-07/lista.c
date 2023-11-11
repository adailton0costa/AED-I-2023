#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

LISTA criarLista(int quantidade) {
    LISTA lista;
    lista.elementos = (int*)malloc(quantidade * sizeof(int));
    lista.quantidade = 0;
    return lista;
}

void liberarLista(LISTA *lista) {
    free(lista->elementos);
    lista->quantidade = 0;
}

void inserirElemento(LISTA *lista, int elemento) {
    if (lista->quantidade < sizeof(lista->elementos)) {
        lista->elementos[lista->quantidade++] = elemento;
    } else {
        printf("Lista cheia, não é possível adicionar mais elementos.\n");
    }
}
void inserirElementoOrdenado(LISTA *lista, int elemento) {
    int i = lista->quantidade - 1;

    while (i >= 0 && lista->elementos[i] > elemento) {
        lista->elementos[i + 1] = lista->elementos[i];
        i--;
    }

    lista->elementos[i + 1] = elemento;
    lista->quantidade++;

    // Reorganizar a lista usando bubble sort (poderia ser otimizado)
    for (int i = 0; i < lista->quantidade - 1; i++) {
        for (int j = 0; j < lista->quantidade - i - 1; j++) {
            if (lista->elementos[j] > lista->elementos[j + 1]) {
                int temp = lista->elementos[j];
                lista->elementos[j] = lista->elementos[j + 1];
                lista->elementos[j + 1] = temp;
            }
        }
    }
}


void imprimirListaIterativo(LISTA lista) {
    for (int i = 0; i < lista.quantidade; ++i) {
        printf("%d ", lista.elementos[i]);
    }
    printf("\n");
}

int buscaBinariaRecursiva(LISTA lista, int elemento, int inicio, int fim) {
    if (inicio > fim) {
        return -1;  // Elemento não encontrado
    }

    int meio = (inicio + fim) / 2;

    if (lista.elementos[meio] == elemento) {
        return meio;  // Elemento encontrado
    } else if (lista.elementos[meio] > elemento) {
        return buscaBinariaRecursiva(lista, elemento, inicio, meio - 1);
    } else {
        return buscaBinariaRecursiva(lista, elemento, meio + 1, fim);
    }
}

void imprimirListaRecursivo(LISTA lista, int indice) {
    if (indice < lista.quantidade) {
        printf("%d ", lista.elementos[indice]);
        imprimirListaRecursivo(lista, indice + 1);
    } else {
        printf("\n");
    }
}

int buscarMaiorRecursivo(LISTA lista, int indice) {
    if (indice == lista.quantidade - 1) {
        return lista.elementos[indice];
    }

    int maiorRestante = buscarMaiorRecursivo(lista, indice + 1);

    return (lista.elementos[indice] > maiorRestante) ? lista.elementos[indice] : maiorRestante;
}

int buscarMenorRecursivo(LISTA lista, int indice) {
    if (indice == lista.quantidade - 1) {
        return lista.elementos[indice];
    }

    int menorRestante = buscarMenorRecursivo(lista, indice + 1);

    return (lista.elementos[indice] < menorRestante) ? lista.elementos[indice] : menorRestante;
}

int somaRecursiva(LISTA lista, int indice) {
    if (indice == lista.quantidade - 1) {
        return lista.elementos[indice];
    }

    return lista.elementos[indice] + somaRecursiva(lista, indice + 1);
}

int produtoRecursivo(LISTA lista, int indice) {
    if (indice == lista.quantidade - 1) {
        return lista.elementos[indice];
    }

    return lista.elementos[indice] * produtoRecursivo(lista, indice + 1);
}