#include <stdio.h>
#include <stdlib.h>

typedef struct Node nodetype;

struct Node {
    int data;
    nodetype* next;
    nodetype* prev;
};

void insertFront(nodetype** head, int data) {
    nodetype* newNode = (nodetype*)malloc(sizeof(nodetype));

    newNode->data = data;
    newNode->next = (*head);
    newNode->prev = NULL;

    if ((*head) != NULL) {
        (*head)->prev = newNode;
    }

    (*head) = newNode;
}

void insertAfter(nodetype* prev_node, int data) {
    if (prev_node == NULL) {
        printf("previous node cannot be null");
        return;
    }

    nodetype* newNode = (nodetype*)malloc(sizeof(nodetype));

    newNode->data = data;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
    newNode->prev = prev_node;

    if (newNode->next !=  NULL)
        newNode->next->prev = newNode;
}

void insertEnd(nodetype** head, int data) {
    nodetype* newNode = (nodetype*)malloc(sizeof(nodetype));

    newNode->data = data;
    newNode->next = NULL;

    nodetype* temp = *head;
    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    while(temp->next != NULL) 
        temp = temp->next;
    
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteNode(nodetype** head, nodetype* del_node) {
    if (*head == NULL || del_node == NULL) {
        return;
    }

    if (*head == del_node)
        *head = del_node->next;
    
    if (del_node->next != NULL) 
        del_node->next->prev = del_node->prev;

    if (del_node->prev != NULL)
        del_node->prev->next = del_node->next;
    
    free(del_node);
}

void printList(nodetype* node) {
    nodetype* last;

    while(node != NULL) {
        printf("%d->", node->data);
        last = node;
        node = node->next;
    }
    if (node == NULL)
        printf("NULL\n");
}
