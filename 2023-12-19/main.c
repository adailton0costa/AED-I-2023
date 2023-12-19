#include "fila.h"
#include <stdio.h>

int main() {
  Fila *fila = criarFila();

  // Adicionando aviões à fila de espera
  Aviao aviao1 = {"Voo 123", 1};
  inserirAviao(fila, aviao1);

  Aviao aviao2 = {"Voo 456", 2};
  inserirAviao(fila, aviao2);

  Aviao aviao3 = {"Voo 789", 3};
  inserirAviao(fila, aviao3);

  // Listando todos os aviões na fila de espera
  printf("lista de Aviões na fila de espera:\n");
  listarAvioesEspera(fila);

  // Autorizando a decolagem do primeiro avião da fila
  Aviao *primeiro = primeiroAviao(fila);
  if (primeiro != NULL) {
    printf("Autorizando a decolagem do primeiro avião da fila:\n");
    printf("Nome: %s, Identificador: %d\n", primeiro->nome,
           primeiro->identificador);
    removerAviao(fila);
  }

  // Adicionando um avião à fila de espera
  Aviao aviao4 = {"Voo 987", 4};
  inserirAviao(fila, aviao4);
  printf("Avião adicionado à fila de espera.\n");
  printf("Nome: Voo 987, Identificador: 4");
  printf("\n");

  // Listando todos os aviões na fila de espera novamente
  printf("lista de Aviões na fila de espera:\n");
  listarAvioesEspera(fila);

  // Listando as características do primeiro avião da fila
  Aviao *primeiroNovo = primeiroAviao(fila);
  if (primeiroNovo != NULL) {
    printf("Características do primeiro avião da fila:\n");
    printf("Nome: %s, Identificador: %d\n", primeiroNovo->nome,
           primeiroNovo->identificador);
  }

  // Liberando a memória alocada pela fila
  destruirFila(fila);

  return 0;
}