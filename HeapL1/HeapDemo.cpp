#include <iostream>
#include <vector>
using namespace std;

int left(int i) { return 2 * i + 1; }
int right(int i) { return 2 * i + 2; }
int parent(int i) { return (i - 1) / 2; }

void insertMinHeap(vector<int>& heap, int& size, int capacity, int value) {
    if (size == capacity) return;

    heap[size] = value;
    int i = size;
    size++;

    while (i != 0 && heap[parent(i)] > heap[i]) {
        swap(heap[i], heap[parent(i)]);
        i = parent(i);
    }
}

void showHeap(const vector<int>& heap, int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

int main() {
    int capacity = 9;
    vector<int> heap(capacity);
    int size = 0;

    insertMinHeap(heap, size, capacity, 10);
    insertMinHeap(heap, size, capacity, 20);
    insertMinHeap(heap, size, capacity, 15);
    insertMinHeap(heap, size, capacity, 40);
    insertMinHeap(heap, size, capacity, 50);
    insertMinHeap(heap, size, capacity, 100);
    insertMinHeap(heap, size, capacity, 25);
    insertMinHeap(heap, size, capacity, 45);

    showHeap(heap, size);

    return 0;
}
