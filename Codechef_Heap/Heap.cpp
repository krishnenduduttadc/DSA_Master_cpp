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
                cur_index = parent_index; // Update the current index
            } else {
                break; // If parent is smaller, stop bubbling up
            }
        }
    }

    void Heapify(int index) {
        int left_child = 2 * index + 1;
        int right_child = 2 * index + 2;
        int smallest = index; // Start with the current index as the smallest

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
        cout << "Deleting the element " << v[0] << endl; // Print the element being deleted
        swap(v[0], v[v.size() - 1]); // Move the last element to the root
        v.pop_back(); // Remove the last element
        Heapify(0); // Restore the heap property
    }
};

int main() {
    Heap* h1 = new Heap();

    // Hardcoded input for testing
    int n = 10; // Number of commands
    string commands[10] = {
        "insert 8",
        "insert 3",
        "insert 4",
        "insert 1",
        "insert 18",
        "print",
        "delete",
        "print",
        "delete",
        "print"
    };

    // Process the commands
    for (int i = 0; i < n; i++) {
        string command = commands[i];
        if (command.substr(0, 6) == "insert") {
            int value = stoi(command.substr(7)); // Extract the value after 'insert '
            h1->insert(value);
        }
        else if (command == "delete") {
            h1->delete_from_heap();
        }
        else if (command == "print") {
            cout << "Current Heap: ";
            for (auto j : h1->v) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    delete h1; // Clean up
    return 0;
}

/*
Hardcoded Input:
10
insert 8
insert 3
insert 4
insert 1
insert 18
print
delete
print
delete
print
*/
