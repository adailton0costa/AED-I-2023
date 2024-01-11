// main.c

#include "tabela_hash.h"
#include <stdio.h>

int main() {
    TabelaHash* tabela = criarTabelaHash();

    // Exemplo de inserção de pacientes
    Paciente paciente1 = {1, "Carlos", "379.587.356-96", 25};
    Paciente paciente2 = {2, "Joao", "314.361.991-00", 30};

    inserirPaciente(tabela, paciente1);
    inserirPaciente(tabela, paciente2);

    // Exemplo de busca de pacientes
    int codigoBusca = 1;
    Paciente* pacienteEncontrado = buscarPaciente(tabela, codigoBusca);

    if (pacienteEncontrado != NULL) {
        printf("Paciente encontrado:\n");
        printf("Código: %d\n", pacienteEncontrado->codigo);
        printf("Nome: %s\n", pacienteEncontrado->nome);
        printf("CPF: %s\n", pacienteEncontrado->cpf);
        printf("Idade: %d\n", pacienteEncontrado->idade);
    } else {
        printf("Paciente com código %d não encontrado.\n", codigoBusca);
    }

    // Limpar a memória antes de encerrar o programa
    destruirTabelaHash(tabela);

    return 0;
}
