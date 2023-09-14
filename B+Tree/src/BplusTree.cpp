#include <iostream>
#include <vector>

const int ORDER = 3;
const int ARRAY_SIZE = 100;

class Record {

public:
    int value;

    Record(int val) : value(val) {}
};

class Node {

public:
    void** pointers;
    int* keys;
    Node* parent;
    bool is_leaf;
    int num_keys;
    Node* next;

    Node() {
        pointers = new void*[ORDER];
        keys = new int[ORDER - 1];
        parent = nullptr;
        is_leaf = false;
        num_keys = 0;
        next = nullptr;
    }

    ~Node() {
        delete[] pointers;
        delete[] keys;
    }
};

class BPlusTree {

public:

    int order;
    Node* root;
    bool verbose_output;
    Node* queue;

    BPlusTree() : order(ORDER), root(nullptr), verbose_output(false), queue(nullptr) {}

    ~BPlusTree() {
        if (root != nullptr) {
            destroyTree(root);
        }
    }

    void destroyTree(Node* node) {
        if (node->is_leaf) {
            delete node;
        } else {
            for (int i {0}; i < node->num_keys + 1; ++i) {
                destroyTree(reinterpret_cast<Node*>(node->pointers[i]));
            }
            delete node;
        }
    }

    void enqueue(Node* new_node) {
        if (queue == nullptr) {
            queue = new_node;
            queue->next = nullptr;
        } else {
            Node* current = queue;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_node;
            new_node->next = nullptr;
        }
    }

    Node* dequeue() {
        Node* n {queue};
        queue = queue->next;
        n->next = nullptr;
        return n;
    }

    int height(Node* root) {
        int h {0};
        Node* current = root;
        while (!current->is_leaf) {
            current = reinterpret_cast<Node*>(current->pointers[0]);
            h++;
        }
        return h;
    }

    int pathToLeaves(Node* root, Node* child) {
        int length {0};
        Node* current {child};
        while (current != root) {
            current = current->parent;
            length++;
        }
        return length;
    }

    void printLeaves(Node* root) {
        if (root == nullptr) {
            std::cout << "Empty tree." << '\n';
            return;
        }

        int i{};
        Node* current {root};
        while (!current->is_leaf) {
            current = reinterpret_cast<Node*>(current->pointers[0]);
        }

        while (true) {
            for (i = 0; i < current->num_keys; ++i) {
                if (verbose_output) {
                    std::cout << current->pointers[i] << " ";
                }
                std::cout << current->keys[i] << " ";
            }

            if (verbose_output) {
                std::cout << current->pointers[order - 1];
            }

            if (current->pointers[order - 1] != nullptr) {
                std::cout << " | ";
                current = reinterpret_cast<Node*>(current->pointers[order - 1]);
            } else {
                break;
            }
        }
        std::cout << '\n';
    }

    void printTree(Node* root) {
        Node* n = nullptr;
        int i {0};
        int rank {0};
        int new_rank {0};

        if (root == nullptr) {
            std::cout << "Empty tree." << '\n';
            return;
        }

        queue = nullptr;
        enqueue(root);

        while (queue != nullptr) {
            n = dequeue();
            if (n->parent != nullptr && n == reinterpret_cast<Node*>(n->parent->pointers[0])) {
                new_rank = pathToLeaves(root, n);
                if (new_rank != rank) {
                    rank = new_rank;
                    std::cout << '\n';
                }
            }

            if (verbose_output) {
                std::cout << "(" << n << ")";
            }

            for (i = 0; i < n->num_keys; ++i) {
                if (verbose_output) {
                    std::cout << n->pointers[i] << " ";
                }
                std::cout << n->keys[i] << " ";
            }

            if (!n->is_leaf) {
                for (i = 0; i <= n->num_keys; ++i) {
                    enqueue(reinterpret_cast<Node*>(n->pointers[i]));
                }
            }

            if (verbose_output) {
                if (n->is_leaf) {
                    std::cout << n->pointers[order - 1];
                } else {
                    std::cout << n->pointers[n->num_keys];
                }
            }
            std::cout << "| ";
        }
        std::cout << '\n';
    }

    void findAndPrint(Node* root, int key) {
        Node* leaf = nullptr;
        Record* r = find(root, key, nullptr);
        if (r == nullptr) {
            std::cout << "Record not found under key " << key << "." << '\n';
        } else {
            std::cout << "Record with key " << key << " has value " << r->value << "." << '\n';
        }
    }

    void findAndPrintRange(Node* root, int key_start, int key_end) {
        int i;
        int returned_keys[ARRAY_SIZE];
        void* returned_pointers[ARRAY_SIZE];
        int num_found = findRange(root, key_start, key_end, returned_keys, returned_pointers);
        if (num_found == 0) {
            std::cout << "None found." << '\n';
        } else {
            for (i = 0; i < num_found; ++i) {
                std::cout << "Key: " << returned_keys[i] << '\n';
            }
        }
    }

