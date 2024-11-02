#include <bits/stdc++.h>
using namespace std;

// Function to perform a linear search recursively
int linearSearch(vector<int>& arr, int n, int x) {
    if (n == arr.size()) {
        return -1; // Element not found
    }
    if (arr[n] == x) {
        return n; // Element found at index n
    }
    return linearSearch(arr, n + 1, x); // Recursive call for the next index
}

int main() {
    // Hardcoded input values
    int n = 5; // Size of the array
    int x = 9; // Element to search for
    vector<int> arr = {1, 4, 9, 2, 8}; // The array

    // Call the linear search function and output the result
    cout << linearSearch(arr, 0, x) << endl;

    return 0;
}
