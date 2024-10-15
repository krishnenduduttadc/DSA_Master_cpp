#include <bits/stdc++.h>
using namespace std;


class Heap {
    public:
    vector<int> v;
    void insert(int value){
        v.push_back(value);
        int cur_index = v.size()-1;
        while(cur_index!=0){
            int parent_index = (cur_index-1)/2;
            if(v[parent_index]<v[cur_index]){
                swap(v[parent_index], v[cur_index]);
            }
            cur_index = parent_index;
        }
    }
    
    void Heapify(int index) {
        int left_child = 2*index+1;
        int right_child = 2*index+2;
        if(left_child<v.size() && v[left_child]>v[index]){
            swap(v[index], v[left_child]);
            Heapify(left_child);
        }
        if(right_child<v.size() && v[right_child]>v[index]){
            swap(v[index], v[right_child]);
            Heapify(right_child);
        }
    }
    
    void delete_from_heap(){
        int index = 0;
        swap(v[index], v[v.size()-1]);
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
    string operation;
    
    while (cin >> operation) { // Read operations continuously
        if (operation == "+") {
            int power;
            cin >> power; // Read the power of the card received
            h1->insert(power); // Insert into the heap
        } else if (operation == "-") {
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

10
+ 7
+ 18
+ 3
+ 15
+ 1
-
-
+ 92
- 
-
*/