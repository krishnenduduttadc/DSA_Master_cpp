#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int MaxSumIncreasingSubseq(vector<int>& arr) {
    int omax = INT_MIN;
    vector<int> dp(arr.size());

    for (int i = 0; i < dp.size(); i++) {
        int maxSum = arr[i];
        for (int j = 0; j < i; j++) {
            if (arr[j] <= arr[i]) {
                maxSum = max(maxSum, dp[j] + arr[i]);
            }
        }
        dp[i] = maxSum;
        omax = max(omax, dp[i]);
    }

    return omax;
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80, 3};

    int maxSum = MaxSumIncreasingSubseq(arr);
    cout << maxSum << endl;

    return 0;
}
