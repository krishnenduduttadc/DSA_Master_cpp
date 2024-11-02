#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 101
char a[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(char ele) {
    if (top < MAX_SIZE - 1) {
        a[++top] = ele;
    } else {
        cout << "Stack is full. Cannot push: " << ele << "\n";
    }
}

// Function to pop an element from the stack
char pop() {
    if (top >= 0) {
        char ele = a[top];
        top--;
        return ele;
    } else {
        cout << "Stack is empty. Cannot pop.\n";
        return '-1';
    }
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to check if the stack is full
bool isFull() {
    return top >= MAX_SIZE;
}

// Function to check if a pair of parentheses matches
bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')');
}

// Function to check if the parentheses in an expression are balanced
bool isBalanced(string expression) {
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (c == '(') {
            push(c);
        } else if (c == ')') {
            if (isEmpty()) {
                return false; // More closing than opening
            }
            char topChar = pop();
            if (!isMatchingPair(topChar, c)) {
                return false; // Mismatched parentheses
            }
        }
    }
    return isEmpty(); // Stack should be empty if expression is balanced
}

int main() {
    // Hardcoded test cases
    string testCases[] = {
        "((()))",
        "()()()",
        "(((()"
    };

    int t = sizeof(testCases) / sizeof(testCases[0]); // Number of test cases

    for (int i = 0; i < t; i++) {
        string str = testCases[i];
        cout << str << " : ";
        bool ans = isBalanced(str);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }

    return 0;
}

/*
Expected Output:
((())) : true
()()() : true
(((() : false
*/
