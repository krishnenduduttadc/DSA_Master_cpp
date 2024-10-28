#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    vector<int> v;

    // Function to insert a value into the heap
    void insert(int value) {
        v.push_back(value); // Add the value to the end of the vector
        int cur_index = v.size() - 1; // Index of the newly inserted element

        // Perform heapify-up operation
        while (cur_index != 0) { // Continue until reaching the root (index 0)
            int parent_index = (cur_index - 1) / 2; // Calculate the index of the parent node
            if (v[parent_index] > v[cur_index]) { // If the parent node is greater than the current node
                swap(v[parent_index], v[cur_index]); // Swap them
            }
            cur_index = parent_index; // Move up to the parent node
        }
    }
};

int main() {
    Heap* h1 = new Heap();

    // Hardcoded input
    int n = 7; // Number of elements
    int values[] = {2, 3, 4, 6, 1, 3, 1}; // Hardcoded values to be inserted

    // Insert hardcoded values into the heap
    for (int i = 0; i < n; i++) {
        h1->insert(values[i]); // Insert into the heap
    }

    // Output the elements of the heap
    for (auto i : h1->v) {
        cout << i << " "; // Print each element in the heap
    }
    cout << endl;

    delete h1; // Clean up memory
    return 0;
}
