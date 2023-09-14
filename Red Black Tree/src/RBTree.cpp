#include <iostream>

enum class Color {
    RED,
    BLACK
};

struct Node {
    int data;
    Node* parent;
    Node* left;
    Node* right;
    Color color;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->parent = nullptr;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->color = Color::RED;
    return newNode;
}

void leftRotate(Node** root, Node* x) {
    Node* y = x->right;
    x->right = y->left;

    if (y->left != nullptr)
        y->left->parent = x;

    y->parent = x->parent;

    if (x->parent == nullptr)
        *root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;

    y->left = x;
    x->parent = y;
}

void rightRotate(Node** root, Node* y) {
    Node* x = y->left;
    y->left = x->right;

    if (x->right != nullptr)
        x->right->parent = y;

    x->parent = y->parent;

    if (y->parent == nullptr)
        *root = x;
    else if (y == y->parent->left)
        y->parent->left = x;
    else
        y->parent->right = x;

    x->right = y;
    y->parent = x;
}

void insertFixUp(Node** root, Node* newNode) {
    while (newNode != *root && newNode->parent->color == Color::RED) {
        if (newNode->parent == newNode->parent->parent->left) {
            Node* y = newNode->parent->parent->right;
            if (y != nullptr && y->color == Color::RED) {
                newNode->parent->color = Color::BLACK;
                y->color = Color::BLACK;
                newNode->parent->parent->color = Color::RED;
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->right) {
                    newNode = newNode->parent;
                    leftRotate(root, newNode);
                }
                newNode->parent->color = Color::BLACK;
                newNode->parent->parent->color = Color::RED;
                rightRotate(root, newNode->parent->parent);
            }
        } else {
            Node* y = newNode->parent->parent->left;
            if (y != nullptr && y->color == Color::RED) {
                newNode->parent->color = Color::BLACK;
                y->color = Color::BLACK;
                newNode->parent->parent->color = Color::RED;
                newNode = newNode->parent->parent;
            } else {
                if (newNode == newNode->parent->left) {
                    newNode = newNode->parent;
                    rightRotate(root, newNode);
                }
                newNode->parent->color = Color::BLACK;
                newNode->parent->parent->color = Color::RED;
                leftRotate(root, newNode->parent->parent);
            }
        }
    }
    (*root)->color = Color::BLACK;
}

void insert(Node** root, int data) {
    Node* newNode = createNode(data);
    Node* parent = nullptr;
    Node* current = *root;

    while (current != nullptr) {
        parent = current;
        if (newNode->data < current->data)
            current = current->left;
        else
            current = current->right;
    }

    newNode->parent = parent;

    if (parent == nullptr)
        *root = newNode;
    else if (newNode->data < parent->data)
        parent->left = newNode;
    else
        parent->right = newNode;

    insertFixUp(root, newNode);
}

void removeFixup(Node** root, Node* x) {
    while (x != *root && x->color == Color::BLACK) {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->color == Color::RED) {
                w->color = Color::BLACK;
                x->parent->color = Color::RED;
                leftRotate(root, x->parent);
                w = x->parent->right;
            }
            if (w->left->color == Color::BLACK && w->right->color == Color::BLACK) {
                w->color = Color::RED;
                x = x->parent;
            } else {
                if (w->right->color == Color::BLACK) {
                    w->left->color = Color::BLACK;
                    w->color = Color::RED;
                    rightRotate(root, w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = Color::BLACK;
                w->right->color = Color::BLACK;
                leftRotate(root, x->parent);
                x = *root;
            }
        } else {
            Node* w = x->parent->left;
            if (w->color == Color::RED) {
                w->color = Color::BLACK;
                x->parent->color = Color::RED;
                rightRotate(root, x->parent);
                w = x->parent->left;
            }
            if (w->right->color == Color::BLACK && w->left->color == Color::BLACK) {
                w->color = Color::RED;
                x = x->parent;
            } else {
                if (w->left->color == Color::BLACK) {
                    w->right->color = Color::BLACK;
                    w->color = Color::RED;
                    leftRotate(root, w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = Color::BLACK;
                w->left->color = Color::BLACK;
                rightRotate(root, x->parent);
                x = *root;
            }
        }
    }
    x->color = Color::BLACK;
}

Node* findMinimum(Node* node) {
    while (node->left != nullptr)
        node = node->left;
    return node;
}

void transplant(Node** root, Node* u, Node* v) {
    if (u->right == nullptr)
        *root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;

    if (v != nullptr)
        v->parent = u->parent;
}

void removeNode(Node** root, int data) {
    Node* z = *root;
    Node* y;
    Node* x;

    while (z != nullptr) {
        if (data == z->data) {
            break;
        }
        if (data < z->data) {
            z = z->left;
        } else {
            z = z->right;
        }
    }

    if (z == nullptr) {
        return;
    }

    if (z->left == nullptr || z->right == nullptr) {
        y = z;
    } else {
        y = findMinimum(z->right);
    }

    if (y->left != nullptr) {
        x = y->left;
    } else {
        x = y->right;
    }

    if (x != nullptr) {
        x->parent = y->parent;
    }

    if (y->parent == nullptr) {
        *root = x;
    } else if (y == y->parent->left) {
        y->parent->left = x;
    } else {
        y->parent->right = x;
    }

    if (y != z) {
        z->data = y->data;
    }

    if (y->color == Color::BLACK) {
        removeFixup(root, x);
    }

    delete y;
}

void printTreeInOrder(Node* root) {
    if (root != nullptr) {
        printTreeInOrder(root->left);
        std::cout << root->data << " (" << ((root->color == Color::RED) ? "RED" : "BLACK") << ") ";
        printTreeInOrder(root->right);
    }
}

void printTree(Node* root, int indent) {
    if (root == nullptr)
        return;

    if (root->right != nullptr) {
        printTree(root->right, indent + 4);
    }

    for (int i = 0; i < indent; i++) {
        std::cout << " ";
    }

    std::cout << root->data << " (" << ((root->color == Color::RED) ? "RED" : "BLACK") << ")" << std::endl;

    if (root->left != nullptr) {
        printTree(root->left, indent + 4);
    }
}

void destroyTreeRec(Node* root) {
    if (root != nullptr) {
        destroyTreeRec(root->left);
        destroyTreeRec(root->right);
        delete root;
    }
}

void destroyTree(Node** root) {
    destroyTreeRec(*root);
    *root = nullptr;
}
