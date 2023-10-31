#ifndef PESSOA_H
#define PESSOA_H

typedef struct {
    char nome[100];
    char dataNascimento[11]; // Formato: dd/mm/aaaa
    char cpf[12]; // Formato: 999.999.999-99
} Pessoa;

void preencherPessoa(Pessoa *pessoa, const char *nome, const char *dataNascimento, const char *cpf);
void imprimirPessoa(const Pessoa *pessoa);

#endif