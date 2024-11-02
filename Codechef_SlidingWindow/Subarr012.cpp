#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long countSubarrays(vector<long long>& arr) {
    long long n = arr.size();
    long long left = 0, right = 0;
    long long count = 0;

    unordered_map<long long, long long> freq; // To store frequency of 0, 1, 2

    // Traverse the array with the sliding window approach
    while (right < n) {
        // Include the current element in the window
        freq[arr[right]]++;

        // Check if the window contains at least one 0, one 1, and one 2
        while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
            // If the window [left, right] is valid, all subarrays starting from
            // left to right are valid. There are (n - right) such subarrays.
            count += (n - right);
            
            // Now, shrink the window by moving the left pointer
            freq[arr[left]]--;
            left++;
        }

        // Expand the window by moving the right pointer
        right++;
    }

    return count;
}

int main() {
    vector<long long> arr = {0, 1, 2, 0}; // Hardcoded input

    cout << countSubarrays(arr) << endl;

    return 0;
}
