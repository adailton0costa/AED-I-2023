#ifndef CUBO_H_INCLUDED
#define CUBO_H_INCLUDED

typedef struct{
    int tam;
    int area;
    int vol;
}CUBO;

CUBO * criarcubo(int aresta);

void liberarcubo(CUBO * c);
void acessarvalores(CUBO c, int * t, int * a, int * v);

#endif // CUBO_H_INCLUDED