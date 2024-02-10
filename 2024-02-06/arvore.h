// arvore.h

#ifndef ARVORE_H
#define ARVORE_H

// Definindo a estrutura do nó da árvore
typedef struct No {
    int chave;
    struct No* esquerda;
    struct No* direita;
} No;

// Funções do TDA
No* criarArvore();
void inserirElemento(No** raiz, int chave);
void imprimirArvore(No* raiz);
int contarElementos(No* raiz);
No* buscarElemento(No* raiz, int chave);
void preOrdem(No* raiz);
void inOrdem(No* raiz);
void posOrdem(No* raiz);

#endif
