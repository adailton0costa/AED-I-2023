#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main() {
    ListaLinearSequencial lista = criarLista(10);

    Elemento elem1 = {1};
    Elemento elem2 = {3};
    Elemento elem3 = {5};
    Elemento elem4 = {6};
    Elemento elem5 = {7};
    inserirNoFinal(&lista, elem1);
    inserirNoFinal(&lista, elem2);
    inserirNoFinal(&lista, elem3);
    inserirNoFinal(&lista, elem4);
    inserirNoFinal(&lista, elem5);


    imprimirLista(lista);

    Elemento elem6 = {2};
    Elemento elem7 = {4};
    inserirOrdenado(&lista, elem6);
    inserirOrdenado(&lista, elem7);

    imprimirLista(lista);

    eliminarElemento(&lista, 5);

    imprimirLista(lista);

    free(lista.elementos);

    return 0;
}