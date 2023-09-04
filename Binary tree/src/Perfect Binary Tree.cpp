#include <iostream>
#include <memory>

struct TreeNode {
    int data;
    std::shared_ptr<TreeNode> left;
    std::shared_ptr<TreeNode> right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

int depth(std::shared_ptr<TreeNode> root) {
    int d {0};
    while (root != nullptr) {
        d++;
        root = root->left;
    }
    return d;
}

bool checkIfIsPerfect(std::shared_ptr<TreeNode> root, int d, int level) {
    if (root == nullptr) {
        return true;
    }

    if (root->left == nullptr && root->right == nullptr) {
        return (d == level + 1);
    }

    if (root->left == nullptr || root->right == nullptr) {
        return false;
    }

    return checkIfIsPerfect(root->left, d, level + 1) && checkIfIsPerfect(root->right, d, level + 1);
}

bool isPerfect(std::shared_ptr<TreeNode> root)  {
    int d {depth(root)};
    return checkIfIsPerfect(root, d, 0);
}
