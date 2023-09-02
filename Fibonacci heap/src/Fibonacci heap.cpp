#include <iostream>
#include <vector>
#include <memory>

class Node : public std::enable_shared_from_this<Node> {

public:
    int key;
    int degree;
    bool mark;
    std::shared_ptr<Node> parent;
    std::shared_ptr<Node> child;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(int k) : key(k), degree(0), mark(false) {}

    void addChild(std::shared_ptr<Node> childNode) {
        if (!child) {
            child = childNode;
            childNode->left = childNode->right  = childNode;
        }
        else {
            childNode->left = child;
            childNode->right = child->right;
            child->right->left = childNode;
            child->right = childNode;
        }
        childNode->parent = shared_from_this();
        degree++;
    }
};

class FibonacciHeap {

public:
    FibonacciHeap() : min(nullptr), numNodes(0) {}

    void insert(int key) {
        auto newNode {std::make_shared<Node>(key)};

        if (!min) {
            min = newNode;
        }
        else {
            newNode->left = min;
            newNode->right = min->right;
            min->right->left = newNode;
            min->right = newNode;
            if (key < min->key) {
                min = newNode;
            }  
        }
        numNodes++;
    }

     void decreaseKey(int oldKey, int newKey) {
        if (!min) {
            return;
        }

        auto nodeToUpdate = findNode(min, oldKey);
        if (!nodeToUpdate) {
            return;
        }   

        nodeToUpdate->key = newKey;
        auto parent {nodeToUpdate->parent};
        if (parent && nodeToUpdate->key  < parent->key) {
            cut(nodeToUpdate, parent);
            cascadingCut(parent);
        }

        if (nodeToUpdate->key < min->key) {
            min = nodeToUpdate;
        }
    }

    int extractMin() {
        if (!min) {
            return -1;
        }

        auto minNode = min;
        if (minNode->child) {
            auto child {minNode->child};
            do {
                auto nextChild = minNode->right;
                minNode->left->right = child;
                child->right = minNode->right;
                minNode->right->left = child;
                child->left = minNode->left;
                if (child->key < minNode->key) {
                    minNode = child;
                }
                child->parent = nullptr;
                child = nextChild;
            } while(child != minNode->child);
        }

        minNode->left->right = minNode->right;
        minNode->right->left = minNode->left;
        if (minNode == minNode->right) {
            min = nullptr;
        }
        else {
            min = minNode->right;
            consolidate();
        }
        numNodes--;
        return minNode->key;
    }

    void deleteNode(int key) {
        decreaseKey(key, INT_MIN);
        extractMin();
    }

private:
    std::shared_ptr<Node> min;
    int numNodes;

    void consolidate() {
        int maxDegree {static_cast<int>(log2(numNodes) + 1)};
        std::vector<std::shared_ptr<Node>> degreeTable(maxDegree, nullptr);

        auto current {min};
        std::vector<std::shared_ptr<Node>> toVisit;
        do {
            toVisit.push_back(current);
            current = current->right;
        } while (current != min);

        for (auto node: toVisit) {
            int degree = node->degree;
            while (degreeTable[degree]) {
                auto other = degreeTable[degree];
                if (node->key > other->key) {
                    std::swap(node, other);
                }
                link(other, node);
                degreeTable[degree] = nullptr;
                degree++;
            }
            degreeTable[degree] = node;
        }
        min = nullptr;
        for (auto node: degreeTable) {
            if (node) {
                if (!min) {
                    min = node;
                }
                else {
                    node->left = min;
                    node->right = min->right;
                    min->right->left = node;
                    min->right = node;
                    if (node->key < min->key) {
                        min = node;
                    }
                }
            }
        }
    }

    void link(std::shared_ptr<Node> y, std::shared_ptr<Node> x) {
        y->left->right = y->right;
        y->right->left = y->left;

        y->left = y->right = y;
        x->addChild(y);
        y->mark =  false;
    }

    void cut(std::shared_ptr<Node> x, std::shared_ptr<Node> y) {
        x->left->right = x->right;
        x->right->left = x->left;

        if (y->child == x) {
            y->child = x->right == x ? nullptr : x->right;
        }

        y->degree--;

        x->left = x->right = x;
        min->left->right = x;
        x->right = min->right;
        min->right->left = x;
        x->left = min;
        x->parent = nullptr;
        x->mark = false;
    }

    void cascadingCut(std::shared_ptr<Node> y) {
        auto z {y->parent};
        if (z) {
            if (!y->mark) {
                y->mark =  true;
            }
            else {
                cut(y, z);
                cascadingCut(z);
            }
        }
    }

    std::shared_ptr<Node> findNode(std::shared_ptr<Node> start, int key) {
        auto current {start};
        std::vector<std::shared_ptr<Node>> toVisit;
        do {
            if  (current->key == key) {
                return current;
            }
            if (current->child) {
                toVisit.push_back(current->child);
            }
            current = current->right;
        } while (current != start);

        for (auto node: toVisit) {
            auto result {findNode(node, key)};
            if (result) {
                return result;
            }
        }      
        return nullptr;
    }
};
