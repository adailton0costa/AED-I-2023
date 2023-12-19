#ifndef FILA_H
#define FILA_H

typedef struct {
    char nome[50];
    int identificador;
} Aviao;

typedef struct no {
    Aviao aviao;
    struct no* proximo;
} No;

typedef struct {
    No* inicio;
    No* fim;
    int tamanho;
} Fila;

Fila* criarFila();
void destruirFila(Fila* fila);
void inserirAviao(Fila* fila, Aviao aviao);
void removerAviao(Fila* fila);
Aviao* primeiroAviao(Fila* fila);
int numeroAvioesEspera(Fila* fila);
void listarAvioesEspera(Fila* fila);

#endif
