// lista_ligada_dinamica.h
#ifndef LISTA_LIGADA_DINAMICA_H
#define LISTA_LIGADA_DINAMICA_H

typedef struct No {
    int valor;
    struct No* proximo;
} No;

typedef struct ListaLigada {
    No* cabeca;
} ListaLigada;

void inicializarLista(ListaLigada* lista);
void adicionarElemento(ListaLigada* lista, int valor);
void imprimirLista(ListaLigada* lista);
ListaLigada copiarLista(ListaLigada* original);
ListaLigada concatenarListas(ListaLigada* l1, ListaLigada* l2);
ListaLigada intercalarListas(ListaLigada* l1, ListaLigada* l2);

#endif // LISTA_LIGADA_DINAMICA_H