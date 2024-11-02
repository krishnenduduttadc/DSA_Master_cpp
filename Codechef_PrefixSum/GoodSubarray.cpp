#include <bits/stdc++.h>

using namespace std;

int main() {
    int n = 3, k = 1; // Hardcoded input values
    // Output the hardcoded input
    cout << n << " " << k << endl;

    // Initialize an array to store n integers
    vector<int> arr = {1, 0, 3}; // Hardcoded array values

    // Create prefix sum array
    vector<long long> prefix(n);
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    int count = 0;

    // Count subarrays with sum equal to k
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum;
            if (i == 0) {
                sum = prefix[j];
            } else {
                sum = prefix[j] - prefix[i - 1];
            }

            if (sum == k) count++;
        }
    }

    cout << count << endl; // Output the count of subarrays

    return 0;
}
