#include <stdio.h>
#include <stdlib.h>

typedef struct Stack stackType;

struct Stack {
    int top;
    int capacity;
    int* array;
};

stackType* createStack(int capacity) {
    stackType* stack = (stackType*)malloc(sizeof(stackType));
    stack->capacity = capacity;
    stack->top = - 1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

int isFull(stackType* stack) {
    return stack->top == stack->capacity - 1;
}

int isEmpty(stackType* stack) {
    return stack->top == -1;
}

void push(stackType* stack, int element) {
    if(isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = element;
    printf("%d pushed to stack\n", element);
}

int pop(stackType* stack) {
    if(isEmpty(stack)) {
        return INT_MIN;
    }
    return stack->array[stack->top - 1];
}

int showTop(stackType* stack) {
    if(isEmpty(stack)) {
        return INT_MIN;
    }
    return stack->array[stack->top];
}

void destroyStack(stackType* stack) {
    free(stack->array); 
    free(stack);         
}