    int findRange(Node* root, int key_start, int key_end, int returned_keys[], void* returned_pointers[]) {
        int i, num_found;
        num_found = 0;
        Node* n = findLeaf(root, key_start);

        if (n == nullptr) {
            return 0;
        }

        for (i = 0; i < n->num_keys && n->keys[i] < key_start; ++i)
            ;

        if (i == n->num_keys) {
            return 0;
        }

        while (n != nullptr) {
            for (; i < n->num_keys && n->keys[i] <= key_end; ++i) {
                returned_keys[num_found] = n->keys[i];
                returned_pointers[num_found] = n->pointers[i];
                num_found++;
            }
            n = reinterpret_cast<Node*>(n->pointers[order - 1]);
            i = 0;
        }

        return num_found;
    }

    Node* findLeaf(Node* root, int key) {
        if (root == nullptr) {
            return nullptr;
        }

        int i = 0;
        Node* current = root;
        while (!current->is_leaf) {
            if (verbose_output) {
                std::cout << "[";
                for (i = 0; i < current->num_keys - 1; ++i) {
                    std::cout << current->keys[i] << " ";
                }
                std::cout << current->keys[i] << "] ";
            }
            i = 0;
            while (i < current->num_keys) {
                if (key >= current->keys[i]) {
                    i++;
                } else {
                    break;
                }
            }
            if (verbose_output) {
                std::cout << i << " ->" << '\n';
            }
            current = reinterpret_cast<Node*>(current->pointers[i]);
        }
        if (verbose_output) {
            std::cout << "Leaf [";
            for (i = 0; i < current->num_keys - 1; ++i) {
                std::cout << current->keys[i] << " ";
            }
            std::cout << current->keys[i] << "] ->" << '\n';
        }
        return current;
    }

    Record* find(Node* root, int key, Node** leaf_out) {
        if (root == nullptr) {
            if (leaf_out != nullptr) {
                *leaf_out = nullptr;
            }
            return nullptr;
        }

        int i {0};
        Node* leaf {nullptr};

        leaf = findLeaf(root, key);

        for (i = 0; i < leaf->num_keys; ++i) {
            if (leaf->keys[i] == key) {
                break;
            }
        }

        if (leaf_out != nullptr) {
            *leaf_out = leaf;
        }

        if (i == leaf->num_keys) {
            return nullptr;
        } else {
            return reinterpret_cast<Record*>(leaf->pointers[i]);
        }
    }

    int cut(int length) {
        if (length % 2 == 0) {
            return length / 2;
        } else {
            return length / 2 + 1;
        }
    }

    Record* makeRecord(int value) {
        return new Record(value);
    }

    Node* makeNode() {
        return new Node();
    }

    Node* makeLeaf() {
        Node* leaf {makeNode()};
        leaf->is_leaf = true;
        return leaf;
    }

    int getLeftIndex(Node* parent, Node* left) {
        int left_index {0};
        while (left_index <= parent->num_keys && parent->pointers[left_index] != left) {
            left_index++;
        }
        return left_index;
    }

    Node* insertIntoLeaf(Node* leaf, int key, Record* pointer) {
        int i, insertion_point;

        insertion_point = 0;
        while (insertion_point < leaf->num_keys && leaf->keys[insertion_point] < key) {
            insertion_point++;
        }

        for (i = leaf->num_keys; i > insertion_point; i--) {
            leaf->keys[i] = leaf->keys[i - 1];
            leaf->pointers[i] = leaf->pointers[i - 1];
        }
        leaf->keys[insertion_point] = key;
        leaf->pointers[insertion_point] = pointer;
        leaf->num_keys++;
        return leaf;
    }

    Node* insertIntoLeafAfterSplitting(Node* root, Node* leaf, int key, Record* pointer) {
        Node* new_leaf;
        int* temp_keys;
        void** temp_pointers;
        int insertion_index, split, new_key, i, j;

        new_leaf = makeLeaf();

        temp_keys = new int[order];
        temp_pointers = new void*[order];

        insertion_index = 0;
        while (insertion_index < order - 1 && leaf->keys[insertion_index] < key) {
            insertion_index++;
        }

        for (i = 0, j = 0; i < leaf->num_keys; ++i, ++j) {
            if (j == insertion_index) {
                j++;
            }
            temp_keys[j] = leaf->keys[i];
            temp_pointers[j] = leaf->pointers[i];
        }

        temp_keys[insertion_index] = key;
        temp_pointers[insertion_index] = pointer;

        leaf->num_keys = 0;

        split = cut(order - 1);

        for (i = 0; i < split; ++i) {
            leaf->pointers[i] = temp_pointers[i];
            leaf->keys[i] = temp_keys[i];
            leaf->num_keys++;
        }

        for (i = split, j = 0; i < order; ++i, ++j) {
            new_leaf->pointers[j] = temp_pointers[i];
            new_leaf->keys[j] = temp_keys[i];
            new_leaf->num_keys++;
        }

        delete[] temp_pointers;
        delete[] temp_keys;

        new_leaf->pointers[order - 1] = leaf->pointers[order - 1];
        leaf->pointers[order - 1] = new_leaf;

        for (i = leaf->num_keys; i < order - 1; ++i) {
            leaf->pointers[i] = nullptr;
        }
        for (i = new_leaf->num_keys; i < order - 1; ++i) {
            new_leaf->pointers[i] = nullptr;
        }

        new_leaf->parent = leaf->parent;
        new_key = new_leaf->keys[0];

        return insertIntoParent(root, leaf, new_key, new_leaf);
    }

