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

bool isFullBinaryTree(Node* root) {
    if (root == NULL) {
        return true;
    }

    if  (root->left == NULL  && root->right == NULL) {
        return true;
    }

    if ((root->left) && (root->right)) {
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
    }

    return false;
}
