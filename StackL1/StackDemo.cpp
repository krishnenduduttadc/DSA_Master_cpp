#include <iostream>
using namespace std;

#define MAX 1000 // Maximum size of Stack

class StackDemo {
private:
    int top;
    char a[MAX]; // Array to store elements of the stack

public:
    // Constructor to initialize the stack
    StackDemo() {
        top = -1; // Initialize top to -1 (empty stack)
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }

    // Function to push an element into the stack
    bool push(char x) {
        if (top >= MAX - 1) {
            cout << "Stack Overflow" << endl;
            return false;
        } else {
            a[++top] = x;
            cout << "Stack pushed" << endl;
            return true;
        }
    }

    // Function to pop an element from the stack
    char pop() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return 0;
        } else {
            char abc = a[top--];
            return abc;
        }
    }

    // Function to return the top element of the stack without removing it
    char peek() {
        if (top < 0) {
            cout << "Stack Underflow" << endl;
            return 0;
        } else {
            return a[top];
        }
    }

    // Function to return the top element of the stack
    char topElement() {
        return a[top];
    }

    // Function to check if the stack is empty
    bool empty() {
        return (top < 0);
    }
};

int main() {
    StackDemo s;

    // Pushing elements into the stack
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.push('e');

    // Popping and displaying elements from the stack
    cout << s.pop() << " Popped from stack" << endl;

    // Peeking the top element of the stack
    cout << s.peek() << " Peeked from stack" << endl;

    // Displaying the top element of the stack
    cout << s.topElement() << " is top of stack" << endl;

    return 0;
}
