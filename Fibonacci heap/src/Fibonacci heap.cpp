#include <iostream>
#include <cmath>
#include <memory>

struct Node {
    int key;
    int degree;
    std::shared_ptr<Node> parent;
    std::shared_ptr<Node> child;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;
    char mark;
    char childCut;
};

class FibonacciHeap {

public:

    FibonacciHeap() {
        heapRoot = initializeHeap();
    }

    std::shared_ptr<Node> initializeHeap() {
        return nullptr;
    }

    void link(std::shared_ptr<Node> root1, std::shared_ptr<Node> nodeToLink, std::shared_ptr<Node> root2) {
        (nodeToLink->left)->right = nodeToLink->right;
        (nodeToLink->right)->left = nodeToLink->left;
        if (root2->right == root2)
            root1 = root2;
        nodeToLink->left = nodeToLink;
        nodeToLink->right = nodeToLink;
        nodeToLink->parent = root2;

        if (root2->child == nullptr)
            root2->child = nodeToLink;

        nodeToLink->right = root2->child;
        nodeToLink->left = (root2->child)->left;
        ((root2->child)->left)->right = nodeToLink;
        (root2->child)->left = nodeToLink;

        if (nodeToLink->key < (root2->child)->key)
            root2->child = nodeToLink;
        root2->degree++;
    }

    std::shared_ptr<Node> createNode(int value) {
        auto newNode = std::make_shared<Node>();
        newNode->key = value;
        return newNode;
    }

    std::shared_ptr<Node> insert(std::shared_ptr<Node> heapRoot, std::shared_ptr<Node> newNode) {
        newNode->degree = 0;
        newNode->parent = nullptr;
        newNode->child = nullptr;
        newNode->left = newNode;
        newNode->right = newNode;
        newNode->mark = 'F';
        newNode->childCut = 'N';
        if (heapRoot != nullptr) {
            (heapRoot->left)->right = newNode;
            newNode->right = heapRoot;
            newNode->left = heapRoot->left;
            heapRoot->left = newNode;
            if (newNode->key < heapRoot->key)
                heapRoot = newNode;
        }
        else {
            heapRoot = newNode;
        }
        heapSize = heapSize + 1;
        return heapRoot;
    }

    std::shared_ptr<Node> Union(std::shared_ptr<Node> heap1, std::shared_ptr<Node> heap2) {
        std::shared_ptr<Node> nextPointer;
        auto newHeap {initializeHeap()};
        newHeap = heap1;
        (newHeap->left)->right = heap2;
        (heap2->left)->right = newHeap;
        nextPointer = newHeap->left;
        newHeap->left = heap2->left;
        heap2->left = nextPointer;
        return newHeap;
    }

    std::shared_ptr<Node> extractMin(std::shared_ptr<Node> heapRoot) {
        std::shared_ptr<Node> current;
        std::shared_ptr<Node> nodeToextract;
        std::shared_ptr<Node> minNode {heapRoot};
        current = minNode;
        nodeToextract = minNode;
        if (minNode == nullptr)
            return minNode;

        std::shared_ptr<Node> childNode;
        std::shared_ptr<Node> nextNode;

        childNode = nullptr;

        if (minNode->child != nullptr)
            childNode = minNode->child;

        if (childNode != nullptr) {
            nodeToextract = childNode;
            do {
                nextNode = childNode->right;
                (heapRoot->left)->right = childNode;
                childNode->right = heapRoot;
                childNode->left = heapRoot->left;
                heapRoot->left = childNode;
                if (childNode->key < heapRoot->key)
                    heapRoot = childNode;

                childNode->parent = nullptr;
                childNode = nextNode;
            } while (nextNode != nodeToextract);
        }

        (minNode->left)->right = minNode->right;
        (minNode->right)->left = minNode->left;
        heapRoot = minNode->right;

        if (minNode == minNode->right && minNode->child == nullptr)
            heapRoot = nullptr;
        else {
            heapRoot = minNode->right;
            consolidate(heapRoot);
        }
        heapSize = heapSize - 1;
        return current;
    }

