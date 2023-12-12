// aluno.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

void inicializarLista(ListaAlunos* lista) {
    lista->head = NULL;
    lista->count = 0;
}

void reiniciarLista(ListaAlunos* lista) {
    Node* current = lista->head;
    Node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    lista->head = NULL;
    lista->count = 0;
}

int quantidadeElementos(ListaAlunos lista) {
    return lista.count;
}

int listaCheia(ListaAlunos lista) {
    // Assume que a lista nunca está cheia, pois é uma lista dinâmica
    return 0;
}

int listaVazia(ListaAlunos lista) {
    return lista.head == NULL;
}

void exibirLista(ListaAlunos lista) {
    Node* current = lista.head;

    while (current != NULL) {
        printf("Matricula: %d, Nome: %s, Idade: %d\n", current->data.matricula, current->data.nome, current->data.idade);
        current = current->next;
    }
}

void inserirElementoOrdenado(ListaAlunos* lista, Aluno aluno) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = aluno;
    new_node->next = NULL;

    if (lista->head == NULL || aluno.matricula < lista->head->data.matricula) {
        new_node->next = lista->head;
        lista->head = new_node;
    } else {
        Node* current = lista->head;
        while (current->next != NULL && aluno.matricula > current->next->data.matricula) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }

    lista->count++;
}

void excluirElemento(ListaAlunos* lista, int matricula) {
    Node* current = lista->head;
    Node* previous = NULL;

    while (current != NULL && current->data.matricula != matricula) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (previous != NULL) {
            previous->next = current->next;
        } else {
            lista->head = current->next;
        }
        free(current);
        lista->count--;
    }
}