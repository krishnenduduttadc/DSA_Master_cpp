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
            }
            cur_index = parent_index;
        }
    }
    
    void Heapify(int index) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        if (left_child < v.size() && v[left_child] > v[index]) {
            swap(v[index], v[left_child]);
            Heapify(left_child);
        }
        if (right_child < v.size() && v[right_child] > v[index]) {
            swap(v[index], v[right_child]);
            Heapify(right_child);
        }
    }
    
    void delete_from_heap() {
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
    // Hardcoded input
    int n = 10; // Number of elements
    int k = 4;  // We want to find the 4-th largest element
    vector<int> values = {1, 78, 29, 48, 19, 2, 17, 134, 93, 13}; // Hardcoded values

    Heap* h1 = new Heap();
    
    for (int i = 0; i < n; i++) {
        h1->insert(values[i]); // Insert each element into the heap
    }

    // Remove the largest elements k-1 times
    for (int i = 1; i < k; i++) {
        h1->delete_from_heap();
    }

    // The root of the heap is now the k-th largest element
    cout << h1->getMax() << endl;

    delete h1; // Clean up
    return 0;
}

/*
Expected Output:
78
*/
