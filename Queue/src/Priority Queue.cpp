#include <iostream>
#include <vector>

template <typename T>
class PriorityQueue {

public:
    void push(T item) {
        heap.push_back(item);
        heapifyUp(heap.size() - 1);
    }

    T pop() {
        if (heap.empty()) {
            std::cerr << "Queue is empty" << '\n';
            return -1;
        }

        T root {heap.at(0)};
        heap.at(0) = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    T peek() {
        if (heap.empty()) {
            std::cerr << "Queue is empty" << '\n';
            return -1;
        }

        return heap.at(0);
    }

    bool isEmpty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

private:
    std::vector<T> heap;

    void heapifyUp(int index) {
        int parent {(index - 1) / 2};
        while (index > 0 && heap.at(index) < heap.at(parent)) {
            std::swap(heap.at(index), heap.at(parent));
            index = parent;
            parent = (index - 1) / 2;
        }
    }

    void heapifyDown(int index) {
        int leftChild {2 * index + 1};
        int rightChild {2 * index + 2};
        int smallest {index};

        if (leftChild < heap.size() && heap.at(leftChild) < heap.at(smallest)) {
            smallest = leftChild;
        }

        if (rightChild < heap.size() && heap.at(rightChild) < heap.at(smallest)) {
            smallest = rightChild;
        }

        if (smallest != index) {
            std::swap(heap.at(index), heap.at(smallest));
            heapifyDown(smallest);
        }
    }
};
