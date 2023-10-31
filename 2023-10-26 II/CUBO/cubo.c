#include "cubo.h"
#include <math.h>
#include <stdlib.h>

CUBO *criarcubo(int aresta) {
  CUBO *pont = (CUBO *)malloc(sizeof(CUBO));
  pont->tam = aresta;
  pont->area = (6 * aresta * aresta);
  pont->vol = pow(aresta, 3);

  return pont;
}
void liberarcubo(CUBO *c) { free(c); }
void acessarvalores(CUBO c, int *t, int *a, int *v) {
  *t = c.tam;
  *a = c.area;
  *v = c.vol;
}