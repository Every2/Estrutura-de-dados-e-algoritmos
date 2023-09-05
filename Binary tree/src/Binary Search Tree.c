#include <stdio.h>
#include <stdlib.h>

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

void inOrder(Node* root) {
    if  (root != NULL) {
        inOrder(root->left);

        printf(" %d-> ", root->item);
    
        inOrder(root->right);
    }
}

Node* insert(Node* node, int key) {
    if (node == NULL) return createNode(key);

    if (key < node->item)  {
        node->left = insert(node->left, key);
    }
    else {
        node->right = insert(node->right, key);
    }

    return node;
}

Node* minValueofNode(Node* node) {
    Node* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

Node* deleteNode(Node* root, int key) {
    if (root == NULL) return root;

    if (key < root->item) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->item) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        Node* temp = minValueofNode(root->right);
        root->item = temp->item;
        root->right = deleteNode(root->right, temp->item);
    }
    return root;
}