    void consolidate(std::shared_ptr<Node> heapRoot) {
        int degree, i;
        float f {(log(heapSize)) / (log(2))};
        int D {f};
        std::shared_ptr<Node> A[100];

        for (i = 0; i <= D; i++)
            A[i] = nullptr;

        std::shared_ptr<Node> currentNode = heapRoot;
        std::shared_ptr<Node> tempNode;
        std::shared_ptr<Node> nextNode;
        std::shared_ptr<Node> pt = currentNode;

        do {
            pt = pt->right;
            degree = currentNode->degree;

            while (A[degree] != nullptr) {
                tempNode = A[degree];

                if (currentNode->key > tempNode->key) {
                    nextNode = currentNode;
                    currentNode = tempNode;
                    tempNode = nextNode;
                }

                if (tempNode == heapRoot)
                    heapRoot = currentNode;
                link(heapRoot, tempNode, currentNode);
                if (currentNode->right == currentNode)
                    heapRoot = currentNode;
                A[degree] = nullptr;
                degree = degree + 1;
            }

            A[degree] = currentNode;
            currentNode = currentNode->right;

        } while (currentNode != heapRoot);
        heapRoot = nullptr;
        for (int j = 0; j <= D; j++) {
            if (A[j] != nullptr) {
                A[j]->left = A[j];
                A[j]->right = A[j];
                if (heapRoot != nullptr) {
                    (heapRoot->left)->right = A[j];
                    A[j]->right = heapRoot;
                    A[j]->left = heapRoot->left;
                    heapRoot->left = A[j];
                    if (A[j]->key < heapRoot->key)
                        heapRoot = A[j];
                }
                else {
                    heapRoot = A[j];
                }
                if (heapRoot == nullptr)
                    heapRoot = A[j];
                else if (A[j]->key < heapRoot->key)
                    heapRoot = A[j];
            }
        }
    }

    void display(std::shared_ptr<Node> heapRoot) {
        std::shared_ptr<Node> current = heapRoot;
        if (current == nullptr) {
            std::cout << "The Heap is Empty" << '\n';
        }
        std::cout << "The root nodes of Heap are: " << '\n';

        do {
            std::cout << current->key;
            current = current->right;
            if (current != heapRoot) {
                std::cout << "-->";
            }
        } while (current != heapRoot && current->right != nullptr);
        std::cout << '\n';
    }

    std::shared_ptr<Node> find(std::shared_ptr<Node> heapRoot, int k) {
        std::shared_ptr<Node> current = heapRoot;
        current->childCut = 'Y';
        std::shared_ptr<Node> foundNode = nullptr;
        if (current->key == k) {
            foundNode = current;
            current->childCut = 'N';
            return foundNode;
        }

        if (foundNode == nullptr) {
            if (current->child != nullptr)
                foundNode = find(current->child, k);
            if ((current->right)->childCut != 'Y')
                foundNode = find(current->right, k);
        }

        current->childCut = 'N';
        return foundNode;
    }

    int decreaseKey(std::shared_ptr<Node> heap_root, int x, int new_key) {
        std::shared_ptr<Node> parent_node;
        if (heap_root == nullptr) {
            std::cout << "A Heap está Vazia" << '\n';
            return 0;
        }
        std::shared_ptr<Node> found_node = find(heap_root, x);
        if (found_node == nullptr) {
            std::cout << "Nó não encontrado na Heap" << '\n';
            return 1;
        }

        if (found_node->key < new_key) {
            std::cout << "Chave inserida é maior que a chave atual" << '\n';
            return 0;
        }
        found_node->key = new_key;
        parent_node = found_node->parent;
        if (parent_node != nullptr && found_node->key < parent_node->key) {
            cut(heap_root, found_node, parent_node);
            cascadeCut(heap_root, parent_node);
        }

        if (found_node->key < heap_root->key)
            heap_root = found_node;

        return 0;
    }

    int deleteKey(std::shared_ptr<Node> heap_root, int k) {
        std::shared_ptr<Node> node_pointer = nullptr;
        int t;
        t = decreaseKey(heap_root, k, -5000);
        if (!t)
            node_pointer = extractMin(heap_root);
        if (node_pointer != nullptr)
            std::cout << "Chave Deletada" << '\n';
        else
            std::cout << "Chave não Deletada" << '\n';
        return 0;
    }

    void cut(std::shared_ptr<Node> heap_root, std::shared_ptr<Node> node_to_cut, std::shared_ptr<Node> parent_node) {
        if (node_to_cut == node_to_cut->right)
            parent_node->child = nullptr;
        (node_to_cut->left)->right = node_to_cut->right;
        (node_to_cut->left)->left = node_to_cut->left;
        if (node_to_cut == parent_node->child)
            parent_node->child = node_to_cut->right;
        parent_node->degree = parent_node->degree - 1;
        node_to_cut->right = node_to_cut;
        node_to_cut->left = node_to_cut;
        (heap_root->left)->right = node_to_cut;
        node_to_cut->right = heap_root;
        node_to_cut->left = heap_root->left;
        heap_root->left = node_to_cut;
        node_to_cut->parent = nullptr;
        node_to_cut->mark = 'F';
    }

    void cascadeCut(std::shared_ptr<Node> heap_root, std::shared_ptr<Node> parent_node) {
        std::shared_ptr<Node> grandparent_node = parent_node->parent;
        if (grandparent_node != nullptr) {
            if (parent_node->mark == 'F') {
                parent_node->mark = 'T';
            }
            else {
                cut(heap_root, parent_node, grandparent_node);
                cascadeCut(heap_root, grandparent_node);
            }
        }
    }

private:
    int heapSize;
    std::shared_ptr<Node> heapRoot;
};
