#include <iostream>
#include <vector>
#include <array>
#include <stdexcept>

template <typename T, int N = 0> class Stack {
public:
    Stack() : useVector(true){};
    Stack(std::array<T, N> stackArray) : useVector(false), plainStack(stackArray), topIndex(-1) {};
    
    void push(const T& element) {
        if (useVector) {
            dynamicStack.push_back(element);
        } 
        else {
            if (N == 0 || topIndex + 1 < N) {
                topIndex++;
                plainStack[topIndex] = element;
            }
            else {
                throw std::overflow_error("Stack is full");
            }
        }
    };

    bool isEmpty() const {
        return (useVector ? dynamicStack.empty() : topIndex == -1);
    };

    T showTop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }

        return (useVector ? dynamicStack.back(): plainStack[topIndex]);
    };

    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty");
        }

        if (useVector) {
            T top = dynamicStack.back();
            dynamicStack.pop_back();
            return top;
        }
        else {
            T top = plainStack[topIndex];
            topIndex--;
            return top;
        }
    }
    
private:
    bool useVector{};
    int topIndex;
    std::vector <T> dynamicStack;
    std::array <T, N> plainStack;
};


int main() {
    
    Stack<char> stackVector;

    Stack<int, 10> stackArray;

    stackVector.push('a');
    stackVector.push('b');
    stackVector.push('c');

    while (!stackVector.isEmpty()) {
        std::cout << stackVector.pop() << " ";
    }
    std::cout << '\n';

    stackArray.push(1);
    stackArray.push(2);
    stackArray.push(3);

    while (!stackArray.isEmpty()) {
        std::cout << stackArray.pop() << " ";
    }
    std::cout << '\n';

    return 0;
}

