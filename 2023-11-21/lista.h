#ifndef LISTA_H
#define LISTA_H

typedef struct {
    int chave;
    // Outros campos podem ser adicionados conforme necessário
} Elemento;

typedef struct {
    Elemento *elementos;
    int tamanho;
    int capacidade;
} ListaLinearSequencial;

ListaLinearSequencial criarLista(int capacidade);
void inserirNoFinal(ListaLinearSequencial *lista, Elemento elemento);
void inserirOrdenado(ListaLinearSequencial *lista, Elemento elemento);
void eliminarElemento(ListaLinearSequencial *lista, int chave);
void imprimirLista(ListaLinearSequencial lista);

#endif // LISTA_LINEAR_SEQUENCIAL_H
