// main.c
#include "lista_ligada_dinamica.h"

int main() {
    ListaLigada l1, l2;

    // Inicializando listas
    inicializarLista(&l1);
    inicializarLista(&l2);

    // Adicionando elementos às listas (substitua esses valores pelos seus próprios)
    adicionarElemento(&l1, 1);
    adicionarElemento(&l1, 3);
    adicionarElemento(&l1, 5);

    adicionarElemento(&l2, 2);
    adicionarElemento(&l2, 4);
    adicionarElemento(&l2, 6);

    // Imprimindo listas originais
    printf("Lista l1: ");
    imprimirLista(&l1);

    printf("Lista l2: ");
    imprimirLista(&l2);

    // Copiando lista l1 para l3
    ListaLigada l3 = copiarLista(&l1);
    printf("Cópia de l1 (l3): ");
    imprimirLista(&l3);

    // Concatenando l1 e l2
    ListaLigada concatenacao = concatenarListas(&l1, &l2);
    printf("Concatenação de l1 e l2: ");
    imprimirLista(&concatenacao);

    // Intercalando l1 e l2
    ListaLigada intercalacao = intercalarListas(&l1, &l2);
    printf("Intercalação de l1 e l2: ");
    imprimirLista(&intercalacao);

    return 0;
}