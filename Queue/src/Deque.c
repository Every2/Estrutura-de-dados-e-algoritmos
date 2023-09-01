#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Deque DequeT;

struct Deque {
    int array[MAX_SIZE];
    int front, rear;
};

DequeT* createDeque() {
    DequeT* deque = (DequeT *)malloc(sizeof(DequeT));
    deque->front = -1;
    deque->rear = -1;
    return deque;
}

int isFull(DequeT* deque) {
    return ((deque->front == 0 && deque->rear == MAX_SIZE - 1) || (deque->front == deque->rear + 1));
}

int isEmpty(DequeT* deque) {
    return (deque->front == -1);
}

void insertFront(DequeT* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full");
        return;
    }

    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    }
    else if (deque->front == 0) {
        deque->front = MAX_SIZE - 1;
    }
    else {
        deque->front--;
    }
    deque->array[deque->front] = value;
}

void insertRear(DequeT* deque, int value) {
    if (isFull(deque)) {
        printf("Deque is full");
        return;
    }

    if (deque->front == -1) {
        deque->front = 0;
        deque->rear = 0;
    } 
    else if (deque->rear == MAX_SIZE - 1)  {
        deque->rear = 0;
    }
    else {
        deque->rear++;
    }

    deque->array[deque->rear] = value;    
}

int deleteFront(DequeT* deque)  {
    if (isEmpty(deque)) {
        printf("Deque is empty");
        return -1;
    }

    int value = deque->array[deque->front];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    }
    else if (deque->front == MAX_SIZE - 1) {
        deque->front = 0;
    }
    else {
        deque->front++;
    }
    return value;
}

int deleteRear(DequeT* deque) {
    if (isEmpty(deque)) {
        printf("The deque is empty");
        return -1;
    }

    int value = deque->array[deque->rear];

    if (deque->front == deque->rear) {
        deque->front = -1;
        deque->rear = -1;
    }
    else if (deque->rear == 0) {
        deque->rear = MAX_SIZE - 1;
    }
    else {
        deque->rear--;
    }

    return value;
}

int getFront(DequeT* deque) {
    if (isEmpty(deque)) {
        printf("The deque is empty");
        return -1;
    }

    return deque->array[deque->front];
}

int getRear(DequeT* deque) {
    if (isEmpty(deque)) {
        printf("The deque is empty");
        return -1;
    }

    return deque->array[deque->rear];
}

void destroyDeque(DequeT* deque) {
    free(deque);
}
