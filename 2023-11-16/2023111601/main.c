#include <stdio.h>
#include "funcoes.h"

int main() {
    // Exemplo de uso
    int numero = 2845;
    int k_valor = 3;

    // Chama a função e exibe o resultado
    int resultado = k_esimo_digito(numero, k_valor);
    printf("O %d-ésimo dígito de %d é %d\n", k_valor, numero, resultado);

    return 0;
}