#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"
#include "data.h"

int main() {
    Pessoa *pessoaPtr = (Pessoa *)malloc(sizeof(Pessoa));
    Data *dataNascimento = (Data *)malloc(sizeof(Data));

    preencherPessoa(pessoaPtr, "Adailton costa", "22/01/2000", "123.456.789-00");

    // Preencha a estrutura de data
    preencherData(dataNascimento, 22, 1, 2000);

    printf("Dados da Pessoa:\n");
    imprimirPessoa(pessoaPtr);

    printf("Data de Nascimento:\n");
    imprimirData(dataNascimento);

    // Libere a memória alocada dinamicamente
    free(pessoaPtr);
    free(dataNascimento);

    return 0;
}