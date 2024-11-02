#include <bits/stdc++.h>
using namespace std;

#define maxSize 101
int a[maxSize];
int front = 0; // Index of the front element
int rear = -1;  // Index of the rear element
int currentSize = 0; // Initialize current size

bool isEmpty() {
    return currentSize == 0;
}

bool isFull() {
    return currentSize == maxSize;
}

int size() {
    return currentSize;
}

void enqueue(int item) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue.\n";
        return;
    }
    rear = (rear + 1) % maxSize; // Circular increment
    a[rear] = item;
    currentSize++;
}

int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return -1; // Return a sentinel value or throw an exception
    }
    int removedItem = a[front];
    front = (front + 1) % maxSize; // Circular increment
    currentSize--;
    return removedItem;
}

int main() {
    int n = 10; // Hardcoded value for n
    // Enqueue even numbers and print odd numbers
    for (int i = 1; i <= n; i++) {
        if (i % 2) {
            cout << i << " "; // Print odd numbers
        } 
        else {
            enqueue(i); // Enqueue even numbers
        }
    }

    // Dequeue all elements and print them
    while (!isEmpty()) {
        cout << dequeue() << " "; // Print dequeued elements
    }
    return 0;
}
