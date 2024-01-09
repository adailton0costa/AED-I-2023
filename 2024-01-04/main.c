// main.c
#include "deque.h"
#include <stdio.h>

void josephus(Deque *D, int n) {
    printf("\nSoldados eliminados para o problema de Josephus:\n");

    while (contar(D) > 1) {
        for (int i = 1; i < n; i++) {
            inserir_fim(D, remover_inicio(D));
        }

        Soldado soldadoEliminado = remover_inicio(D);
        printf("Soldado %d eliminado\n", soldadoEliminado.codigo);
    }

    Soldado soldadoEscapado = remover_inicio(D);
    printf("\nSoldado que escapa: Soldado %d\n", soldadoEscapado.codigo);
}

int main() {
    Deque dequeSoldados;
    inicializarDeque(&dequeSoldados);

    for (int i = 1; i <= 10; i++) {
        Soldado novoSoldado = {i, "Soldado", "Grau"};
        inserir_fim(&dequeSoldados, novoSoldado);
    }

    printf("Operações no deque de soldados:\n");
    printf("Contagem: %d\n", contar(&dequeSoldados));
    printf("Deque vazio? %s\n", vazia(&dequeSoldados) ? "Sim" : "Não");

    printf("\nRemover do início: Soldado %d\n", remover_inicio(&dequeSoldados).codigo);
    printf("Contagem: %d\n", contar(&dequeSoldados));

    printf("\nRemover do final: Soldado %d\n", remover_fim(&dequeSoldados).codigo);
    printf("Contagem: %d\n", contar(&dequeSoldados));

    printf("\nPrimeiro: Soldado %d\n", primeiro(&dequeSoldados).codigo);
    printf("Último: Soldado %d\n", ultimo(&dequeSoldados).codigo);

    josephus(&dequeSoldados, 3);

    return 0;
}
