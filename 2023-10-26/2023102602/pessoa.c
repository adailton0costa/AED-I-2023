#include "pessoa.h"
#include <string.h>
#include <stdio.h>

void preencherPessoa(Pessoa *pessoa, const char *nome, const char *dataNascimento, const char *cpf) {
    strcpy(pessoa->nome, nome);
    strcpy(pessoa->dataNascimento, dataNascimento);
    strcpy(pessoa->cpf, cpf);
}

void imprimirPessoa(const Pessoa *pessoa) {
    printf("Nome: %s\n", pessoa->nome);
    printf("Data de Nascimento: %s\n", pessoa->dataNascimento);
    printf("CPF: %s\n", pessoa->cpf);
}