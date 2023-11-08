#include <stdio.h>
#include "turma.h"

int main() {
    int quantidadeAlunos;

    printf("Digite a quantidade de alunos na turma: ");
    scanf("%d", &quantidadeAlunos);

    Turma turma = criarTurma(quantidadeAlunos);

    Aluno aluno;
    for (int i = 0; i < quantidadeAlunos; ++i) {
        printf("Digite os dados do aluno %d:\n", i + 1);
        printf("Código: ");
        scanf("%d", &aluno.codigo);
        printf("Nome: ");
        scanf("%s", aluno.nome);
        printf("Idade: ");
        scanf("%d", &aluno.idade);
        printf("Coeficiente: ");
        scanf("%f", &aluno.coeficiente);

        inserirAluno(&turma, aluno);
    }

    imprimirDadosTurma(turma);

    int codigoBusca;
    printf("Digite o código do aluno a ser buscado: ");
    scanf("%d", &codigoBusca);

    buscarAlunoPorCodigo(turma, codigoBusca);

    liberarTurma(&turma);

    return 0;
}