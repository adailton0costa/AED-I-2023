#include "tabela_hash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função auxiliar para calcular o índice na tabela hash
int calcularIndice(int codigo) {
    return codigo % TAMANHO_TABELA;
}

// Função para criar uma tabela hash
TabelaHash* criarTabelaHash() {
    TabelaHash* tabela = (TabelaHash*)malloc(sizeof(TabelaHash));
    if (tabela == NULL) {
        perror("Erro ao alocar memória para a tabela hash");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela->tabela[i] = NULL;
    }

    return tabela;
}

// Função para inserir um paciente na tabela hash
void inserirPaciente(TabelaHash* tabela, Paciente paciente) {
    int indice = calcularIndice(paciente.codigo);

    // Tratar colisões (substituir o paciente existente)
    tabela->tabela[indice] = &paciente;
}

// Função para buscar um paciente na tabela hash
Paciente* buscarPaciente(TabelaHash* tabela, int codigo) {
    int indice = calcularIndice(codigo);
    return tabela->tabela[indice];
}

// Função para destruir a tabela hash e liberar a memória alocada
void destruirTabelaHash(TabelaHash* tabela) {
    free(tabela);
}
