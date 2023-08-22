#include <stdio.h>
#include <stdlib.h>

typedef struct Queue queueType;

struct Queue{
    int* array;
    int size;
    int capacity;
    int front;
    int rear;
};

queueType* createQueue(int capacity) {
    queueType* queue = (queueType*)malloc(sizeof(queueType));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(queueType* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(queueType* queue) {
    return (queue->size == 0);
}

void enqueue(queueType* queue, int item) {
    if (isFull(queue)) {
        return;
    }

    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d enqueued to queue\n", item);
}

int dequeue(queueType* queue) {
    if (isEmpty(queue)) {
        return INT_MIN;
    }

    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(queueType* queue) {
    if (isEmpty(queue)) {
        return INT_MIN;
    }

    return queue->array[queue->front];
}

int rear(queueType* queue) {
    if (isEmpty(queue)) {
        return INT_MIN;
    }

    return queue->array[queue->rear];
}

void destroyQueue(queueType* queue) {
    free(queue->array); 
    free(queue);         
}

int main()
{
    struct Queue* queue = createQueue(4);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    printf("%d dequeued from queue\n\n",
           dequeue(queue));
 
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
 
    destroyQueue(queue);
    return 0;
}