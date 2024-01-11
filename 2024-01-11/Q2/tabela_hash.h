#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#define TAMANHO_TABELA 100

// Estrutura para armazenar informações do paciente
typedef struct Paciente {
    int codigo;
    char nome[50];
    char cpf[15];
    int idade;
    struct Paciente* proximo;  // Ponteiro para o próximo paciente na lista encadeada
} Paciente;

// Estrutura da tabela hash
typedef struct {
    Paciente* tabela[TAMANHO_TABELA];
} TabelaHash;

// Funções públicas
TabelaHash* criarTabelaHash();
void inserirPaciente(TabelaHash* tabela, Paciente paciente);
Paciente* buscarPaciente(TabelaHash* tabela, int codigo);
void excluirPaciente(TabelaHash* tabela, int codigo);
void destruirTabelaHash(TabelaHash* tabela);

#endif
