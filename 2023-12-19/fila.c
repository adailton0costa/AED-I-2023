#include <stdlib.h>
#include "fila.h"

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

void destruirFila(Fila* fila) {
    No* atual = fila->inicio;
    while (atual != NULL) {
        No* proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(fila);
}

void inserirAviao(Fila* fila, Aviao aviao) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->aviao = aviao;
    novoNo->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = novoNo;
        fila->fim = novoNo;
    } else {
        fila->fim->proximo = novoNo;
        fila->fim = novoNo;
    }

    fila->tamanho++;
}

void removerAviao(Fila* fila) {
    if (fila->inicio == NULL) {
        return;
    }

    No* primeiro = fila->inicio;
    fila->inicio = primeiro->proximo;
    free(primeiro);

    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    fila->tamanho--;
}

Aviao* primeiroAviao(Fila* fila) {
    if (fila->inicio == NULL) {
        return NULL;
    }

    return &(fila->inicio->aviao);
}

int numeroAvioesEspera(Fila* fila) {
    return fila->tamanho;
}

void listarAvioesEspera(Fila* fila) {
    No* atual = fila->inicio;
    while (atual != NULL) {
        printf("Nome: %s, Identificador: %d\n", atual->aviao.nome, atual->aviao.identificador);
        atual = atual->proximo;
    }
}