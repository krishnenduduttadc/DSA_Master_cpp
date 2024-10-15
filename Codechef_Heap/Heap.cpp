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
    cin>>n;
    for(int i=0; i<n; i++)
    {
        string command;
        cin>>command;
        if(command=="insert"){
            int value;
            cin>>value;
            h1->insert(value);
        }
        else if(command=="delete")
        {
            h1->delete_from_heap();
        }
        else if(command=="print"){
            for(auto j: h1->v)
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

}

/*
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
