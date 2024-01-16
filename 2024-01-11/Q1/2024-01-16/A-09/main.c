#include <stdio.h>
#include "hash_table.h"

int main() {
    // Inicializa a tabela hash com ponteiros nulos
    HashTable* hashTable = createHashTable(M);

    // Chaves a serem inseridas
    int keys[] = { 12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5 };
    int numKeys = sizeof(keys) / sizeof(keys[0]);

    // Insere as chaves na tabela hash
    for (int i = 0; i < numKeys; i++) {
        insert(hashTable, keys[i]);
    }

    // Imprime a tabela hash
    printHashTable(hashTable);

    // Libera a memória alocada pela tabela hash
    freeHashTable(hashTable);

    return 0;
}
