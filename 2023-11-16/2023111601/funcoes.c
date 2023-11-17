#include "funcoes.h"
#include <math.h>

int k_esimo_digito_recursivo(int n, int k) {
    // Caso base: se k for maior que o número de dígitos, retorna 0
    if (k > 0 && n == 0) {
        return 0;
    }

    // Caso base: se k for 1, retorna o último dígito
    if (k == 1) {
        return n % 10;
    }

    // Chama a função recursivamente com o número sem o último dígito e k decrementado
    return k_esimo_digito_recursivo(n / 10, k - 1);
}

// Função que lida com casos especiais e chama a função recursiva
int k_esimo_digito(int n, int k) {
    // Converte o número para uma string para facilitar a manipulação dos dígitos
    int digitos = floor(log10(n)) + 1;

    // Caso base: se k for maior que o número de dígitos, retorna 0
    if (k > digitos) {
        return 0;
    }

    // Chama a função recursiva para encontrar o k-ésimo dígito
    return k_esimo_digito_recursivo(n, k);
}
