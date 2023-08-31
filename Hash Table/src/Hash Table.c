#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct KeyValue KeyT;
typedef struct HashTable HashT;

struct KeyValue {
    char *key;
    char *value;
    KeyT* next;
};

struct HashTable {
    int size;
    KeyT** table;
};

unsigned int hash(const char *key, int size) {
    unsigned int hash = 0;
    while (*key) {
        hash = (hash + *key) % size;
        key++;
    }

    return hash;
}

HashT* createHashTable(int size) {
    HashT* ht = (HashT*)malloc(sizeof(HashT));
    if (ht == NULL) {
        printf("Error to alloc  memory for Hash table");
        exit(EXIT_FAILURE);
    }

    ht->size = size;
    ht->table = (KeyT**)malloc(sizeof(KeyT *) * size);
    if (ht->table == NULL) {
        printf("Error to alloc  memory for Hash table");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        ht->table[i] = NULL;
    }

    return ht;
}

void insert(HashT* ht, const char *key, const char *value) {
    unsigned int index = hash(key, ht->size);

    KeyT* newNode = (KeyT*)malloc(sizeof(KeyT));
    if (newNode ==  NULL) {
        printf("Error to alloc  memory for Hash table");
        return;
    }

    newNode->key = strdup(key);
    newNode->value = strdup(value);
    newNode->next = NULL;

    KeyT* current = ht->table[index];
    while(current != NULL) {
        if (strcmp(current->key, key) == 0) {
            free(newNode->key);
            free(newNode->value);
            free(newNode);
            current->value = strdup(value);
            return;
        }
        current = current->next;
    }

    newNode->next = ht->table[index];
    ht->table[index] = newNode;
}

const char* lookup(HashT *ht, const char* key) {
    unsigned int index = hash(key, ht->size);

    KeyT* current = ht->table[index];
    while(current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }

    return NULL;
}

void destroyHashTable(HashT* ht) {
    for (int i = 0; i < ht->size; i++) {
        KeyT* current = ht->table[i];
        while (current != NULL) {
            KeyT* temp =  current;
            current = current->next;
            free(temp->key);
            free(temp->value);
            free(temp);
        }
    }
    free(ht->table);
    free(ht);
}
