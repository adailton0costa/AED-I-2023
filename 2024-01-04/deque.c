// deque.c
#include "deque.h"

void inicializarDeque(Deque *D) {
    D->inicio = NULL;
    D->fim = NULL;
    D->tamanho = 0;
}

bool inserir_inicio(Deque *D, Soldado x) {
    Node *novoNode = (Node *)malloc(sizeof(Node));
    if (novoNode == NULL) {
        return false; // Falha na alocação de memória
    }

    novoNode->soldado = x;
    novoNode->anterior = NULL;
    novoNode->proximo = D->inicio;

    if (D->inicio == NULL) {
        // Se o deque está vazio, o novoNode é tanto o início quanto o fim
        D->inicio = novoNode;
        D->fim = novoNode;
    } else {
        D->inicio->anterior = novoNode;
        D->inicio = novoNode;
    }

    D->tamanho++;
    return true;
}

bool inserir_fim(Deque *D, Soldado x) {
    Node *novoNode = (Node *)malloc(sizeof(Node));
    if (novoNode == NULL) {
        return false; // Falha na alocação de memória
    }

    novoNode->soldado = x;
    novoNode->anterior = D->fim;
    novoNode->proximo = NULL;

    if (D->fim == NULL) {
        // Se o deque está vazio, o novoNode é tanto o início quanto o fim
        D->inicio = novoNode;
        D->fim = novoNode;
    } else {
        D->fim->proximo = novoNode;
        D->fim = novoNode;
    }

    D->tamanho++;
    return true;
}

Soldado remover_inicio(Deque *D) {
    if (vazia(D)) {
        Soldado soldadoVazio = {0, "", ""};
        return soldadoVazio; // Retorna um Soldado vazio se o deque estiver vazio
    }

    Node *temp = D->inicio;
    Soldado soldadoRemovido = temp->soldado;

    if (D->inicio == D->fim) {
        // Se só houver um elemento, atualiza início e fim para NULL
        D->inicio = NULL;
        D->fim = NULL;
    } else {
        D->inicio = temp->proximo;
        D->inicio->anterior = NULL;
    }

    free(temp);
    D->tamanho--;
    return soldadoRemovido;
}

Soldado remover_fim(Deque *D) {
    if (vazia(D)) {
        Soldado soldadoVazio = {0, "", ""};
        return soldadoVazio; // Retorna um Soldado vazio se o deque estiver vazio
    }

    Node *temp = D->fim;
    Soldado soldadoRemovido = temp->soldado;

    if (D->inicio == D->fim) {
        // Se só houver um elemento, atualiza início e fim para NULL
        D->inicio = NULL;
        D->fim = NULL;
    } else {
        D->fim = temp->anterior;
        D->fim->proximo = NULL;
    }

    free(temp);
    D->tamanho--;
    return soldadoRemovido;
}

Soldado primeiro(Deque *D) {
    if (vazia(D)) {
        Soldado soldadoVazio = {0, "", ""};
        return soldadoVazio; // Retorna um Soldado vazio se o deque estiver vazio
    }

    return D->inicio->soldado;
}

Soldado ultimo(Deque *D) {
    if (vazia(D)) {
        Soldado soldadoVazio = {0, "", ""};
        return soldadoVazio; // Retorna um Soldado vazio se o deque estiver vazio
    }

    return D->fim->soldado;
}

int contar(Deque *D) {
    return D->tamanho;
}

bool vazia(Deque *D) {
    return D->inicio == NULL;
}

Soldado remover_pos(Deque *D, int n) {
    if (vazia(D) || n <= 0 || n > D->tamanho) {
        Soldado soldadoVazio = {0, "", ""};
        return soldadoVazio; // Retorna um Soldado vazio se o deque estiver vazio ou a posição for inválida
    }

    // Encontrar o nó na posição desejada
    Node *temp = D->inicio;
    for (int i = 1; i < n; i++) {
        temp = temp->proximo;
    }

    // Remover o nó e ajustar os ponteiros
    if (temp->anterior != NULL) {
        temp->anterior->proximo = temp->proximo;
    } else {
        D->inicio = temp->proximo;
    }

    if (temp->proximo != NULL) {
        temp->proximo->anterior = temp->anterior;
    } else {
        D->fim = temp->anterior;
    }

    Soldado soldadoRemovido = temp->soldado;
    free(temp);
    D->tamanho--;

    return soldadoRemovido;
}
