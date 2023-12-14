// main.c
#include "lista_alunos.h"

int main() {
    ListaAlunos listaCircularDupla;
    inicializarLista(&listaCircularDupla);

    ListaAlunos listaCircular;
    inicializarLista(&listaCircular);

    ListaAlunos listaDupla;
    inicializarLista(&listaDupla);

    // Adicionando alunos às listas
    adicionarAluno(&listaCircularDupla, "Alice");
    adicionarAluno(&listaCircularDupla, "Bob");
    adicionarAluno(&listaCircularDupla, "Camila");
    adicionarAluno(&listaCircularDupla, "Davi");

    adicionarAluno(&listaCircular, "Evan");
    adicionarAluno(&listaCircular, "Franciel");
    adicionarAluno(&listaCircular, "Geraldo");
    adicionarAluno(&listaCircular, "Henrique");

    adicionarAluno(&listaDupla, "Lunciana");
    adicionarAluno(&listaDupla, "Maria");
    adicionarAluno(&listaDupla, "Nolyan");
    adicionarAluno(&listaDupla, "Orlanda");
    adicionarAluno(&listaDupla, "Pedro");
    adicionarAluno(&listaDupla, "Quin");
    adicionarAluno(&listaDupla, "Rian");
    adicionarAluno(&listaDupla, "Sophia");
    adicionarAluno(&listaDupla, "Teliana");
    adicionarAluno(&listaDupla, "Umberto");
    adicionarAluno(&listaDupla, "Victo");
    adicionarAluno(&listaDupla, "William");
    adicionarAluno(&listaDupla, "Xuxa");
    adicionarAluno(&listaDupla, "Yara");

    // Imprimindo listas
    printf("Lista Circular Dupla: ");
    imprimirLista(&listaCircularDupla);

    printf("Lista Circular: ");
    imprimirLista(&listaCircular);

    printf("Lista Dupla: ");
    imprimirLista(&listaDupla);

    return 0;
}