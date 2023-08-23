#include <stdio.h>
#include <stdlib.h>

typedef struct Node nodetype;

struct Node {
    int data;
    nodetype* next;
};

void insertAtBeginning(nodetype** head_ref, int new_data) {
    nodetype* newNode = (nodetype*)malloc(sizeof(nodetype));

    newNode->data = new_data;
    newNode->next = (*head_ref);

    (*head_ref) = newNode; 
}

void insertAfter(nodetype* prev_node, int new_data) {
    if (prev_node == NULL) {
        printf("the given previous node cannot be NULL");
        return;
    }

    nodetype* newNode = (nodetype*)malloc(sizeof(nodetype));
    newNode->data = new_data;
    newNode->next = prev_node->next;
    prev_node->next = newNode;
}

void insertAtEnd(nodetype** head_ref, int new_data) {
    nodetype* newNode = (nodetype*)malloc(sizeof(nodetype));
    nodetype* last = *head_ref;

    newNode->data = new_data;
    newNode->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    }

    while (last->next != NULL) last = last->next;

    last->next = newNode;
    return;
}

void deleteNode(nodetype** head_ref, int key) {
    nodetype* temp = *head_ref, *prev;

    if (temp != NULL && temp->data == key) {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while(temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;

    free(temp);
}

int searchNode(nodetype** head_ref, int key)  {
    nodetype* current = *head_ref;

    while (current != NULL) {
        if (current->data == key) return 1;
        current = current->next;
    }
    return 0;
}

void sortLinkedList(nodetype** head_ref) {
    nodetype* current = *head_ref, *index = NULL;
    int temp;

    if (head_ref == NULL) {
        return;
    } 
    else {
        while(current != NULL) {
            index = current->next;

            while(index != NULL) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
                index = index->next;
            }
            current = current->next;
        }
    }
}

void printList(nodetype* node) {
    while (node != NULL) {
        printf(" %d ", node->data);
        node = node->next;
    }
}

