#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#define TABLE_SIZE 100

typedef struct Paciente {
    int codigo;
    char nome[50];
    char cpf[12];
    int idade;
    struct Paciente* proximo;
} Paciente;

typedef struct {
    Paciente* data[TABLE_SIZE];
} TabelaHash;

TabelaHash* criarTabelaHash();
void inserirPaciente(TabelaHash* tabela, Paciente* paciente);
Paciente* buscarPaciente(TabelaHash* tabela, int codigo);
void destruirTabelaHash(TabelaHash* tabela);

#endif