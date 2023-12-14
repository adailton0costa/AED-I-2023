// main.c
#include "lista_ligada.h"

int main() {
    ListaLigada L;
    L.tamanho = 0;

    // Adicionando elementos à lista L (substitua esses valores pelos seus próprios)
    adicionarElemento(&L, 1);
    adicionarElemento(&L, 2);
    adicionarElemento(&L, 3);
    adicionarElemento(&L, 4);
    adicionarElemento(&L, 5);

    // Imprimindo lista original L
    printf("Lista L original: ");
    imprimirLista(&L);

    // Construindo e imprimindo lista L1
    ListaLigada L1 = construirL1(&L);
    printf("Lista L1: ");
    imprimirLista(&L1);

    // Construindo e imprimindo lista L2
    ListaLigada L2 = construirL2(&L);
    printf("Lista L2: ");
    imprimirLista(&L2);

    return 0;
}
