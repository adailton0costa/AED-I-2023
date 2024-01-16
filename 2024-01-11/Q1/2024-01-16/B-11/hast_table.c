#include <stdio.h>
#include <stdlib.h>
#include "hash_table.h"

// Função para criar a tabela hash
HashTable* createHashTable(int size) {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->slots = (Node**)malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        hashTable->slots[i] = NULL;
    }
    return hashTable;
}

// Função hash
int hash(int key) {
    return (2 * key + 5) % M;
}

// Função para inserir um nó na tabela hash
void insert(HashTable* hashTable, int key) {
    // Calcula o índice usando a função hash
    int index = hash(key);

    // Cria um novo nó
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;

    // Insere o nó na tabela hash
    if (hashTable->slots[index] == NULL) {
        hashTable->slots[index] = newNode;
    } else {
        Node* curr = hashTable->slots[index];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// Função para imprimir a tabela hash
void printHashTable(HashTable* hashTable) {
    for (int i = 0; i < M; i++) {
        printf("- %d: ", i);
        Node* curr = hashTable->slots[i];
        while (curr != NULL) {
            printf("%d -> ", curr->key);
            curr = curr->next;
        }
        printf("NULL\n");
    }
}

// Função para liberar a memória alocada pela tabela hash
void freeHashTable(HashTable* hashTable) {
    for (int i = 0; i < M; i++) {
        Node* curr = hashTable->slots[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(hashTable->slots);
    free(hashTable);
}