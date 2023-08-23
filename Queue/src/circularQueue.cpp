#include <iostream>
#include <array>
#include <stdexcept>

template <typename T, int N>
class CircularQueue {

public:
    CircularQueue() : front(0), rear(-1), size(0){}
    bool isFull() const {
        return size == N;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void enqueue(T value) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % N;
        }
        elements[rear] = value;
        size++;
    }

    T dequeue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }

        T removedValue{elements[front]};
        if (front == rear) {
            front = rear = -1;
        } 
        else {
            front = (front + 1) % N;
        }
        size--;
        return removedValue;
    }

    void printQueue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        else {
            int i = front;
            std::cout << "Front -> " << elements[i] << '\n';
            std::cout << "Items -> ";
            for (int j = 0; j < size; ++j) {
                std::cout << elements[i] << " ";
                i = (i + 1) % N;
            } 
            std::cout << '\n';
            std::cout << "Rear -> " << elements[rear] << '\n';
        }
    }

private:
    std::array<T, N> elements;
    int front;
    int rear;
    int size;
};


