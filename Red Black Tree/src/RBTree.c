#include <stdio.h>
#include <stdlib.h>

typedef enum {
    RED,
    BLACK
} Color;

typedef struct Node {
    int data;
    struct Node* parent;
    struct Node* left;
    struct Node* right;
    Color color;
} Node;

Node *createNode(int data) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->parent = NULL;
    newNode->left =  NULL;
    newNode->right =  NULL;
    newNode->color = RED;
    return newNode;
}

void leftRotate(Node **root, Node *x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != NULL)
        y->left->parent = x;
    
    y->parent = x->parent;

    if (x->parent == NULL)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(Node **root, Node *y) {
    Node *x = y->left;
    y->left = x->right;

    if (x->right != NULL)
        x->right->parent = y;
    
    x->parent = y->parent;

    if (y->parent == NULL)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;
    
    x->right = y;
    y->parent = x;
}

void insertFixUp(Node **root, Node *newNode) {
    while (newNode != *root && newNode->parent->color == RED) {
        if (newNode->parent == newNode->parent->parent->left) {
            Node *y = newNode->parent->parent->right;
            if (y != NULL && y->color == RED) {
                newNode->parent->color = BLACK;
                y->color = BLACK;
                newNode->parent->parent->color = RED;
                newNode = newNode->parent->parent;
            }
            else {
                if (newNode == newNode->parent->right) {
                    newNode = newNode->parent;
                    leftRotate(root, newNode);
                }
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                rightRotate(root, newNode->parent->parent);
            }
        } else {
            Node *y = newNode->parent->parent->left;
            if (y != NULL && y->color == RED) {
                newNode->parent->color = BLACK;
                y->color = BLACK;
                newNode->parent->parent->color = RED;
                newNode = newNode->parent->parent;
            }
            else {
                if (newNode == newNode->parent->left) {
                    newNode = newNode->parent;
                    rightRotate(root, newNode);
                }
                newNode->parent->color = BLACK;
                newNode->parent->parent->color = RED;
                leftRotate(root, newNode->parent->parent);
            }
        }
    }
    (*root)->color = BLACK;
}

void insert(Node **root, int data) {
    Node *newNode = createNode(data);
    Node *parent = NULL;
    Node *current = *root;

    while (current != NULL) {
        parent = current;
        if (newNode->data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    newNode->parent = parent;

    if (parent == NULL)
        *root = newNode;
    else if (newNode->data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    insertFixUp(root, newNode);
}

void removeFixup(Node **root, Node *x) {
    while (x != *root && x->color == BLACK) {
        if (x == x->parent->left) {
            Node *w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(root, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            }
            else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(root, x->parent);
                x = *root;
            }
        }
        else {
            Node *w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(root, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == BLACK && w->left->color == BLACK) {
                w->color = RED;
                x = x->parent;
            }
            else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(root, x->parent);
                x = *root;
            }
        }
    }
    x->color = BLACK;
}

Node *findMinimum(Node *node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

void transplant(Node **root, Node *u, Node *v) {
    if (u->right == NULL)
        *root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else 
        u->parent->right = v;

    if  (v != NULL)
        v->parent = u->parent;
}

void removeNode(Node **root, int data) {
    Node *z = *root;
    Node *y;
    Node *x;

    while (z != NULL) {
        if (data == z->data) {
            break;
        }
        if (data < z->data) {
            z = z->left;
        }
        else {
            z = z->right;
        }
    }

    if (z == NULL) {
        return;
    }

    if (z->left == NULL || z->right == NULL) {
        y = z;
    }
    else {
        y = findMinimum(z->right);
    }

    if (y->left != NULL) {
        x = y->left;
    }
    else {
        x = y->right;
    }

    if (x != NULL) {
        x->parent = y->parent;
    }

    if (y->parent == NULL) {
        *root = x;
    }
    else if (y == y->parent->left) {
        y->parent->left = x;
    }
    else {
        y->parent->right = x;
    }

    if (y != z) {
        z->data = y->data;
    }

    if (y->color == BLACK) {
        removeFixup(root, x);
    }

    free(y);
}

void printTreeInOrder(Node* root) {
    if (root != NULL) {
        printTreeInOrder(root->left);
        printf("%d (%s) ", root->data, (root->color == RED) ? "RED" : "BLACK");
        printTreeInOrder(root->right);
    }
}

void printTree(Node* root, int indent) {
    if (root == NULL)
        return;

    if (root->right != NULL) {
        printTree(root->right, indent + 4);
    }

    for (int i = 0; i < indent; i++) {
        printf(" ");
    }

    printf("%d (%s)\n", root->data, (root->color == RED) ? "RED" : "BLACK");

    if (root->left != NULL) {
        printTree(root->left, indent + 4);
    }
}

void destroyTreeRec(Node* root) {
    if (root != NULL) {
        destroyTreeRec(root->left);
        destroyTreeRec(root->right);
        free(root);
    }
}

void destroyTree(Node** root) {
    destroyTreeRec(*root);
    *root = NULL;
}
