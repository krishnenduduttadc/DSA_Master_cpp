#include <iostream>
using namespace std;

#define MAX 1000

int top = -1;
char stackArr[MAX];

bool isEmpty() {
    return top < 0;
}

bool isFull() {
    return top >= MAX - 1;
}

bool push(char x) {
    if (isFull()) {
        cout << "Stack Overflow" << endl;
        return false;
    }
    stackArr[++top] = x;
    cout << x << " pushed to stack" << endl;
    return true;
}

char pop() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return 0;
    }
    return stackArr[top--];
}

char peek() {
    if (isEmpty()) {
        cout << "Stack Underflow" << endl;
        return 0;
    }
    return stackArr[top];
}

char topElement() {
    return peek();
}

int main() {
    push('a');
    push('b');
    push('c');
    push('d');
    push('e');

    cout << pop() << " popped from stack" << endl;
    cout << peek() << " is on top after peek" << endl;
    cout << topElement() << " is top of stack using topElement()" << endl;

    return 0;
}
