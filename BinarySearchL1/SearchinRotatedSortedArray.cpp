#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] == target) {
            return mid;
        }

        // Left half is sorted
        if (nums[lo] <= nums[mid]) {
            if (target >= nums[lo] && target < nums[mid]) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        // Right half is sorted
        else {
            if (target > nums[mid] && target <= nums[hi]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
    }

    return -1; // Target not found
}

int main() {
    vector<int> nums1 = {4, 5, 6, 7, 0, 1, 2};
    int target1 = 0;
    cout << "Index of " << target1 << " in nums1: " << search(nums1, target1) << endl; // Output: 4

    return 0;
}
