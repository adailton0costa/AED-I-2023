#include <stdio.h>

int maior(int v[], int n) {
    int x;
    if (n == 1)
        return v[0];
    else {
        x = maior(v, n - 1);
        if (x > v[n - 1])
            return x;
        else
            return v[n - 1];
    }
}

int menor(int v[], int n) {
    int x;
    if (n == 1)
        return v[0];
    else {
        x = menor(v, n - 1);
        if (x < v[n - 1])
            return x;
        else
            return v[n - 1];
    }
}

int soma(int v[], int n) {
    if (n == 0)
        return 0;
    else
        return v[n - 1] + soma(v, n - 1);
}

int produto(int v[], int n) {
    if (n == 0)
        return 1; // Inicia com 1 para não afetar o produto
    else
        return v[n - 1] * produto(v, n - 1);
}

int main() {
    int v[] = {1, 2, 3, 40, 5, 6, 7, 8, 9, 10};

    printf("Maior: %d\n", maior(v, 10));
    printf("Menor: %d\n", menor(v, 10));
    printf("Soma: %d\n", soma(v, 10));
    printf("Produto: %d\n", produto(v, 10));

    return 0;
}