#include <stdlib.h>
#include <stdio.h>

typedef struct PriorityQueue Pqueue;

struct PriorityQueue {
    int *array;
    int capacity;
    int size;
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(Pqueue* pq, int index) {
    int parent = (index - 1) / 2;
    while (index > 0 && pq->array[index] < pq->array[parent]) {
        swap(&pq->array[index], &pq->array[parent]);
        index = parent;
        parent = (index - 1) / 2;
    }
}

void heapifyDown(Pqueue *pq, int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < pq->size  && pq->array[leftChild] < pq->array[smallest]) {
        smallest = leftChild;
    }

    if (rightChild < pq->size && pq->array[rightChild] < pq->array[smallest]) {
        smallest = rightChild;
    }

    if (smallest != index) {
        swap(&pq->array[index], &pq->array[smallest]);
        heapifyDown(pq, smallest);
    }
}

Pqueue* createQueue(int capacity) {
    Pqueue* pq = (Pqueue *)malloc(sizeof(Pqueue));
    pq->capacity  = capacity;
    pq->size = 0;
    pq->array =  (int *)malloc(sizeof(int) * capacity);
    return pq;
}

void push(Pqueue* pq, int item) {
    if (pq->size == pq->capacity) {
        printf("Queue is full");
        return;
    }

    pq->array[pq->size] = item;
    pq->size++;
    heapifyUp(pq, pq->size - 1);
}

int pop(Pqueue* pq) {
    if (pq->size == 0) {
        printf("Queue is empty");
        return -1;
    }

    int root = pq->array[0];
    pq->array[0] = pq->array[pq->size - 1];
    pq->size--;
    heapifyDown(pq, 0);
    return root;
}

int peek(Pqueue* pq) {
    if (pq->size == 0) {
        printf("Queue is empty"); 
        return -1;    
    }
    return pq->array[0];
}

void destroyQueue(Pqueue* pq) {
    free(pq->array);
    free(pq);
}
