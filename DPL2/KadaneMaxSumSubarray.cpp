#include <iostream>
using namespace std;

int maxSubArraySum(const int arr[], int n) {
    int currentSum = arr[0]; // Initialize current sum and overall sum
    int overallSum = arr[0];
    
    for (int i = 1; i < n; i++) {
        if (currentSum >= 0) {
            currentSum += arr[i]; // Add current element to current sum if positive
        } else {
            currentSum = arr[i]; // Start new subarray if current sum is negative
        }
        
        if (currentSum > overallSum) {
            overallSum = currentSum; // Update overall sum if current sum is greater
        }
    }
    
    return overallSum; // Return maximum sum found
}

int main() {
    const int arr[] = {5, 6, 7, 4, 3, 6, 4}; // Input array
    int n = sizeof(arr) / sizeof(arr[0]); // Determine the number of elements in the array

    cout << maxSubArraySum(arr, n) << endl; // Output maximum sum of subarray
    return 0;
}
