#include <iostream>
#include <unordered_set> // for unordered_set

using namespace std;

int countDistinct(int arr[], int n) {
    unordered_set<int> h; // Declaration of unordered_set to store distinct elements
    
    for (int i = 0; i < n; i++) {
        h.insert(arr[i]);
    }
    
    return h.size();
}

int main() {
    int arr[] = {15, 16, 27, 27, 28, 15};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the size of the array
    
    cout << countDistinct(arr, n) << endl;

    return 0;
}
