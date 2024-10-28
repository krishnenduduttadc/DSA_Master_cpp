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
    // Hardcoded input
    int t = 2; // Number of test cases
    
    // Test case 1
    int n1 = 7;
    int arr1[] = {10, 15, 30, 40, 50, 100, 40};

    // Test case 2
    int n2 = 3;
    int arr2[] = {15, 10, 18};

    // Array of test cases
    pair<int*, int> testCases[] = {
        {arr1, n1},
        {arr2, n2}
    };

    // Iterate through the test cases
    for (int i = 0; i < t; i++) {
        int* arr = testCases[i].first;
        int n = testCases[i].second;

        if (isMinHeap(arr, n)) {
            cout << "Yes" << endl; // It's a min-heap
        } else {
            cout << "No" << endl; // It's not a min-heap
        }
    }

    return 0;
}

/*
Output:
No
No
*/
