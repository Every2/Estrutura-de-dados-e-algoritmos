#include <iostream>
#include <memory>

template <typename T>
class Node {

public:
    T data;
    std::shared_ptr<Node<T>> next;

    Node(T value) : data(value), next(nullptr) {}
};

template <typename T>
class CircularLinkedList {

public:
    CircularLinkedList () : head(nullptr), tail(nullptr) {}

    bool isEmpty() const {
        return head == nullptr;
    }

    void addToEmpty(T value) {
        auto newNode = std::make_shared<Node<T>>(value);
        head = newNode;
        tail = newNode;
        tail->next = head; 
    }

    void append(T value) {
        auto NewNode = std::make_shared<Node<T>>(value);

        if (isEmpty()) {
            head = NewNode;
            tail = NewNode;
            tail->next = head;
        }
        else {
            NewNode->next = head;
            tail->next = NewNode;
            tail = NewNode;
        }
    }

    void addFront(T value) {
        if (isEmpty()) {
            addToEmpty(value);
            return;
        }

        auto newNode = std::make_shared<Node<T>>(value);
        newNode->next = head;
        head = newNode;
        tail->next = newNode;
    }

    void addEnd(T value) {
        if (isEmpty()) {
            addToEmpty(value);
            return;
        }

        auto newNode = std::make_shared<Node<T>>(value);
        newNode->next = head;
        tail->next = newNode;
        tail = newNode;
    }

    void addAfter(T value, T item) {
        if (isEmpty())  {
            std::cout << "The list is empty."  << '\n';
            return;
        }

        auto newNode = std::make_shared<Node<T>>(value);
        auto current = head;

        do {
            if (current->data == item) {
                newNode->next = current->next;
                current->next = newNode;

                if (current == tail) {
                    tail = newNode;
                }

                return;
            }
            current = current->next;
        } while (current != head);
        std::cout << "\nThe given node is not present in the list " << '\n';
    }

    void deleteNode(T key) {
        if (isEmpty()) {
            std::cout << "List is empty" << '\n';
            return;
        }

        if (head->data == key && head->next == head) {
            head = nullptr;
            tail = nullptr;
            return;
        }

        if (head->data == key) {
            tail->next = head->next;
            head = head->next;
            return;
        }

        auto current = head;

        while (current->next != head && current->next->data != key) {
            current = current->next;
        }

        if (current->next->data == key) {
            auto temp = current->next;
            current->next = temp->next;

            if (temp == tail) {
                tail = current;
            }
        } else {
            std::cout << "This element isn't in the list" << '\n';
        }
    }

    void traverse() const {
        if (isEmpty()) {
            std::cout << "The list is empty."  << '\n';
            return;
        }

        auto current = head;

        do {
            std::cout << current->data << " -> ";
            current = current->next;
        } while (current != head);
    }

private:
    std::shared_ptr<Node<T>> head;
    std::shared_ptr<Node<T>> tail;
};
