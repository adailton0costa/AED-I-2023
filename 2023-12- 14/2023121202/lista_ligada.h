// lista_ligada.h
#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct ListaLigada {
    No elementos[100];
    int tamanho;
} ListaLigada;

void adicionarElemento(ListaLigada* lista, int valor);
void imprimirLista(ListaLigada* lista);
ListaLigada construirL1(ListaLigada* lista);
ListaLigada construirL2(ListaLigada* lista);

#endif // LISTA_LIGADA_H