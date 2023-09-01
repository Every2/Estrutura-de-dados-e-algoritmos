#include <iostream>
#include <array>


template <typename T, int S>
class Deque {

public:
    Deque() : front(0), rear(0), size(0) {
        array.fill(0);
    }

    bool isEmpty() const {
        return size == 0;
    }

    bool isFull() const {
        return size ==  S;
    }

    void insertFront(const T& value) {
        if (isFull()) {
            std::cout << "Deque is full"  << '\n';
            return;
        }

        front = (front - 1 + S) %  S;
        array.at(front) = value;
        size++;
    }

    void insertRear(const T& value) {
        if (isFull()) {
            std::cout << "Deque is full" << '\n';
            return;
        }

        array.at(rear) = value;
        rear = (rear + 1) % S;
        size++;
    }

    T deleteFront() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << '\n';
            return T();
        }

        T value = array.at(front);
        front = (front + 1) % S;
        size--;
        return value;
    }

    T deleteRear() {
        if (isEmpty()) {
            std::cout << "Deque is empty" << '\n';
            return T();
        }

        rear = (rear - 1 + S) % S;
        size--;
        return array.at(rear);
    }

    T getFront() const {
        if (isEmpty()) {
            std::cout << "Deque is empty" << '\n';
            return T();
        }
        return array.at(front);
    }

    T getRear() const {
        if (isEmpty()) {
            std::cout << "Deque is empty" << '\n';
            return T();
        }
        return array.at((rear - 1  + S) % S);
    }

    size_t getSize() const {
        return size;
    }

private:
    std::array<T, S> array;
    T front;
    T rear;
    size_t size;
};
