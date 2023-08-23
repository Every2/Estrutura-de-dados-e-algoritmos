#include <stdio.h>

#define MAX_SIZE 100

typedef struct CircularQueue typeCircularQ;

struct CircularQueue {
    int element[MAX_SIZE];
    int front;
    int rear;
};

void initialize(typeCircularQ* queue) {
    queue->front = queue->rear = -1;
}

int isEmpty(typeCircularQ* queue) {
    return (queue->front == -1 && queue->rear == -1);
}

int isFull(typeCircularQ* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(typeCircularQ *queue, int value) {
    if (isFull(queue)) {
        printf("Queue is full\n");
    }
    else {
        if (isEmpty(queue)) {
            queue->front = queue->rear = 0;
        }
        else {
            queue->rear = (queue->rear + 1) % MAX_SIZE; 
        }
        queue->element[queue->rear] = value;
    }
}

int dequeue(typeCircularQ* queue) {
    int removedElement;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        return -1;
    }
    else {
        removedElement = queue->element[queue->front];
        if (queue->front == queue->rear) {
            queue->front = queue->rear = -1;
        }
        else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        return removedElement;
    }
}

void display(typeCircularQ* queue) {
    int i;
    if (isEmpty(queue))
        printf("Empty Queue\n");
    else {
        printf("\n Front -> %d ", (queue->front + 1) % MAX_SIZE);
        printf("\n Items -> ");
        for (i = queue->front; i != queue->rear; i = (i + 1) % MAX_SIZE) {
            printf("%d ", queue->element[i]);
        }
        printf("%d ", queue->element[i]);
        printf("\n Rear -> %d \n", (queue->rear + 1) % MAX_SIZE); 
    }
}

