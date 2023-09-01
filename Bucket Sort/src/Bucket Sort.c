#include <stdio.h>
#include <stdlib.h>

typedef struct Node NodeT;

struct Node {
    int data;
    NodeT* next;
};

void insert(NodeT** bucket, int value) {
    NodeT* newNode = (NodeT *)malloc(sizeof(NodeT));
    newNode->data = value;
    newNode->next = NULL;

    if (*bucket == NULL) {
        *bucket = newNode;
    }
    else {
        NodeT* current = *bucket;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void insertionSort(NodeT* bucket) {
    if (bucket == NULL || bucket->next == NULL) {
        return;
    }

    NodeT* sorted = NULL;
    NodeT* current = bucket;

    while(current != NULL) {
        NodeT* next = current->next;

        if (sorted == NULL || current->data < sorted->data) {
            current->next = sorted;
            sorted = current;
        }
        else {
            NodeT* search = sorted;
            while (search->next != NULL && current->data > search->next->data) {
                search  = search->next;
            }
            current->next = search->next;
            search->next = current;
        }
    current = next;
    }

    current = bucket;
    while (sorted != NULL) {
        current->data = sorted->data;
        current = current->next;
        sorted = sorted->next;
    }
}

void bucketSort(int array[], int size) {
    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    NodeT** buckets = (NodeT **)malloc(sizeof(NodeT) * (max + 1));
    for (int i = 0; i <= max; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < size; i++) {
        int index = array[i];
        insert(&buckets[index], array[i]);
    }

    int index = 0;
    for (int i = 0; i <= max; i++) {
        insertionSort(buckets[i]);
        NodeT* current = buckets[i];
        while (current != NULL) {
            array[index++] = current->data;
            current = current->next;
        }
        free(buckets[i]);
    }
    free(buckets);
}
