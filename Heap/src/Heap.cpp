#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

class MaxHeap {

public:
    MaxHeap(int capacity) : capacity(capacity), size(0) {
        array = std::make_unique<std::vector<int>>(capacity);
    }

    void insert(int key) {
        if (size >= capacity) {
            std:: cout << "Heap is full" << '\n';
            return;
        }

        (*array).at(size) = key;
        size++;

        heapifyUp(size - 1);
    }

    int deleteRoot() {
        if (size <= 0) {
            std::cout << "Heap is empty" << '\n';
            return -1;
        }

        int root = (*array).at(0);
        (*array).at(0) = std::move((*array).at(size - 1));
        size--;

        heapifyDown(0);

        return root;
    }

    void printHeap() {
        std::cout << "Heap: ";
        for (int i {0}; i < size; i++) {
            std::cout << (*array).at(i) << " ";
        }

        std::cout << '\n';
    }

private:
    std::unique_ptr<std::vector<int>> array;
    int capacity;
    int size;

    void heapifyUp(int index) {
        while(index > 0 && (*array).at(index) > (*array).at((index - 1) / 2)) {
            std::swap((*array).at(index), (*array).at((index - 1) / 2));
            index = (index - 1 / 2);
        }
    }

    void heapifyDown(int index) {
        int largest = index;
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;

        if (leftChild < size && (*array).at(leftChild) > (*array).at(largest)) {
            largest = leftChild;
        }

        if (rightChild < size && (*array).at(rightChild) > (*array).at(largest)) {
            largest = rightChild;
        }

        if (largest != index) {
            std::swap((*array).at(index), (*array).at(largest));
            heapifyDown(largest);
        }
    }
};

