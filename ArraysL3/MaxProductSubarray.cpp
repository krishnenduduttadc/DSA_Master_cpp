#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int maxProduct(vector<int>& nums) {
    int n = nums.size();

    int pf1 = 1;
    int max1 = INT_MIN;
    int pf2 = 1;
    int max2 = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (pf1 == 0) {
            pf1 = nums[i];
        } else {
            pf1 = pf1 * nums[i];
        }
        max1 = max(max1, pf1);
    }

    for (int i = n - 1; i >= 0; i--) {
        if (pf2 == 0) {
            pf2 = nums[i];
        } else {
            pf2 = pf2 * nums[i];
        }
        max2 = max(max2, pf2);
    }

    return max(max1, max2);
}

int main() {
    vector<int> arr = {2, 3, -2, 4};
    int result = maxProduct(arr);
    cout << "Maximum product of subarray: " << result << endl; // Expected output: 6 (subarray [2, 3])
    return 0;
}
