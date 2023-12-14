// lista_alunos.c
#include "lista_alunos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inicializarLista(ListaAlunos* lista) {
    lista->cabeca = NULL;
}

void adicionarAluno(ListaAlunos* lista, const char* nome) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    strcpy(novoAluno->nome, nome);
    novoAluno->proximo = NULL;
    novoAluno->anterior = NULL;

    if (lista->cabeca == NULL) {
        lista->cabeca = novoAluno;
        novoAluno->proximo = novoAluno;
        novoAluno->anterior = novoAluno;
    } else {
        Aluno* ultimo = lista->cabeca->anterior;
        novoAluno->proximo = lista->cabeca;
        novoAluno->anterior = ultimo;
        lista->cabeca->anterior = novoAluno;
        ultimo->proximo = novoAluno;
    }
}

void imprimirLista(ListaAlunos* lista) {
    if (lista->cabeca == NULL) {
        printf("Lista vazia\n");
        return;
    }

    Aluno* atual = lista->cabeca;

    do {
        printf("%s ", atual->nome);
        atual = atual->proximo;
    } while (atual != lista->cabeca);

    printf("\n");
}