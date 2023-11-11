#include "lista.h"
#include <stdio.h>

int main() {
  int quantidadeElementos;

  printf("Digite a quantidade de elementos na lista: ");
  scanf("%d", &quantidadeElementos);

  LISTA lista = criarLista(quantidadeElementos);

  // Inserir elementos manualmente ou gerar números aleatórios
  for (int i = 0; i < quantidadeElementos; ++i) {
    int elemento;
    printf("Digite o elemento %d: ", i + 1);
    scanf("%d", &elemento);
    inserirElemento(&lista, elemento);
  }

  printf("Lista original: ");
  imprimirListaIterativo(lista);

  // Inserir elemento de forma ordenada
  int elementoOrdenado;
  printf("Digite um elemento para inserir de forma ordenada: ");
  scanf("%d", &elementoOrdenado);
  inserirElementoOrdenado(&lista, elementoOrdenado);

  printf("Lista ordenada: ");
  imprimirListaIterativo(lista);

  // Busca binária
  int elementoBusca;
  printf("Digite um elemento para buscar na lista: ");
  scanf("%d", &elementoBusca);
  int indice =
      buscaBinariaRecursiva(lista, elementoBusca, 0, lista.quantidade - 1);
  if (indice != -1) {
    printf("Elemento encontrado na posição %d.\n", indice);
  } else {
    printf("Elemento não encontrado na lista.\n");
  }

  // Imprimir elementos de forma recursiva
  printf("Lista (recursivo): ");
  imprimirListaRecursivo(lista, 0);

  // Buscar maior elemento
  int maiorElemento = buscarMaiorRecursivo(lista, 0);
  printf("Maior elemento na lista: %d\n", maiorElemento);

  // Buscar menor elemento
  int menorElemento = buscarMenorRecursivo(lista, 0);
  printf("Menor elemento na lista: %d\n", menorElemento);

  // Soma de todos os elementos
  int soma = somaRecursiva(lista, 0);
  printf("Soma de todos os elementos: %d\n", soma);

  // Produto de todos os elementos
  int produto = produtoRecursivo(lista, 0);
  printf("Produto de todos os elementos: %d\n", produto);

  // Liberar espaço na memória
  liberarLista(&lista);

  return 0;
}