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

int main() {
  Node *root = NULL;
  root = createNode(1);
  root->left = createNode(2);
  root->right = createNode(3);

  root->left->left = createNode(4);
  root->left->right = createNode(5);
  root->left->right->left = createNode(6);
  root->left->right->right = createNode(7);

  if (isFullBinaryTree(root))
    printf("The tree is a full binary tree\n");
  else
    printf("The tree is not a full binary tree\n");
}

