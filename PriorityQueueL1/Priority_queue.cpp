#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Priority_Queue {
private:
    vector<int> heap;

public:
    Priority_Queue() {}

    bool isEmpty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

    int getMin() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return heap[0];
    }

    void insert(int element) {
        heap.push_back(element);
        int childIndex = heap.size() - 1;
        int parentIndex = (childIndex - 1) / 2;
        while (childIndex > 0) {
            if (heap[childIndex] < heap[parentIndex]) {
                swap(heap[childIndex], heap[parentIndex]);
                childIndex = parentIndex;
                parentIndex = (childIndex - 1) / 2;
            } else {
                return;
            }
        }
    }

    int removeMin() {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        int temp = heap[0];
        heap[0] = heap[heap.size() - 1];
        heap.pop_back();
        int index = 0;
        int minIndex = index;
        int leftChildIndex = 1;
        int rightChildIndex = 2;

        while (leftChildIndex < heap.size()) {
            if (heap[leftChildIndex] < heap[minIndex]) {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < heap.size() && heap[rightChildIndex] < heap[minIndex]) {
                minIndex = rightChildIndex;
            }
            if (minIndex == index) {
                break;
            } else {
                swap(heap[index], heap[minIndex]);
                index = minIndex;
                leftChildIndex = 2 * index + 1;
                rightChildIndex = 2 * index + 2;
            }
        }
        return temp;
    }
};

int main() {
    Priority_Queue pq;

    // Insert elements into the priority queue
    pq.insert(4);
    pq.insert(2);
    pq.insert(7);
    pq.insert(1);
    pq.insert(5);

    // Remove and print the minimum element until the queue is empty
    while (!pq.isEmpty()) {
        cout << pq.removeMin() << " ";
    }
    cout << endl;

    return 0;
}
