#include <iostream>
#include <vector>

using namespace std;

int findMin(vector<int> nums) {
    int lo = 0, hi = nums.size() - 1;
    int ans = nums[0];

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[lo] <= nums[hi]) {
            ans = min(ans, nums[lo]);
            break;
        }

        ans = min(ans, nums[mid]);

        if (nums[mid] >= nums[lo]) {
            lo = mid + 1;  // Go right
        } else {
            hi = mid - 1;  // Go left
        }
    }

    return ans;
}

int main() {
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Minimum element in nums1: " << findMin(nums1) << endl;  // Output: 1

    return 0;
}
