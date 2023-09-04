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

bool checkHeightBalance(Node* root, int* height) {
    int leftHeight = 0, rightHeight = 1;
    int left = 0, right = 0;

    if (root == NULL)  {
        *height = 0;
        return true;
    }

    left = checkHeightBalance(root->left, &leftHeight);
    right = checkHeightBalance(root->right, &rightHeight);

    *height = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;

    if ((leftHeight - rightHeight >= 2) || (rightHeight - leftHeight >= 2)) {
        return false;
    }
    else {
        return left && right;
    }
}
