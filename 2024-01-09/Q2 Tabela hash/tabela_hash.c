#include "tabela_hash.h"
#include <stdlib.h>

TabelaHash* criarTabelaHash() {
    TabelaHash* tabela = (TabelaHash*)malloc(sizeof(TabelaHash));
    for (int i = 0; i < TABLE_SIZE; i++) {
        tabela->data[i] = NULL;
    }
    return tabela;
}

int funcaoHash(int codigo) {
    return codigo % TABLE_SIZE;
}

void inserirPaciente(TabelaHash* tabela, Paciente* paciente) {
    int indice = funcaoHash(paciente->codigo);
    if (tabela->data[indice] == NULL) {
        tabela->data[indice] = paciente;
    } else {
        Paciente* atual = tabela->data[indice];
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = paciente;
    }
}

Paciente* buscarPaciente(TabelaHash* tabela, int codigo) {
    int indice = funcaoHash(codigo);
    Paciente* atual = tabela->data[indice];
    while (atual != NULL) {
        if (atual->codigo == codigo) {
            return atual;
        }
        atual = atual->proximo;
    }
    return NULL;
}

void destruirTabelaHash(TabelaHash* tabela) {
    free(tabela);
}