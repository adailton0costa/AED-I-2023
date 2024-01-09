// deque.h
#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0

typedef struct {
    int codigo;
    char nome[50];
    char grau[20];
} Soldado;

typedef struct Node {
    Soldado soldado;
    struct Node *anterior;
    struct Node *proximo;
} Node;

typedef struct {
    Node *inicio;
    Node *fim;
    int tamanho;
} Deque;

void inicializarDeque(Deque *D);
bool inserir_inicio(Deque *D, Soldado x);
bool inserir_fim(Deque *D, Soldado x);
Soldado remover_inicio(Deque *D);
Soldado remover_fim(Deque *D);
Soldado primeiro(Deque *D);
Soldado ultimo(Deque *D);
int contar(Deque *D);
bool vazia(Deque *D);
Soldado remover_pos(Deque *D, int n);

#endif
