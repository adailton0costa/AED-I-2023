// lista_alunos.h
#ifndef LISTA_ALUNOS_H
#define LISTA_ALUNOS_H

typedef struct Aluno {
    char nome[50];
    // Adicione outros campos relevantes do aluno, se necessário
    struct Aluno* proximo;
    struct Aluno* anterior;
} Aluno;

typedef struct ListaAlunos {
    Aluno* cabeca;
} ListaAlunos;

void inicializarLista(ListaAlunos* lista);
void adicionarAluno(ListaAlunos* lista, const char* nome);
void imprimirLista(ListaAlunos* lista);

#endif // LISTA_ALUNOS_H