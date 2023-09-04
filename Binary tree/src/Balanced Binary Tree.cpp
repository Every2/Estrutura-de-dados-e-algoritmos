#include <iostream>
#include <memory>

struct TreeNode {
    int data;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int checkHeightBalance(std::shared_ptr<TreeNode> root) {
    if (root == nullptr) {
        return 0; 
    }

    int leftHeight = checkHeightBalance(root->left);
    if (leftHeight == -1) {
        return -1; 
    }

    int rightHeight = checkHeightBalance(root->right);
    if (rightHeight == -1) {
        return -1; 
    }

    int heightDiff = std::abs(leftHeight - rightHeight);
    if (heightDiff > 1) {
        return -1; 
    }

    return std::max(leftHeight, rightHeight) + 1; 
}

bool isBalanced(std::shared_ptr<TreeNode> root) {
    return checkHeightBalance(root) != -1;
}
