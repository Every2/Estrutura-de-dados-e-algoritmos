#include <iostream>
#include <memory>
#include <vector>

template <typename T>
class BTreeNode {
public:
    bool is_leaf;
    std::vector<T> keys;
    std::vector<std::shared_ptr<BTreeNode>> children;

    BTreeNode(bool _is_leaf = true) : is_leaf(_is_leaf) {}

    void insert(const T& key) {
        int i = 0;
        while (i < keys.size() && key > keys.at(i)) {
            i++;
        }

        keys.insert(keys.begin() + i, key);
    }
};

template <typename T>
class BTree {
public:
    BTree(int _degree) : degree(_degree), root(nullptr) {}

    bool search(const T& key) {
        return search(root, key);
    }

    void insert(const T& key) {
        if (!root) {
            root = std::make_shared<BTreeNode<T>>();
            root->insert(key);
        } else {
            if (root->keys.size() == (2 * degree - 1)) {
                auto new_root {std::make_shared<BTreeNode<T>>(false)};
                new_root->children.push_back(root);
                splitChild(new_root, 0);
                root = new_root;
            }
            insertNonFull(root, key);
        }
    }

    void inOrderTraversal() {
        inOrderTraversal(root);
    }

private:
    int degree;
    std::shared_ptr<BTreeNode<T>> root;

    bool search(const std::shared_ptr<BTreeNode<T>>& node, const T& key) {
        if (!node) {
            return false;
        }

        int i = 0;
        while (i < node->keys.size() && key > node->keys.at(i)) {
            i++;
        }

        if (i < node->keys.size() && key == node->keys.at(i)) {
            return true;
        } else if (node->is_leaf) {
            return false;
        } else {
            return search(node->children.at(i), key);
        }
    }

    void splitChild(const std::shared_ptr<BTreeNode<T>>& parent, int child_index) {
        auto old_child {parent->children.at(child_index)};
        auto new_child {std::make_shared<BTreeNode<T>>(old_child->is_leaf)};
        parent->keys.insert(parent->keys.begin() + child_index, old_child->keys.at(degree - 1));
        parent->children.insert(parent->children.begin() + child_index + 1, new_child);

        new_child->keys.assign(old_child->keys.begin() + degree, old_child->keys.end());
        old_child->keys.erase(old_child->keys.begin() + degree, old_child->keys.end());

        if (!old_child->is_leaf) {
            new_child->children.assign(old_child->children.begin() + degree, old_child->children.end());
            old_child->children.erase(old_child->children.begin() + degree, old_child->children.end());
        }
    }

    void insertNonFull(std::shared_ptr<BTreeNode<T>>& node, const T& key) {
        int i {static_cast<int>(node->keys.size() - 1)};

        if (node->is_leaf) {
            node->insert(key);
        } else {
            while (i >= 0 && key < node->keys.at(i)) {
                i--;
            }

            i++;
            if (node->children.at(i)->keys.size() == (2 * degree - 1)) {
                splitChild(node, i);
                if (key > node->keys.at(i)) {
                    i++;
                }
            }
            insertNonFull(node->children.at(i), key);
        }
    }

    void deleteKey(std::shared_ptr<BTreeNode<T>>& node, const T& key) {
        if (!node) {
            return;
        }
        int i {0};
        while (i < node->keys.size() && key > node->keys.at(i)) {
            i++;
        }

        if (i < node->keys.size() && key == node->keys.at(i)) {
            node->keys.erase(node->keys.begin() + i);
        }
        else {
            if (!node->is_leaf) {
                deleteKey(node->children.at(i), key);
            }
        }
    }

    void inOrderTraversal(const std::shared_ptr<BTreeNode<T>>& node) {
        if (node) {
            int i {0};
            for (i; i < node->keys.size(); ++i) {
                if (!node->is_leaf) {
                    inOrderTraversal(node->children.at(i));
                }
                std::cout << node->keys.at(i) << " ";
            }
            if (!node->is_leaf) {
                inOrderTraversal(node->children.at(i));
            }
        }
    }
};
