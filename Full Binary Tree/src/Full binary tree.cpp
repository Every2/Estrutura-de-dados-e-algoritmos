#include <iostream>
#include <memory>

struct TreeNode {
    int data;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

bool isFullBinaryTree(std::shared_ptr<TreeNode> root) {
    if (root == nullptr) {
        return true;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return true;
    }

    if ((root->left)  && (root->right)) {
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));
    }

    return false;
}
