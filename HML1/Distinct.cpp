#include <iostream>
#include <unordered_set> // for unordered_set

using namespace std;

int countDistinct(int arr[], int n) {
    unordered_set<int> h; // Declaration of unordered_set to store distinct elements
    
    // Adding elements to the unordered_set
    for (int i = 0; i < n; i++) {
        h.insert(arr[i]);
    }
    
    // Return the size of the unordered_set, which represents the number of distinct elements
    return h.size();
}

int main() {
    int arr[] = {15, 16, 27, 27, 28, 15};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    
    // Call the function to count distinct elements and print the result
    cout << countDistinct(arr, n) << endl;

    return 0;
}