    Node* insertIntoNode(Node* root, Node* parent, int left_index, int key, Node* right) {
        int i;

        for (i = parent->num_keys; i > left_index; i--) {
            parent->pointers[i + 1] = parent->pointers[i];
            parent->keys[i] = parent->keys[i - 1];
        }
        parent->pointers[left_index + 1] = right;
        parent->keys[left_index] = key;
        parent->num_keys++;
        return root;
    }

    Node* insertIntoNodeAfterSplitting(Node* root, Node* old_node, int left_index, int key, Node* right) {
        int i, j, split, k_prime;
        Node* new_node, * child;
        int* temp_keys;
        Node** temp_pointers;

        temp_pointers = new Node*[ORDER + 1];
        temp_keys = new int[ORDER];

        for (i = 0, j = 0; i < old_node->num_keys + 1; ++i, ++j) {
            if (j == left_index + 1) {
                j++;
            }
            temp_pointers[j] = reinterpret_cast<Node*>(old_node->pointers[i]);
        }

        for (i = 0, j = 0; i < old_node->num_keys; ++i, ++j) {
            if (j == left_index) {
                j++;
            }
            temp_keys[j] = old_node->keys[i];
        }

        temp_pointers[left_index + 1] = right;
        temp_keys[left_index] = key;

        old_node->num_keys = 0;

        split = cut(ORDER);
        new_node = makeNode();

        for (i = 0; i < split - 1; ++i) {
            old_node->pointers[i] = temp_pointers[i];
            old_node->keys[i] = temp_keys[i];
            old_node->num_keys++;
        }
        old_node->pointers[i] = temp_pointers[i];
        k_prime = temp_keys[split - 1];
        for (++i, j = 0; i < ORDER; ++i, ++j) {
            new_node->pointers[j] = temp_pointers[i];
            new_node->keys[j] = temp_keys[i];
            new_node->num_keys++;
        }
        new_node->pointers[j] = temp_pointers[i];

        delete[] temp_pointers;
        delete[] temp_keys;

        new_node->parent = old_node->parent;
        for (i = 0; i <= new_node->num_keys; ++i) {
            child = reinterpret_cast<Node*>(new_node->pointers[i]);
            child->parent = new_node;
        }

        return insertIntoParent(root, old_node, k_prime, new_node);
    }

    Node* insertIntoParent(Node* root, Node* left, int key, Node* right) {
        int left_index;
        Node* parent;

        parent = left->parent;

        if (parent == nullptr) {
            return insertIntoNewRoot(left, key, right);
        }

        left_index = getLeftIndex(parent, left);

        if (parent->num_keys < order - 1) {
            return insertIntoNode(root, parent, left_index, key, right);
        }

        return insertIntoNodeAfterSplitting(root, parent, left_index, key, right);
    }

    Node* insertIntoNewRoot(Node* left, int key, Node* right) {
        Node* root = makeNode();
        root->keys[0] = key;
        root->pointers[0] = left;
        root->pointers[1] = right;
        root->num_keys++;
        root->parent = nullptr;
        left->parent = root;
        right->parent = root;
        return root;
    }

    Node* startNewTree(int key, Record* pointer) {
        Node* root = makeLeaf();
        root->keys[0] = key;
        root->pointers[0] = pointer;
        root->pointers[order - 1] = nullptr;
        root->parent = nullptr;
        root->num_keys++;
        return root;
    }

    Node* insert(Node* root, int key, int value) {
        Record* pointer = nullptr;
        Node* leaf = nullptr;

        pointer = makeRecord(value);

        if (root == nullptr) {
            return startNewTree(key, pointer);
        }

        leaf = findLeaf(root, key);

        if (leaf->num_keys < order - 1) {
            leaf = insertIntoLeaf(leaf, key, pointer);
            return root;
        }

        return insertIntoLeafAfterSplitting(root, leaf, key, pointer);
    }
};

int main() {
    BPlusTree tree;
    Node* root = nullptr;

    root = tree.insert(root, 3, 300);
    root = tree.insert(root, 1, 100);
    root = tree.insert(root, 7, 700);
    root = tree.insert(root, 2, 200);
    root = tree.insert(root, 5, 500);
    root = tree.insert(root, 4, 400);
    root = tree.insert(root, 6, 600);

    tree.printTree(root);

    tree.findAndPrint(root, 3);
    tree.findAndPrint(root, 6);
    tree.findAndPrint(root, 7);

    tree.findAndPrintRange(root, 2, 5);

    return 0;
}