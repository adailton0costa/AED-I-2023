#include "complexo.h"
#include <stdio.h>

int main() {
  Complexo z1 = criarComplexo(2.0, 5.0);
  Complexo z2 = criarComplexo(9.0, 7.0);

  Complexo soma = somarComplexos(z1, z2);
  printf("Soma: %.2f + %.2fi\n", soma.real, soma.imag);

  Complexo subtracao = subtrairComplexos(z1, z2);
  printf("Subtração: %.2f + %.2fi\n", subtracao.real, subtracao.imag);

  Complexo multiplicacao = multiplicarComplexos(z1, z2);
  printf("Multiplicação: %.2f + %.2fi\n", multiplicacao.real,
         multiplicacao.imag);

  Complexo divisao = dividirComplexos(z1, z2);
  printf("Divisão: %.2f + %.2fi\n", divisao.real, divisao.imag);

  destruirComplexo(z1);
  destruirComplexo(z2);

  return 0;
}