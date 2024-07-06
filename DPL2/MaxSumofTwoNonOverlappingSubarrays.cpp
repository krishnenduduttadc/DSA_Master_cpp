#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int>& arr, int x, int y) {
    int n = arr.size();
    vector<int> dp1(n);
    vector<int> dp2(n);
    int sum = 0;

    // Calculate dp1 array
    for (int i = 0; i < n; i++) {
        if (i < x) {
            sum += arr[i];
            dp1[i] = sum;
        } else {
            sum += arr[i] - arr[i - x];
            dp1[i] = max(dp1[i - 1], sum);
        }
    }

    sum = 0;
    // Calculate dp2 array
    for (int i = n - 1; i >= 0; i--) {
        if (i + y >= n) {
            sum += arr[i];
            dp2[i] = sum;
        } else {
            sum += arr[i] - arr[i + y];
            dp2[i] = max(dp2[i + 1], sum);
        }
    }

    int ans = 0;
    // Calculate maximum sum of two non-overlapping subarrays
    for (int i = x - 1; i < n - y; i++) {
        ans = max(ans, dp1[i] + dp2[i + 1]);
    }

    dp1.clear();
    dp2.clear();
    dp1.resize(n);
    dp2.resize(n);
    sum = 0;

    // Calculate dp1 array (for the reverse case)
    for (int i = 0; i < n; i++) {
        if (i < y) {
            sum += arr[i];
            dp1[i] = sum;
        } else {
            sum += arr[i] - arr[i - y];
            dp1[i] = max(dp1[i - 1], sum);
        }
    }

    sum = 0;
    // Calculate dp2 array (for the reverse case)
    for (int i = n - 1; i >= 0; i--) {
        if (i + x >= n) {
            sum += arr[i];
            dp2[i] = sum;
        } else {
            sum += arr[i] - arr[i + x];
            dp2[i] = max(dp2[i + 1], sum);
        }
    }

    // Calculate maximum sum of two non-overlapping subarrays (for the reverse case)
    for (int i = y - 1; i < n - x; i++) {
        ans = max(ans, dp1[i] + dp2[i + 1]);
    }

    return ans;
}

int main() {
    vector<int> arr = {3, 8, 1, 3, 2, 1, 8, 9, 0};
    int x = 2;
    int y = 3;
    
    int maxSum = solution(arr, x, y);
    cout << maxSum << endl;

    return 0;
}
