#include <bits/stdc++.h>
using namespace std;

#define maxSize 101
int a[maxSize];  // Array to represent the queue
int front = 0;   // Index of the front element
int rear = -1;   // Index of the rear element
int currentSize = 0;  // Size of the queue

bool isEmpty() {
    return currentSize == 0;  // Check if the queue is empty
}

bool isFull() {
    return currentSize == maxSize;  // Check if the queue is full
}

int size() {
    return currentSize;  // Return the current size of the queue
}

// Function to enqueue an item into the queue
void enqueue(int item) {
    if (isFull()) {
        cout << "Queue is full. Cannot enqueue: " << item << "\n";
        return;
    }
    rear = (rear + 1) % maxSize;  // Circular increment
    a[rear] = item;
    currentSize++;
}

// Function to dequeue an item from the queue
int dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty. Cannot dequeue.\n";
        return -1;  // Return a sentinel value if the queue is empty
    }
    int removedItem = a[front];
    front = (front + 1) % maxSize;  // Circular increment
    currentSize--;
    return removedItem;
}

// Array to store unique tasks
int taskList[maxSize];
int taskListSize = 0;

// Function to add a task to the list
void addTask(int task) {
    if (taskListSize < maxSize) {
        // Check if the task is not already present in the list
        bool taskExists = false;
        for (int i = 0; i < taskListSize; i++) {
            if (task == taskList[i]) {
                taskExists = true;
                break;
            }
        }
        if (!taskExists) {
            enqueue(task);  // Add task to the queue
            taskList[taskListSize] = task;  // Store in taskList
            taskListSize++;
        } else {
            cout << "Task " << task << " already exists in the to-do list.\n";
        }
    } else {
        cout << "Task list is full. Cannot add task: " << task << "\n";
    }
}

// Function to display the current to-do list
void displayToDoList() {
    cout << "Current To-Do List:\n";
    for (int i = 0; i < taskListSize; i++) {
        cout << taskList[i] << "\n";  // Display each task
    }
}

int main() {
    // Hardcoded list of tasks
    int tasks[] = {1, 2, 4, 5, 1, 2, 3, 9, 4, 9};
    int n = sizeof(tasks) / sizeof(tasks[0]);  // Number of tasks

    // Adding hardcoded tasks to the task list
    for (int i = 0; i < n; i++) {
        addTask(tasks[i]);  // Attempt to add each task
    }

    // Display the current to-do list
    displayToDoList();
    return 0;
}

/*
Expected Output:
Current To-Do List:
1
2
3
4
5
9
*/
