#include <iostream>
#include <vector>

using namespace std;

class FindMinimuminRotatedSortedArray {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int ans = -1;
        int lo = 0, hi = nums.size() - 1;

        while (lo <= hi) {
            int m = (lo + hi) / 2;
            
            if (nums[m] <= nums[hi]) {
                if (ans == -1 || nums[m] < nums[ans]) {
                    ans = m;
                }
                hi = m - 1;
            } else {
                if (ans == -1 || nums[lo] < nums[ans]) {
                    ans = lo;
                }
                lo = m + 1;
            }
        }
        
        return nums[ans];
    }
};

int main() {
    FindMinimuminRotatedSortedArray solution;

    // Example test cases
    vector<int> nums1 = {3, 4, 5, 1, 2};
    cout << "Minimum element in nums1: " << solution.findMin(nums1) << endl; // Output: 1

    return 0;
}
