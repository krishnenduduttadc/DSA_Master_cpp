#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isValidSplit(vector<int>& arr, int maxSum, int m) {
    int subArrayCount = 1; // Start with one subarray
    int currentSum = 0;

    for (int num : arr) {
        currentSum += num;
        if (currentSum > maxSum) {
            subArrayCount++;
            currentSum = num; // Start a new subarray
            if (subArrayCount > m) {
                return false; // Cannot split into <= m subarrays with max sum <= maxSum
            }
        }
    }

    return true;
}

int splitArray(vector<int>& arr, int m) {
    int maxVal = 0;
    int sum = 0;

    // Calculate max element and total sum
    for (int val : arr) {
        sum += val;
        maxVal = max(val, maxVal);
    }

    // If m is equal to the length of the array, return the maximum element
    if (m == arr.size()) {
        return maxVal;
    }

    // Binary search for the minimum possible maximum sum
    int lo = maxVal;
    int hi = sum;
    int ans = 0;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (isValidSplit(arr, mid, m)) {
            ans = mid; // Found a valid split, try for smaller max
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {7, 2, 5, 10, 8};
    int m = 2;

    int ans = splitArray(arr, m);
    cout << ans << endl; // Output should be 18

    return 0;
}
