#include <stdio.h>
#include <stdlib.h>
#include "turma.h"

Turma criarTurma(int quantidade) {
    Turma turma;
    turma.alunos = (Aluno*)malloc(quantidade * sizeof(Aluno));
    turma.quantidade = 0;
    return turma;
}

void inserirAluno(Turma *turma, Aluno aluno) {
    if (turma->quantidade < sizeof(turma->alunos)) {
        turma->alunos[turma->quantidade++] = aluno;
    } else {
        printf("Turma cheia, não é possível adicionar mais alunos.\n");
    }
}

void liberarTurma(Turma *turma) {
    free(turma->alunos);
    turma->quantidade = 0;
}

void buscarAlunoPorCodigo(Turma turma, int codigo) {
    for (int i = 0; i < turma.quantidade; ++i) {
        if (turma.alunos[i].codigo == codigo) {
            printf("Aluno encontrado:\n");
            printf("Código: %d\n", turma.alunos[i].codigo);
            printf("Nome: %s\n", turma.alunos[i].nome);
            printf("Idade: %d\n", turma.alunos[i].idade);
            printf("Coeficiente: %.2f\n", turma.alunos[i].coeficiente);
            return;
        }
    }
    printf("Aluno com código %d não encontrado na turma.\n", codigo);
}

void imprimirDadosTurma(Turma turma) {
    printf("Lista de Alunos na Turma:\n");
    for (int i = 0; i < turma.quantidade; ++i) {
        printf("Código: %d, Nome: %s\n", turma.alunos[i].codigo, turma.alunos[i].nome);
    }
}