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
            if(v[parent_index]>v[cur_index]){
                swap(v[parent_index], v[cur_index]);
            }
            cur_index = parent_index;
        }
    }
    
    void Heapify(int index) {
        int left_child = 2*index+1;
        int right_child = 2*index+2;
        if(left_child<v.size() && v[left_child]<v[index]){
            swap(v[index], v[left_child]);
            Heapify(left_child);
        }
        if(right_child<v.size() && v[right_child]<v[index]){
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
    
};


int main() {
Heap* h1 = new Heap();
    int n;
    cin >> n; // Read the number of elements
    for(int i = 0; i < n; i++) {
        int value;
        cin >> value; // Read each element
        h1->insert(value); // Insert into the heap
    }
    
    vector<int> sorted_arr;
    for(int i = 0; i < n; i++) {
        sorted_arr.push_back(h1->v[0]); // Add the root of the heap to the sorted array
        h1->delete_from_heap(); // Delete the root from the heap
    }
    
    for(auto i: sorted_arr) {
        cout << i << " "; // Output the sorted elements
    }
    cout << endl;

    delete h1; 

}


/*
10
1 78 29 48 19 2 17 134 93 13
*/