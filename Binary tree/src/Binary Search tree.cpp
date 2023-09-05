#include <iostream>
#include <memory>

struct TreeNode {
    int data;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inOrder(std::shared_ptr<TreeNode> root) {
    if (root != NULL) {
        inOrder(root->left);

        std::cout << root->data << " ";

        inOrder(root->right);
    }
}

std::shared_ptr<TreeNode> insert(std::shared_ptr<TreeNode> root, int key) {
    if (root == nullptr) return std::make_shared<TreeNode>(key);

    if (key < root->data) {
        root->left = insert(root->left, key);
    }
    else {
        root->right = insert(root->right, key);
    }
    return root;
}

std::shared_ptr<TreeNode> minValueofNode(std::shared_ptr<TreeNode> root) {
    std::shared_ptr<TreeNode> current {root};

    while(current && current->left != nullptr)
        current = current->left;

    return current;
}

std::shared_ptr<TreeNode> deleteNode(std::shared_ptr<TreeNode> root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            return root->right;
        }
        else if (root->right == nullptr) {
            return root->left;
        }

        std::shared_ptr<TreeNode> temp = minValueofNode(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
