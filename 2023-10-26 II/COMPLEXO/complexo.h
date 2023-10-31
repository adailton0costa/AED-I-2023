#ifndef COMPLEXO_H
#define COMPLEXO_H

typedef struct {
    float real;
    float imag;
} Complexo;

Complexo criarComplexo(float real, float imag);
void destruirComplexo(Complexo numero);
Complexo somarComplexos(Complexo numero1, Complexo numero2);
Complexo subtrairComplexos(Complexo numero1, Complexo numero2);
Complexo multiplicarComplexos(Complexo numero1, Complexo numero2);
Complexo dividirComplexos(Complexo numero1, Complexo numero2);

#endif
