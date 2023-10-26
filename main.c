#include <stdio.h>
#include <stdlib.h>
#include "pessoa.h"

int main() {
    Pessoa *pessoaPtr = (Pessoa *)malloc(sizeof(Pessoa));

    preencherPessoa(pessoaPtr, "Adailton costa", "22/01/2000", "123.456.789-00");

    printf("Dados da Pessoa:\n");
    imprimirPessoa(pessoaPtr);

    free(pessoaPtr);

    return 0;
}
