// arvore.c

#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

// Função auxiliar para criar um novo nó
No* criarNo(int chave) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        novo->chave = chave;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    return novo;
}

// Função para criar/inicializar a árvore
No* criarArvore() {
    return NULL;
}

// Função para inserir um elemento na árvore
void inserirElemento(No** raiz, int chave) {
    if (*raiz == NULL) {
        *raiz = criarNo(chave);
    } else {
        if (chave < (*raiz)->chave) {
            inserirElemento(&(*raiz)->esquerda, chave);
        } else if (chave > (*raiz)->chave) {
            inserirElemento(&(*raiz)->direita, chave);
        }
    }
}

// Função para imprimir a árvore (inOrdem)
void imprimirArvore(No* raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esquerda);
        printf("%d ", raiz->chave);
        imprimirArvore(raiz->direita);
    }
}

// Função para contar elementos na árvore
int contarElementos(No* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return 1 + contarElementos(raiz->esquerda) + contarElementos(raiz->direita);
    }
}

// Função para buscar um elemento na árvore
No* buscarElemento(No* raiz, int chave) {
    if (raiz == NULL || raiz->chave == chave) {
        return raiz;
    }

    if (chave < raiz->chave) {
        return buscarElemento(raiz->esquerda, chave);
    } else {
        return buscarElemento(raiz->direita, chave);
    }
}

// Função para percorrer e mostrar as chaves em Pré-ordem
void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->chave);
        preOrdem(raiz->esquerda);
        preOrdem(raiz->direita);
    }
}

// Função para percorrer e mostrar as chaves em In-ordem
void inOrdem(No* raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esquerda);
        printf("%d ", raiz->chave);
        inOrdem(raiz->direita);
    }
}

// Função para percorrer e mostrar as chaves em Pós-ordem
void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerda);
        posOrdem(raiz->direita);
        printf("%d ", raiz->chave);
    }
}
