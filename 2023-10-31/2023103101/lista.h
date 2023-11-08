#ifndef LISTA_H
#define LISTA_H

typedef struct {
  int *vetor;
  int quantidade;
} LISTA;

LISTA criarLista(int tamanho);
void liberarLista(LISTA *lista);
void inserirElemento(LISTA *lista, int elemento);
void inserirElementoOrdenado(LISTA *lista, int elemento);
void imprimirListaIterativo(LISTA lista);
int buscarElementoSequencial(LISTA lista, int elemento);
int buscarElementoSequencialOrdenado(LISTA lista, int elemento);
int buscaBinariaIterativa(LISTA lista, int elemento, int *comparacoes);
void imprimirListaRecursivo(LISTA lista, int indice);
int encontrarMaiorElemento(LISTA lista);
int encontrarMenorElemento(LISTA lista);
int calcularSomaElementos(LISTA lista);
int calcularProdutoElementos(LISTA lista);
int buscaBinariaRecursivaComContagem(LISTA lista, int elemento, int esquerda,
                                     int direita, int *comparacoes);

#endif