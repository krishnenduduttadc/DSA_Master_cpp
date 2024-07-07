#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class MaxSumSubarray {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int ans = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if (sum < 0) {
                sum = nums[i];
            } else {
                sum += nums[i];
            }
            ans = max(sum, ans);
        }
        return ans;
    }
};

int main() {
    MaxSumSubarray maxSumSubarray;
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    int result = maxSumSubarray.maxSubArray(arr);
    cout << "Maximum sum of subarray: " << result << endl; // Output should be 6 (subarray [4,-1,2,1])

    return 0;
}
