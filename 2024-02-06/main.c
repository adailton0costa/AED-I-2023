// man.c

#include <stdio.h>
#include "arvore.h"

int main() {
    No* arvore = criarArvore();

    // Inserindo elementos na árvore
    int elementos[] = {24, 10, 32, 5, 12, 29, 35};
    int numElementos = sizeof(elementos) / sizeof(elementos[0]);
    for (int i = 0; i < numElementos; i++) {
        inserirElemento(&arvore, elementos[i]);
    }

    // Imprimindo a árvore em In-ordem
    printf("Árvore em In-ordem: ");
    imprimirArvore(arvore);
    printf("\n");

    // Contando elementos na árvore
    int totalElementos = contarElementos(arvore);
    printf("Total de elementos na árvore: %d\n", totalElementos);

    // Buscando um elemento na árvore
    int chaveBusca = 29;
    No* elementoBusca = buscarElemento(arvore, chaveBusca);
    if (elementoBusca != NULL) {
        printf("Elemento %d encontrado na árvore.\n", chaveBusca);
    } else {
        printf("Elemento %d não encontrado na árvore.\n", chaveBusca);
    }

    // Percorrendo e mostrando as chaves em Pré-ordem
    printf("Chaves em Pré-ordem: ");
    preOrdem(arvore);
    printf("\n");

    // Percorrendo e mostrando as chaves em In-ordem (novamente)
    printf("Chaves em In-ordem: ");
    inOrdem(arvore);
    printf("\n");

    // Percorrendo e mostrando as chaves em Pós-ordem
    printf("Chaves em Pós-ordem: ");
    posOrdem(arvore);
    printf("\n");

    return 0;
}
