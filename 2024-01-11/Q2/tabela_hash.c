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

// Função para inserir ou atualizar um paciente na tabela hash
void inserirPaciente(TabelaHash* tabela, Paciente paciente) {
    int indice = calcularIndice(paciente.codigo);

    // Se a posição está disponível ou marcada para exclusão, inserir ou atualizar o paciente
    if (tabela->tabela[indice] == NULL || tabela->tabela[indice]->disponivel == 1) {
        // Alocar um novo paciente e copiar os dados
        Paciente* novoPaciente = (Paciente*)malloc(sizeof(Paciente));
        if (novoPaciente == NULL) {
            perror("Erro ao alocar memória para o novo paciente");
            exit(EXIT_FAILURE);
        }

        *novoPaciente = paciente;
        novoPaciente->disponivel = 0;  // Marcar como ocupado

        tabela->tabela[indice] = novoPaciente;
    } else {
        // Atualizar o paciente existente
        tabela->tabela[indice]->codigo = paciente.codigo;
        strcpy(tabela->tabela[indice]->nome, paciente.nome);
        strcpy(tabela->tabela[indice]->cpf, paciente.cpf);
        tabela->tabela[indice]->idade = paciente.idade;
        tabela->tabela[indice]->disponivel = 0;  // Marcar como ocupado
    }
}

// Função para buscar um paciente na tabela hash
Paciente* buscarPaciente(TabelaHash* tabela, int codigo) {
    int indice = calcularIndice(codigo);
    return tabela->tabela[indice];
}

// Função para excluir um paciente da tabela hash
void excluirPaciente(TabelaHash* tabela, int codigo) {
    int indice = calcularIndice(codigo);

    // Marcar a posição como disponível
    if (tabela->tabela[indice] != NULL) {
        tabela->tabela[indice]->disponivel = 1;
    }
}

// Função para destruir a tabela hash e liberar a memória alocada
void destruirTabelaHash(TabelaHash* tabela) {
    // Liberar a memória da tabela hash
    free(tabela);
}
