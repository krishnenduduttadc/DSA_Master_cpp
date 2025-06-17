#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to calculate Length of Longest Increasing Subsequence using Binary Search
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<int> dp(n, 0);
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int lo = 0, hi = ans;
        while (lo < hi) {
            int m = lo + (hi - lo) / 2;
            if (dp[m] < nums[i]) {
                lo = m + 1;
            } else {
                hi = m;
            }
        }
        dp[lo] = nums[i];
        if (lo == ans) ans++;
    }

    return ans;
}

int main() {
    // Test cases
    vector<int> nums1 = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of LIS for nums1: " << lengthOfLIS(nums1) << endl;

    vector<int> nums2 = {0, 1, 0, 3, 2, 3};
    cout << "Length of LIS for nums2: " << lengthOfLIS(nums2) << endl;

    vector<int> nums3 = {7, 7, 7, 7, 7, 7, 7};
    cout << "Length of LIS for nums3: " << lengthOfLIS(nums3) << endl;

    return 0;
}
