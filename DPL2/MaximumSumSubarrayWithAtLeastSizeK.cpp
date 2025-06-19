#include <iostream>
#include <vector>
using namespace std;

int MaximumSumSubarrayWithAtLeastSizeK(vector<int>& arr, int k) {
    int ans = 0;
    int csum = arr[0];
    vector<int> maxsum(arr.size(), 0);

    for (int i = 1; i < arr.size(); i++) {
        if (csum > 0) {
            csum += arr[i];
        } else {
            csum = arr[i];
        }
        maxsum[i] = csum;
    }

    int exactK = 0;
    for (int i = 0; i < k; i++) {
        exactK += arr[i];
    }
    if (exactK > ans) {
        ans = exactK;
    }

    for (int i = k; i < arr.size(); i++) {
        exactK = exactK + arr[i] - arr[i - k];
        if (exactK > ans) {
            ans = exactK;
        }
        int morethanK = maxsum[i - k] + exactK;
        if (morethanK > ans) {
            ans = morethanK;
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {5, 6, 7, 4, 3, 6, 4};
    int k = 4;

    int maxSum = MaximumSumSubarrayWithAtLeastSizeK(arr, k);
    cout << maxSum << endl;

    return 0;
}
