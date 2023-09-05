#include <iostream>
#include <memory>
#include <algorithm>

struct Node {
    int key;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    int height;
};

int height(const std::shared_ptr<Node>& node) {
    if (!node) {
        return false;
    }
    return node->height;
}

std::shared_ptr<Node> newNode(int key) {
    auto node = std::make_shared<Node>();
    node->key = key;
    node->left = nullptr;
    node->right = nullptr;
    node->height = 1;
    return node;
}

std::shared_ptr<Node> rightRotate(std::shared_ptr<Node> y) {
    std::shared_ptr<Node> x = y->left;
    std::shared_ptr<Node> t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = std::max(height(y->left), height(y->right)) + 1;
    x->height = std::max(height(x->left), height(x->right)) + 1;

    return x;
}

std::shared_ptr<Node> leftRotate(std::shared_ptr<Node> x) {
    std::shared_ptr<Node> y = x->right;
    std::shared_ptr<Node> t2 = y->left;

    y->left = x;
    x->right = t2;

    x->height = std::max(height(x->left), height(x->right)) + 1;
    y->height = std::max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(const std::shared_ptr<Node>& node) {
    if (!node) {
        return false;
    }
    return height(node->left) - height(node->right);
}

std::shared_ptr<Node> insertNode(std::shared_ptr<Node> node, int key) {
    if (!node) {
        return newNode(key);
    }

    if (key < node->key) {
        node->left = insertNode(node->left, key);
    } else if (key > node->key) {
        node->right = insertNode(node->right, key);
    } else {
        return node;
    }

    node->height = 1 + std::max(height(node->left), height(node->right));

    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key) {
        return rightRotate(node);
    }
    if (balance < -1 && key > node->right->key) {
        return leftRotate(node);
    }
    if (balance > 1 && key > node->left->key) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && key < node->right->key) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

std::shared_ptr<Node> minValueNode(std::shared_ptr<Node> node) {
    std::shared_ptr<Node> current = node;
    while (current->left) {
        current = current->left;
    }
    return current;
}

std::shared_ptr<Node> deleteNode(std::shared_ptr<Node> root, int key) {
    if (!root) {
        return root;
    }

    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    } else {
        if (!root->left || !root->right) {
            std::shared_ptr<Node> temp = root->left ? root->left : root->right;

            if (!temp) {
                temp = root;
                root = nullptr;
            } else {
                *root = *temp;
            }
        } else {
            std::shared_ptr<Node> temp = minValueNode(root->right);

            root->key = temp->key;

            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root) {
        return root;
    }

    root->height = 1 + std::max(height(root->left), height(root->right));
    int balance = getBalance(root);
    if (balance > 1 && getBalance(root->left) >= 0) {
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->right) <= 0) {
        return leftRotate(root);
    }
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

void printPreOrder(const std::shared_ptr<Node>& root) {
    if (root) {
        std::cout << root->key << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}
