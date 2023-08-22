#include <iostream>
#include <array>
#include <stdexcept>


template<typename T, int N> class Queue {
public:
    Queue() : front(0), rear(-1), count(0) {}

    bool isFull() {
        return count == N;
    }

    bool isEmpty() {
        return count == 0;
    }

    void enQueue(T element) {
        if (isFull()) {
            throw std::overflow_error("Queue is full");
        } 
        else {
            rear = (rear + 1) % N;
            queue[rear] = element;
            count++;
            std::cout << "Inserted: " << element << '\n';
        }
    }
    
    T deQueue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        else {
            T element = queue[front];
            front = (front + 1) % N;
            count--;
            std::cout << "Deleted: " << element << '\n';
            return element;
        }
    }

    void printQueue() {
        if (isEmpty()) {
            throw std::underflow_error("Queue is empty");
        }
        else {
            int i = front;
            std::cout << "Front -> " << queue[i] << '\n';
            std::cout << "Items -> ";
            for (int j = 0; j < count; ++j) {
                std::cout << queue[i] << " ";
                i = (i + 1) % N;
            } 
            std::cout << '\n';
            std::cout << "Rear -> " << queue[rear] << '\n';
        }
    }
private:
    std::array<T, N> queue;
    int front;
    int rear;
    int count;
};

int main() {
    Queue<int, 10> myQueue; 

    myQueue.enQueue(1);
    myQueue.enQueue(2);
    myQueue.enQueue(3);
    myQueue.enQueue(4);
    myQueue.enQueue(5);

    myQueue.printQueue();

    return 0;
}

