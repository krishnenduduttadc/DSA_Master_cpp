#include <bits/stdc++.h>
using namespace std;

class Heap {
public:
    vector<int> v;

    void insert(int value) {
        v.push_back(value);
        int cur_index = v.size() - 1;

        // Bubble up to maintain the heap property
        while (cur_index != 0) {
            int parent_index = (cur_index - 1) / 2;
            if (v[parent_index] > v[cur_index]) {
                swap(v[parent_index], v[cur_index]);
                cur_index = parent_index; // Update current index
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

    void delete_from_heap() {
        if (v.empty()) {
            cout << "Heap is empty. Cannot delete." << endl;
            return;
        }

        // Move the last element to the root
        swap(v[0], v[v.size() - 1]);
        v.pop_back(); // Remove the last element
        Heapify(0); // Restore the heap property
    }

    int getMin() {
        return v.empty() ? -1 : v[0]; // Return minimum element (root of the heap)
    }
};

int main() {
    Heap* h1 = new Heap();

    // Hardcoded input
    int n = 10;
    int values[] = {1, 78, 29, 48, 19, 2, 17, 134, 93, 13};

    // Inserting hardcoded values into the heap
    for (int i = 0; i < n; i++) {
        h1->insert(values[i]); // Insert into the heap
    }

    vector<int> sorted_arr;
    for (int i = 0; i < n; i++) {
        sorted_arr.push_back(h1->getMin()); // Get the root of the heap
        h1->delete_from_heap(); // Delete the root from the heap
    }

    for (auto i : sorted_arr) {
        cout << i << " "; // Output the sorted elements
    }
    cout << endl;

    delete h1; // Clean up
    return 0;
}
