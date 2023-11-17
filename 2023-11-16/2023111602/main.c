#include "vetor.h"
#include <stdio.h>

int main() {
  Vetor vetor1 = {5.0, 10.0, 9.0};
  Vetor vetor2 = {8.0, 12.0, 8.0};
  Vetor resultado_soma;
  float resultado_escalar;

  // Chama a função soma e exibe o resultado
  soma(&vetor1, &vetor2, &resultado_soma);
  printf("Soma: (%.2f, %.2f, %.2f)\n", resultado_soma.x, resultado_soma.y,
         resultado_soma.z);

  // Chama a função produto_escalar e exibe o resultado
  resultado_escalar = produto_escalar(&vetor1, &vetor2);
  printf("Produto Escalar: %.2f\n", resultado_escalar);

  return 0;
}