#include <stdio.h>
#include <stdlib.h>

typedef struct Node NodeT;

struct Node {
    int data;
    NodeT* next;
};

NodeT* addToEmpty(NodeT* last, int data) {
    if (last != NULL) return last;

    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->data = data;
    last = newNode;
    last->next = last;

    return last;
}

NodeT* addFront(NodeT* last, int data) {
    if (last == NULL) return addToEmpty(last, data);
    
    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;

    return last;
}

NodeT* addEnd(NodeT* last, int data) {
    if (last == NULL) return addToEmpty(last, data);

    NodeT* newNode = (NodeT*)malloc(sizeof(NodeT));
    newNode->data = data;
    newNode->next = last->next;
    last->next = newNode;

    return last;
}

NodeT* addAfter(NodeT* last, int data, int item) {
    if (last == NULL) return NULL;

    NodeT* newNode, *p;

    p = last->next;
    do {
        if (p->data  == item) {
            newNode = (NodeT*)malloc(sizeof(NodeT));

            newNode->data = data;
            newNode->next = p->next;
            p->next = newNode;

            if (p == last) return last = newNode;
            return last;
        }
        p = p->next;
    } while (p != last->next);

    printf("\nThe given node is not present in the list ");
    return last;
}

void deleteNode(NodeT** last, int key) {
    if (*last == NULL) return;

    if ((*last)->data == key && (*last)->next == *last) {
        free(*last);
        *last = NULL;
        return;
    }

    NodeT* temp = *last, *d;

    if ((*last)->data == key) {
        while(temp->next != *last) temp = temp->next;
        temp->next = (*last)->next;
        free(*last);
        *last = temp->next;
    }

    while(temp->next != *last  && temp->next->data != key) {
        temp = temp->next;
    }

    if (temp->next->data == key) {
        d = temp->next;
        temp->next = d->next;
        free(d);
    }
}

void traverse(NodeT* last) {
    NodeT* p;

    if (last == NULL) {
        printf("the list is empty");
        return;
    }

    p = last->next;

    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != last->next);
}

