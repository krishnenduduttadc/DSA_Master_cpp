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
            if (v[parent_index] < v[cur_index]) {
                swap(v[parent_index], v[cur_index]);
                cur_index = parent_index; // Continue bubbling up
            } else {
                break; // If parent is greater, stop bubbling up
            }
        }
    }
    
    void Heapify(int index) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int largest = index;

        // Compare with left child
        if (left_child < v.size() && v[left_child] > v[largest]) {
            largest = left_child;
        }
        // Compare with right child
        if (right_child < v.size() && v[right_child] > v[largest]) {
            largest = right_child;
        }
        // If largest is not the root, swap and continue heapifying
        if (largest != index) {
            swap(v[index], v[largest]);
            Heapify(largest);
        }
    }
    
    void delete_from_heap() {
        if (v.empty()) return; // Nothing to delete
        int index = 0;
        swap(v[index], v[v.size() - 1]);
        v.pop_back();
        Heapify(index);
    }
    
    int getMax() {
        if (!v.empty()) {
            return v[0]; // Return the max element (root of the heap)
        }
        return -1; // Or some error value if the heap is empty
    }

    int size() {
        return v.size();
    }
};

int main() {
    Heap* h1 = new Heap(); // Create an instance of Heap

    // Hardcoded input
    vector<int> inputs = {7, 18, 3, 15, 1, -1, 92}; // Using -1 to indicate a delete operation

    for (int input : inputs) {
        if (input != -1) { // If it's a power, insert it
            h1->insert(input); // Insert into the heap
        } else { // If it's -1, perform a delete operation
            if (h1->size() > 0) { // Check if heap is not empty
                cout << h1->getMax() << endl; // Print the strongest card
                h1->delete_from_heap(); // Remove the strongest card
            } else {
                cout << "No cards to put down" << endl; // Handle empty heap case
            }
        }
    }

    delete h1; // Clean up
    return 0;
}

/*
Hardcoded Input (in the code):
7
18
3
15
1
-1  // delete operation
-1  // delete operation
92
-1  // delete operation
-1  // delete operation

Expected Output:
18
15
92
7
*/
