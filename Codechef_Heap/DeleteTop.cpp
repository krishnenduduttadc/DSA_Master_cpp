#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    vector<int> v;

    void insert(int value) {
        v.push_back(value);
        int cur_index = v.size() - 1;
        while (cur_index != 0) {
            int parent_index = (cur_index - 1) / 2;
            if (v[parent_index] > v[cur_index]) {
                swap(v[parent_index], v[cur_index]);
                cur_index = parent_index; // Continue bubbling up
            } else {
                break; // If parent is smaller, stop bubbling up
            }
        }
    }

    void Heapify(int index) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int smallest = index;

        // Compare with left child
        if (left_child < v.size() && v[left_child] < v[smallest]) {
            smallest = left_child;
        }
        // Compare with right child
        if (right_child < v.size() && v[right_child] < v[smallest]) {
            smallest = right_child;
        }
        // If smallest is not the root, swap and continue heapifying
        if (smallest != index) {
            swap(v[index], v[smallest]);
            Heapify(smallest);
        }
    }

    void delete_from_heap(int index) {
        if (index < 0 || index >= v.size()) {
            cout << "Invalid index." << endl;
            return;
        }
        cout << "Deleting the element " << v[index] << endl;
        swap(v[index], v[v.size() - 1]);
        v.pop_back();
        Heapify(index);
    }

    void printHeap() {
        for (auto i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap* h1 = new Heap();

    // Hardcoded inputs
    int n = 7;  // Number of elements
    vector<int> values = {1, 2, 1, 6, 3, 4, 3}; // Elements to be inserted

    // Insert values into the heap
    for (int value : values) {
        h1->insert(value);
    }

    // Print the heap after insertions
    cout << "Heap after insertions: ";
    h1->printHeap();

    // Hardcoded deletions
    int x = 2; // Number of deletions
    vector<int> indices = {0, 1}; // Indices of elements to delete

    // Perform deletions
    for (int i = 0; i < x; i++) {
        int index = indices[i];
        h1->delete_from_heap(index);
        h1->printHeap(); // Print heap after each deletion
    }

    delete h1; // Clean up
    return 0;
}

/*
Hardcoded Input:
7  // Number of elements
1 2 1 6 3 4 3  // Elements to insert
2  // Number of deletions
0 1  // Indices to delete
*/

