// aluno.h
#ifndef ALUNO_H
#define ALUNO_H

// Estrutura que representa um aluno
typedef struct {
    int matricula;
    char nome[50];
    int idade;
} Aluno;

// Estrutura que representa um nó da lista
typedef struct Node {
    Aluno data;
    struct Node* next;
} Node;

// Estrutura que representa a lista ligada dinâmica
typedef struct {
    Node* head;
    int count;
} ListaAlunos;

// Funções do TDA
void inicializarLista(ListaAlunos* lista);
void reiniciarLista(ListaAlunos* lista);
int quantidadeElementos(ListaAlunos lista);
int listaCheia(ListaAlunos lista);
int listaVazia(ListaAlunos lista);
void exibirLista(ListaAlunos lista);
void inserirElementoOrdenado(ListaAlunos* lista, Aluno aluno);
void excluirElemento(ListaAlunos* lista, int matricula);

#endif