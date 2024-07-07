#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int largestPerimeter(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    int p = 0;

    for (int i = nums.size() - 1; i >= 2; --i) {
        if (nums[i - 1] + nums[i - 2] > nums[i]) {
            p = nums[i - 1] + nums[i - 2] + nums[i];
            break;
        }
    }

    return p;
}

int main() {
    vector<int> nums = {25, 6, 9, 11, 8, 12, 10, 3, 2};

    cout << largestPerimeter(nums) << endl;

    return 0;
}
