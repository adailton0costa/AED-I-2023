#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#define M 11 // Tamanho da tabela hash

// Estrutura para os nós da lista encadeada
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Estrutura para a tabela hash
typedef struct HashTable {
    Node** slots;
} HashTable;

// Função para criar a tabela hash
HashTable* createHashTable(int size);

// Função hash
int hash(int key);

// Função para inserir um nó na tabela hash
void insert(HashTable* hashTable, int key);

// Função para imprimir a tabela hash
void printHashTable(HashTable* hashTable);

// Função para liberar a memória alocada pela tabela hash
void freeHashTable(HashTable* hashTable);

#endif