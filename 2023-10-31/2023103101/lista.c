#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

LISTA criarLista(int tamanho) {
  LISTA lista;
  lista.vetor = (int *)malloc(tamanho * sizeof(int));
  lista.quantidade = 0;
  return lista;
}

void liberarLista(LISTA *lista) {
  free(lista->vetor);
  lista->vetor = NULL;
  lista->quantidade = 0;
}

void inserirElemento(LISTA *lista, int elemento) {
  lista->vetor[lista->quantidade] = elemento;
  lista->quantidade++;
}

void inserirElementoOrdenado(LISTA *lista, int elemento) {
  int i = lista->quantidade - 1;
  while (i >= 0 && lista->vetor[i] > elemento) {
    lista->vetor[i + 1] = lista->vetor[i];
    i--;
  }
  lista->vetor[i + 1] = elemento;
  lista->quantidade++;
}

void imprimirListaIterativo(LISTA lista) {
  for (int i = 0; i < lista.quantidade; i++) {
    printf("%d ", lista.vetor[i]);
  }
  printf("\n");
}

int buscarElementoSequencial(LISTA lista, int elemento) {
  int comparacoes = 0;
  for (int i = 0; i < lista.quantidade; i++) {
    comparacoes++;
    if (lista.vetor[i] == elemento) {
      printf("Comparacoes necessarias: %d\n", comparacoes);
      return i;
    }
  }
  printf("Comparacoes necessarias: %d\n", comparacoes);
  return -1;
}

int buscarElementoSequencialOrdenado(LISTA lista, int elemento) {
  int comparacoes = 0;
  int i = 0;
  while (i < lista.quantidade && lista.vetor[i] < elemento) {
    comparacoes++;
    i++;
  }
  if (i < lista.quantidade && lista.vetor[i] == elemento) {
    printf("Comparacoes necessarias: %d\n", comparacoes);
    return i;
  }
  printf("Comparacoes necessarias: %d\n", comparacoes);
  return -1;
}

int buscaBinariaIterativa(LISTA lista, int elemento, int *comparacoes) {
  int esquerda = 0;
  int direita = lista.quantidade - 1;

  while (esquerda <= direita) {
    int meio = (esquerda + direita) / 2;
    (*comparacoes)++;
    if (lista.vetor[meio] == elemento) {
      return meio;
    } else if (lista.vetor[meio] < elemento) {
      esquerda = meio + 1;
    } else {
      direita = meio - 1;
    }
  }
  return -1;
}

void imprimirListaRecursivo(LISTA lista, int indice) {
  if (indice >= lista.quantidade) {
    printf("\n");
    return;
  }

  printf("%d ", lista.vetor[indice]);
  imprimirListaRecursivo(lista, indice + 1);
}

int encontrarMaiorElemento(LISTA lista) {
  int maior = lista.vetor[0];
  for (int i = 1; i < lista.quantidade; i++) {
    if (lista.vetor[i] > maior) {
      maior = lista.vetor[i];
    }
  }
  return maior;
}

int encontrarMenorElemento(LISTA lista) {
  int menor = lista.vetor[0];
  for (int i = 1; i < lista.quantidade; i++) {
    if (lista.vetor[i] < menor) {
      menor = lista.vetor[i];
    }
  }
  return menor;
}

int calcularSomaElementos(LISTA lista) {
  int soma = 0;
  for (int i = 0; i < lista.quantidade; i++) {
    soma += lista.vetor[i];
  }
  return soma;
}

int calcularProdutoElementos(LISTA lista) {
  int produto = 1;
  for (int i = 0; i < lista.quantidade; i++) {
    produto *= lista.vetor[i];
  }
  return produto;
}

int buscaBinariaRecursivaComContagem(LISTA lista, int elemento, int esquerda,
                                     int direita, int *comparacoes) {
  if (esquerda > direita) {
    return -1;
  }

  int meio = (esquerda + direita) / 2;
  (*comparacoes)++;

  if (lista.vetor[meio] == elemento) {
    return meio;
  } else if (lista.vetor[meio] < elemento) {
    return buscaBinariaRecursivaComContagem(lista, elemento, meio + 1, direita, comparacoes);
  } else {
    return buscaBinariaRecursivaComContagem(lista, elemento, esquerda, meio - 1, comparacoes);
  }
}