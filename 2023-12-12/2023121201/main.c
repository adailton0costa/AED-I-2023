// main.c
#include <stdio.h>
#include "aluno.h"

int main() {
    ListaAlunos lista;
    Aluno aluno1 = {101, "Maria", 20};
    Aluno aluno2 = {102, "Dom", 22};
    Aluno aluno3 = {103, "Flavia", 21};

    inicializarLista(&lista);

    inserirElementoOrdenado(&lista, aluno2);
    inserirElementoOrdenado(&lista, aluno1);
    inserirElementoOrdenado(&lista, aluno3);

    printf("Lista de alunos:\n");
    exibirLista(lista);

    printf("\nQuantidade de elementos na lista: %d\n", quantidadeElementos(lista));
    printf("A lista esta cheia? %s\n", listaCheia(lista) ? "Sim" : "Não");
    printf("A lista esta vazia? %s\n", listaVazia(lista) ? "Sim" : "Não");

    excluirElemento(&lista, 102);

    printf("\nLista de alunos após excluir o aluno com matrícula 102:\n");
    exibirLista(lista);

    reiniciarLista(&lista);

    printf("\nA lista após reiniciar:\n");
    exibirLista(lista);

    return 0;
}