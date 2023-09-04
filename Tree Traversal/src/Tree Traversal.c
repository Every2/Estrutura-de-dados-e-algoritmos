#include <stdio.h>
#include <stdlib.h>

typedef struct Node Node;

struct Node {
    int item;
    Node* left;
    Node* right;
};

void inOrderTraversal(Node* root) {
    if (root == NULL) return;
    inOrderTraversal(root->left);
    printf("%d-> ", root->item);
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    if (root == NULL) return;
    printf("%d-> ",  root->item);
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if (root == NULL) return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    printf("%d-> ", root->item);
}

Node* createNode(int value) {
    Node* newNode = malloc(sizeof(Node));
    newNode->item = value;
    newNode->left = NULL;
    newNode->right =  NULL;

    return newNode;
}

Node* insertLeft(Node* root, int value) {
    root->left = createNode(value);
    return root->left;
}

Node* insertRight(Node* root, int value) {
    root->right = createNode(value);
    return root->right;
}
