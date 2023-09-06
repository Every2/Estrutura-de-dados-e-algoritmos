#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct BTreeNode Btree;

struct BTreeNode {
    int keys[3];
    Btree* childPointers[4];
    bool isLeaf;
    int numKeys;
};

Btree* createNode(bool leaf) {
    Btree* newNode = (Btree*)malloc(sizeof(Btree));
    newNode->isLeaf = leaf;
    newNode->numKeys = 0;
    for (int i = 0; i < 4; i++) {
        newNode->childPointers[i] = NULL;
    }
    return newNode;
}

void split(Btree* parent, int index) {
    Btree* newChild = createNode(true);
    Btree* oldChild = parent->childPointers[index];
    parent->numKeys++;

    for (int i = parent->numKeys - 1; i > index; i--) {
        parent->childPointers[i + 1] = parent->childPointers[i];
        parent->keys[i] = parent->keys[i - 1];
    }

    parent->childPointers[index + 1] = newChild;
    parent->keys[index] = oldChild->keys[1];

    newChild->numKeys = 1;
    newChild->keys[0] = oldChild->keys[2];

    oldChild->numKeys = 1;
}

Btree* insert(Btree* root, int key) {
    if (root == NULL) {
        root = createNode(true);
        root->keys[0] = key;
        root->numKeys = 1;
    }
    else {
        if (root->numKeys == 3) {
            Btree* newRoot = createNode(false);
            newRoot->childPointers[0] = root;
            split(newRoot, 0);
            root = newRoot;
        }

        int i = root->numKeys - 1;
        while (i >= 0 && key < root->keys[i]) {
            root->keys[i + 1] = root->keys[i];
            i--;
        }

        root->keys[i + 1] = key;
        root->numKeys++;
    }
    return root;
}

void set(Btree* root, int oldKey, int newKey) {
    if (root == NULL) {
        return;
    }

    int i = 0;
    while (i < root->numKeys && oldKey > root->keys[i]) {
        i++;
    }

    if (i < root->numKeys && oldKey == root->keys[i]) {
        root->keys[i] = newKey;
    }
    else if (!root->isLeaf) {
        set(root->childPointers[i], oldKey, newKey);
    }
}

bool search(Btree* root, int key) {
    if (root == NULL) {
        return false;
    }

    int i = 0;
    while (i < root->numKeys && key > root->keys[i]) {
        i++;
    }
    if (i < root->numKeys && key == root->keys[i]) {
        return true;
    }
    else if (root->isLeaf) {
        return false;
    }
    else {
        return search(root->childPointers[i], key);
    }
}

void inOrderTraversal(Btree* root) {
    if (root != NULL) {
        for (int i = 0; i < root->numKeys; i++) {
            inOrderTraversal(root->childPointers[i]);
            printf("%d ", root->keys[i]);
        }
        inOrderTraversal(root->childPointers[root->numKeys]);
    }
}
