#include <stdio.h>
#include <stdlib.h>

typedef struct MaxHeap Heap;

struct MaxHeap {
    int* array;
    int capacity;
    int size;
};

Heap* createHeap(int capacity) {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    if (!heap) {
        perror("Can't allocate memory to heap");
        exit(EXIT_FAILURE);
    }

    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (int*)malloc(capacity * sizeof(int));
    if (!heap->array) {
        perror("Can't allocate memory to heap");
        exit(EXIT_FAILURE);
    }

    return heap;
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(Heap* heap, int index) {
    int* array = heap->array;
    while (index > 0 && array[index] > array[(index - 1) / 2]) {
        swap(&array[index], &array[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}


void insert(Heap* heap, int key) {
    if (heap->size >= heap->capacity)  {
        printf("Heap is full");
        return;
    }

    heap->array[heap->size] = key;
    heap->size++;

    heapifyUp(heap, heap->size - 1);
}

void heapifyDown(Heap* heap, int index) {
    int* array = heap->array;
    int largest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < heap->size && array[leftChild] > array[largest]) {
        largest = leftChild;
    }

    if (rightChild < heap->size && array[rightChild] > array[largest]) {
        largest = rightChild;
    }

    if (largest != index) {
        swap(&array[index], &array[largest]);
        heapifyDown(heap, largest);
    }
}

int deleteRoot(Heap* heap) {
    if (heap->size <= 0) {
        printf("Heap is empty");
        return -1;
    }

    int root = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;

    heapifyDown(heap, 0);
    
    return root;
}

void printHeap(Heap* heap) {
    printf("Heap: ");
    for (int i = 0; i < heap->size; i++) {
        printf("%d ", heap->array[i]);
    }
    printf("\n");
}
