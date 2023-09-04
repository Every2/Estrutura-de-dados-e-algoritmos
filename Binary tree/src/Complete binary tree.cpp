#include <iostream>
#include <memory>

struct TreeNode {
    int data;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int countNodes(std::shared_ptr<TreeNode> root) {
    if (root == nullptr) {
        return false;
    }

    return (1 + countNodes(root->left) + countNodes(root->right));
}

bool checkComplete(std::shared_ptr<TreeNode> root, int index, int numOfNodes) {
    if (root == nullptr) {
        return true;
    }

    if (index >= numOfNodes) {
        return false;
    }

    return (checkComplete(root->left, 2 * index + 1, numOfNodes) && checkComplete(root->right, 2 * index + 2, numOfNodes));
}
