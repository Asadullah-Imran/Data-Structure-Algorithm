#include <iostream>

#define MAX_SIZE 100

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX_SIZE - 1);
    }

    void push(int value) {
        if (isFull()) {
            std::cout << "Stack Overflow! Cannot push element " << value << std::endl;
            return;
        }
        arr[++top] = value;
        std::cout << "Pushed element " << value << " to the stack." << std::endl;
    }

    void pop() {
        if (isEmpty()) {
            std::cout << "Stack Underflow! Cannot pop element." << std::endl;
            return;
        }
        int poppedElement = arr[top--];
        std::cout << "Popped element: " << poppedElement << std::endl;
    }

    int peek() {
        if (isEmpty()) {
            std::cout << "Stack is empty!" << std::endl;
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack stack;

    stack.push(10);  
    stack.push(20);
    stack.push(30);

    std::cout << "Top element: " << stack.peek() << std::endl;

    stack.pop();
    stack.pop();

    std::cout << "Top element: " << stack.peek() << std::endl;

    return 0;
}