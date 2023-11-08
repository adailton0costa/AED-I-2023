#ifndef TURMA_H
#define TURMA_H

typedef struct {
    int codigo;
    char nome[50];
    int idade;
    float coeficiente;
} Aluno;

typedef struct {
    Aluno *alunos;
    int quantidade;
} Turma;

Turma criarTurma(int quantidade);
void inserirAluno(Turma *turma, Aluno aluno);
void liberarTurma(Turma *turma);
void buscarAlunoPorCodigo(Turma turma, int codigo);
void imprimirDadosTurma(Turma turma);

#endif