#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

// Use a global vector to represent the min-heap
vector<int> heap;

// Check if the heap is empty
bool isEmpty() {
    return heap.empty();
}

// Get the size of the heap
int size() {
    return heap.size();
}

// Return the minimum element (root of the heap)
int getMin() {
    if (isEmpty()) {
        throw runtime_error("Queue is empty");
    }
    return heap[0];
}

// Insert an element into the heap
void insert(int element) {
    heap.push_back(element);
    int childIndex = heap.size() - 1;
    int parentIndex = (childIndex - 1) / 2;

    while (childIndex > 0 && heap[childIndex] < heap[parentIndex]) {
        swap(heap[childIndex], heap[parentIndex]);
        childIndex = parentIndex;
        parentIndex = (childIndex - 1) / 2;
    }
}

// Remove and return the minimum element
int removeMin() {
    if (isEmpty()) {
        throw runtime_error("Queue is empty");
    }

    int temp = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();

    int index = 0;
    int minIndex = index;
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;

    while (leftChildIndex < heap.size()) {
        minIndex = index;

        if (heap[leftChildIndex] < heap[minIndex]) {
            minIndex = leftChildIndex;
        }

        if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[minIndex]) {
            minIndex = rightChildIndex;
        }

        if (minIndex == index) {
            break;
        }

        swap(heap[index], heap[minIndex]);
        index = minIndex;
        leftChildIndex = 2 * index + 1;
        rightChildIndex = 2 * index + 2;
    }

    return temp;
}

int main() {
    // Insert elements into the priority queue
    insert(4);
    insert(2);
    insert(7);
    insert(1);
    insert(5);

    // Remove and print the minimum element until the queue is empty
    while (!isEmpty()) {
        cout << removeMin() << " ";
    }
    cout << endl;

    return 0;
}
