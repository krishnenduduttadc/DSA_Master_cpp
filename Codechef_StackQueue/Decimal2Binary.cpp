#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 101
int a[MAX_SIZE];
int top = -1;

// Function to push an element onto the stack
void push(int ele) {
    if (top < MAX_SIZE - 1) { // Check if the stack is not full
        a[++top] = ele;
    } else {
        cout << "Stack is full. Cannot push: " << ele << "\n";
    }
}

// Function to pop an element from the stack
int pop() {
    if (top >= 0) { // Check if the stack is not empty
        int ele = a[top];
        top--;
        return ele;
    } else {
        cout << "Stack is empty. Cannot pop.\n";
        return -1; // Return -1 to indicate failure
    }
}

// Function to check if the stack is empty
bool isEmpty() {
    return top == -1;
}

// Function to return the current size of the stack
int size() {
    return top + 1;
}

// Function to convert decimal to binary using stack
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        cout << "0\n"; // Special case for decimal = 0
        return;
    }

    while (decimal > 0) {
        int remainder = decimal % 2;
        push(remainder); // Push the remainder onto the stack
        decimal /= 2; // Divide the decimal number by 2
    }

    // Pop all elements from the stack to get the binary representation
    while (!isEmpty()) {
        cout << pop(); // Print the binary digits
    }
    cout << "\n"; // New line after each binary representation
}

int main() {
    int t;
    cin >> t; // Read number of test cases

    while (t--) {
        int decimal;
        cin >> decimal; // Read the decimal number
        decimalToBinary(decimal); // Convert to binary and print
    }
    return 0;
}

/*
Input:
3
10
15
18

Output:
1010
1111
10010
*/
