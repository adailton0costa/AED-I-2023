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

    // Alocar um novo paciente e copiar os dados
    Paciente* novoPaciente = (Paciente*)malloc(sizeof(Paciente));
    if (novoPaciente == NULL) {
        perror("Erro ao alocar memória para o novo paciente");
        exit(EXIT_FAILURE);
    }

    *novoPaciente = paciente;

    // Adicionar o novo paciente na frente da lista encadeada
    novoPaciente->proximo = tabela->tabela[indice];
    tabela->tabela[indice] = novoPaciente;
}

// Função para buscar um paciente na tabela hash
Paciente* buscarPaciente(TabelaHash* tabela, int codigo) {
    int indice = calcularIndice(codigo);
    Paciente* pacienteAtual = tabela->tabela[indice];

    while (pacienteAtual != NULL) {
        if (pacienteAtual->codigo == codigo) {
            return pacienteAtual;
        }
        pacienteAtual = pacienteAtual->proximo;
    }

    return NULL; // Paciente não encontrado
}

// Função para excluir um paciente da tabela hash
void excluirPaciente(TabelaHash* tabela, int codigo) {
    int indice = calcularIndice(codigo);

    Paciente* pacienteAtual = tabela->tabela[indice];
    Paciente* pacienteAnterior = NULL;

    while (pacienteAtual != NULL) {
        if (pacienteAtual->codigo == codigo) {
            // Remove o paciente da lista
            if (pacienteAnterior != NULL) {
                pacienteAnterior->proximo = pacienteAtual->proximo;
            } else {
                tabela->tabela[indice] = pacienteAtual->proximo;
            }

            // Libera a memória alocada para o paciente
            free(pacienteAtual);
            return;
        }

        pacienteAnterior = pacienteAtual;
        pacienteAtual = pacienteAtual->proximo;
    }
}

// Função para destruir a tabela hash e liberar a memória alocada
void destruirTabelaHash(TabelaHash* tabela) {
    // Liberar a memória de cada lista encadeada
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Paciente* pacienteAtual = tabela->tabela[i];
        while (pacienteAtual != NULL) {
            Paciente* pacienteAnterior = pacienteAtual;
            pacienteAtual = pacienteAtual->proximo;
            free(pacienteAnterior);
        }
    }

    // Liberar a memória da tabela hash
    free(tabela);
}
