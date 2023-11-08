#include "lista.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
  int tamanhoLista, valorBusca;
  LISTA lista1, lista2;

  printf("Digite o tamanho da primeira lista: ");
  scanf("%d", &tamanhoLista);

  // Criar a primeira lista e preencher valores manualmente
  lista1 = criarLista(tamanhoLista);
  for (int i = 0; i < tamanhoLista; i++) {
    int valor;
    printf("Digite o valor %d: ", i + 1);
    scanf("%d", &valor);
    inserirElemento(&lista1, valor);
  }

  printf("Elementos da primeira lista:\n");
  imprimirListaIterativo(lista1);

  printf("Digite um número para buscar na primeira lista: ");
  scanf("%d", &valorBusca);
  int indiceSequencial = buscarElementoSequencial(lista1, valorBusca);
  if (indiceSequencial != -1) {
    printf("O número %d foi encontrado na primeira lista (busca sequencial) no "
           "índice %d.\n",
           valorBusca, indiceSequencial);
  } else {
    printf("O número %d não foi encontrado na primeira lista (busca "
           "sequencial).\n",
           valorBusca);
  }

  // Criar a segunda lista e preencher valores ordenados
  lista2 = criarLista(30);
  for (int i = 0; i < 30; i++) {
    inserirElementoOrdenado(&lista2, i + 1);
  }

  printf("Elementos da segunda lista:\n");
  imprimirListaIterativo(lista2);

  printf("Digite um número para buscar na segunda lista: ");
  scanf("%d", &valorBusca);
  int indiceSequencialOrdenado =
      buscarElementoSequencialOrdenado(lista2, valorBusca);
  if (indiceSequencialOrdenado != -1) {
    printf("O número %d foi encontrado na segunda lista (busca sequencial "
           "ordenada) no índice %d.\n",
           valorBusca, indiceSequencialOrdenado);
  } else {
    printf("O número %d não foi encontrado na segunda lista (busca sequencial "
           "ordenada).\n",
           valorBusca);
  }

  int comparacoesSequencial = 0;
  int indiceBinario = buscaBinariaIterativa(lista2, valorBusca, &comparacoesSequencial);
  if (indiceBinario != -1) {
    printf("O número %d foi encontrado na segunda lista (busca binária) no "
           "índice %d. Comparacoes necessarias: %d\n",
           valorBusca, indiceBinario, comparacoesSequencial);
  } else {
    printf("O número %d não foi encontrado na segunda lista (busca binária). Comparacoes necessarias: %d\n",
           valorBusca, comparacoesSequencial);
  }

  printf("Maior elemento da primeira lista: %d\n", encontrarMaiorElemento(lista1));
  printf("Menor elemento da primeira lista: %d\n", encontrarMenorElemento(lista1));
  printf("Soma dos elementos da primeira lista: %d\n", calcularSomaElementos(lista1));
  printf("Produto dos elementos da primeira lista: %d\n", calcularProdutoElementos(lista1));

  int comparacoesBinariaRecursiva = 0;
  int indiceBinarioRecursiva = buscaBinariaRecursivaComContagem(lista2, valorBusca, 0, 29, &comparacoesBinariaRecursiva);
  if (indiceBinarioRecursiva != -1) {
    printf("O número %d foi encontrado na segunda lista (busca binária recursiva) no "
           "índice %d. Comparacoes necessarias: %d\n",
           valorBusca, indiceBinarioRecursiva, comparacoesBinariaRecursiva);
  } else {
    printf("O número %d não foi encontrado na segunda lista (busca binária recursiva). Comparacoes necessarias: %d\n",
           valorBusca, comparacoesBinariaRecursiva);
  }

  liberarLista(&lista1);
  liberarLista(&lista2);

  return 0;
}
