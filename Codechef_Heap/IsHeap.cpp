#include <bits/stdc++.h>
using namespace std;

bool isMinHeap(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        int left = 2 * i + 1;  // index of left child
        int right = 2 * i + 2; // index of right child
        
        // Check if left child exists and compare with the parent
        if (left < n && arr[i] > arr[left]) {
            return false; // Min-heap property violated
        }
        
        // Check if right child exists and compare with the parent
        if (right < n && arr[i] > arr[right]) {
            return false; // Min-heap property violated
        }
    }
    return true; // Array represents a min-heap
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        
        
        if (isMinHeap(arr, n)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}


/*
2
7
10 15 30 40 50 100 40
3
15 10 18

*/