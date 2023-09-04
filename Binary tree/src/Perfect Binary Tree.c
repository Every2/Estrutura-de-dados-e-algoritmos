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

int depth(Node* node) {
    int d = 0;
    while (node != NULL) {
        d++;
        node = node->left;
    }
    return d;
}

bool checkIfIsPerfect(Node* root, int d, int level)  {
    if (root == NULL) {
        return true;
    }

    if (root->left ==  NULL && root->right == NULL) {
        return (d ==  level + 1);
    }

    if (root->left == NULL || root->right == NULL)  {
        return false;
    }

    return checkIfIsPerfect(root->left, d, level + 1) && checkIfIsPerfect(root->right, d, level + 1);
}

bool isPerfect(Node* root) {
    int d = depth(root);
    return checkIfIsPerfect(root, d, 0);
}
