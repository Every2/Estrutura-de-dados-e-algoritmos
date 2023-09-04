#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node Node;

struct Node {
    int item;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right =  NULL;

    return newNode;
}

int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return (1 + countNodes(root->left) +  countNodes(root->right));
}

bool checkComplete(Node* root, int index, int numOfNodes) {
    if (root == NULL) {
        return true;
    }

    if (index >= numOfNodes) {
        return false;
    }

    return (checkComplete(root->left, 2 * index + 1, numOfNodes) && checkComplete(root->right, 2 * index + 2, numOfNodes));
}
