#include <iostream>
#include <memory>

template <typename T>
class Node {
public:
    T data;
    std::shared_ptr<Node<T>> next;
    std::shared_ptr<Node<T>> prev;

    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class DoubleLinkedList {
public:
    std::shared_ptr<Node<T>> head;

    void insertFront(T data) {
        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(data);

        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;
    }

    void insertAfter(std::shared_ptr<Node<T>> prev_node, T data) {
        if (prev_node == nullptr) {
            std::cout << "Previous node cannot be null" << '\n';
            return;
        }

        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(data);
        newNode->next = prev_node->next;
        newNode->prev = prev_node;

        if (prev_node->next != nullptr) {
            prev_node->next->prev = newNode;
        }

        prev_node->next = newNode;
    }

    void insertEnd(T data) {
        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(data);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        std::shared_ptr<Node<T>> temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->prev = temp;
    }

    void deleteNode(std::shared_ptr<Node<T>> del_node) {
        if (head == nullptr || del_node == nullptr) {
            return;
        }

        if (head == del_node) {
            head = del_node->next;
        }

        if (del_node->next != nullptr) {
            del_node->next->prev = del_node->prev;
        }

        if (del_node->prev != nullptr) {
            del_node->prev->next = del_node->next;
        }
    }

    void printList() {
        std::shared_ptr<Node<T>> current = head;

        while(current != nullptr) {
            std::cout << current->data << " -> ";
            current = current->next;
        }

        std::cout << "NULL" << '\n';
    }
};
