#include <iostream>
#include <memory>

template <typename T>
class Node {

public:
    T data;
    std::shared_ptr<Node<T>> next;

    Node(const T& value) : data(value), next(nullptr) {}
};

template <typename T>
class LinkedList {

public:

    LinkedList(): head(nullptr) {}

    void insertAtBeginning(const T& newData) {
        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(newData);
        newNode->next = head;
        head = newNode;
    }

    void insertAfter(const std::shared_ptr<Node<T>>& prev_node, const T& new_data) {
        if (!prev_node) {
            std::cout << "The given previous node cannot be NULL" << '\n';
            return;
        }

        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(new_data);
        newNode->next = prev_node->next;
        prev_node->next = newNode;
    }

    void insertAtEnd(const T& new_data) {
        std::shared_ptr<Node<T>> newNode = std::make_shared<Node<T>>(new_data);

        if (!head) {
            head = newNode;
            return;
        }

        std::shared_ptr<Node<T>> last = head;
        while (last->next) {
            last = last->next;
        }

        last->next = newNode;
    }

    std::shared_ptr<Node<T>> getNodeWithValue(const T& value) const {
        std::shared_ptr<Node<T>> current = head;
        while (current) {
            if (current->data == value) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void deleteNode(const T& key) {
        if (!head) {
            return;
        }

        if (head->data == key) {
            head = head->next;
            return;
        }

        std::shared_ptr<Node<T>> temp = head, prev = nullptr;

        while (temp && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) {
            return;
        }

        prev->next = temp->next;
    }

    bool searchNode(const T& key) const {
        std::shared_ptr<Node<T>> current = head;

        while (current) {
            if (current->data == key) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void sortLinkedList() {
        if (!head) {
            return;
        }

        std::shared_ptr<Node<T>> current = head, index;

        while (current) {
            index = current->next;

            while (index) {
                if (current->data > index->data) {
                    std::swap(current->data, index->data);
                }
                index = index->next;
            }
            current = current->next;
        }
    }

    void printList() const {
        std::shared_ptr<Node<T>> node = head;
        while (node) {
            std::cout << " " << node->data << " ";
            node = node->next;
        }
        std::cout << '\n';
    }

private:
    std::shared_ptr<Node<T>> head;
};



