#include "tabela_hash.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void imprimirPaciente(Paciente* paciente) {
    if (paciente != NULL) {
        printf("Código: %d\n", paciente->codigo);
        printf("Nome: %s\n", paciente->nome);
        printf("CPF: %s\n", paciente->cpf);
        printf("Idade: %d\n", paciente->idade);
    } else {
        printf("Paciente não encontrado.\n");
    }
}

int main() {
    TabelaHash* tabela = criarTabelaHash();

    Paciente* paciente1 = (Paciente*)malloc(sizeof(Paciente));
    paciente1->codigo = 123;
    strcpy(paciente1->nome, "João");
    strcpy(paciente1->cpf, "12345678901");
    paciente1->idade = 30;
    paciente1->proximo = NULL;
    inserirPaciente(tabela, paciente1);

    Paciente* paciente2 = (Paciente*)malloc(sizeof(Paciente));
    paciente2->codigo = 456;
    strcpy(paciente2->nome, "Maria");
    strcpy(paciente2->cpf, "98765432109");
    paciente2->idade = 25;
    paciente2->proximo = NULL;
    inserirPaciente(tabela, paciente2);

    Paciente* pacienteEncontrado1 = buscarPaciente(tabela, 123);
    imprimirPaciente(pacienteEncontrado1);

    Paciente* pacienteEncontrado2 = buscarPaciente(tabela, 456);
    imprimirPaciente(pacienteEncontrado2);

    free(paciente1);
    free(paciente2);
    destruirTabelaHash(tabela);

    return 0;
}