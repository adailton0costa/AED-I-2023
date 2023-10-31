#include "complexo.h"

Complexo criarComplexo(float real, float imag) {
    Complexo numero;
    numero.real = real;
    numero.imag = imag;
    return numero;
}

void destruirComplexo(Complexo numero) {
  
}

Complexo somarComplexos(Complexo numero1, Complexo numero2) {
    Complexo resultado;
    resultado.real = numero1.real + numero2.real;
    resultado.imag = numero1.imag + numero2.imag;
    return resultado;
}

Complexo subtrairComplexos(Complexo numero1, Complexo numero2) {
    Complexo resultado;
    resultado.real = numero1.real - numero2.real;
    resultado.imag = numero1.imag - numero2.imag;
    return resultado;
}

Complexo multiplicarComplexos(Complexo numero1, Complexo numero2) {
    Complexo resultado;
    resultado.real = numero1.real * numero2.real - numero1.imag * numero2.imag;
    resultado.imag = numero1.real * numero2.imag + numero1.imag * numero2.real;
    return resultado;
}

Complexo dividirComplexos(Complexo numero1, Complexo numero2) {
    Complexo resultado;
    float divisor = numero2.real * numero2.real + numero2.imag * numero2.imag;
    resultado.real = (numero1.real * numero2.real + numero1.imag * numero2.imag) / divisor;
    resultado.imag = (numero1.imag * numero2.real - numero1.real * numero2.imag) / divisor;
    return resultado;
}
