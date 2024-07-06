#include <iostream>
using namespace std;

// Function to calculate subset sums recursively
void subsetSums(int arr[], int l, int r, int sum) {
    // Base case: if l exceeds r, print the current sum
    if (l > r) {
        cout << sum << " ";
        return;
    }
    
    // Recursive case: include current element arr[l] in the subset sum
    subsetSums(arr, l + 1, r, sum + arr[l]);
}

int main() {
    // Initialize the array and its length
    int arr[] = {5, 4, 3, 5, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    // Call the function to calculate subset sums, starting with l=0, r=n-1, and initial sum=0
    subsetSums(arr, 0, n - 1, 0);
    
    return 0;
}
