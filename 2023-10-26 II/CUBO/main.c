#include "cubo.h"
#include <stdio.h>
#include <stdlib.h>
int main() {
  int tamanho, area, volume;
  CUBO *meuCubo;

  meuCubo = criarcubo(3);
  acessarvalores(*meuCubo, &tamanho, &area, &volume);
  printf("\nTamanho = %d", tamanho);
  printf("\nArea do cubo = %d ", area);
  printf("\nVolume do cubo = %d", volume);

  liberarcubo(meuCubo);

  return 0;
}