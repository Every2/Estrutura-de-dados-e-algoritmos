#include <iostream>
#include <memory>

struct TreeNode {
    int data;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

void inOrderTraversal(std::shared_ptr<TreeNode> root) {
    if (root == nullptr) {
        return;
    }

    inOrderTraversal(root->left);
    std::cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(std::shared_ptr<TreeNode> root) {
    if (root == nullptr) {
        return;
    }

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data << " ";
}

void preOrderTraversal(std::shared_ptr<TreeNode> root) {
    if (root == nullptr) {
        return;
    }

    std::cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}
