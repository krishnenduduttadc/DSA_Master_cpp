#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int subarraySumEqualsK(const vector<int> arr, int target) {
    int ans = 0;
    unordered_map<int, int> prefixSumFreq;
    prefixSumFreq[0] = 1;  // To handle subarrays that sum to target starting from index 0
    int sum = 0;

    for (int num : arr) {
        sum += num;
        int rsum = sum - target;
        if (prefixSumFreq.find(rsum) != prefixSumFreq.end()) {
            ans += prefixSumFreq[rsum];
        }
        prefixSumFreq[sum]++;
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 9, -2, 4, 1, -7, 2, 6, -5, 8, -3, -7, 6, 2, 1};
    int k = 5;
    cout << subarraySumEqualsK(arr, k) << endl;
    return 0;
}
