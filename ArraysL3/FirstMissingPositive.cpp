#include <iostream>
#include <vector>
using namespace std;

int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();

    int i = 0;
    while (i < n) {
        if (nums[i] == i + 1) {
            i++;
            continue;
        }

        if (nums[i] <= 0 || nums[i] > n) {
            i++;
            continue;
        }

        int idx1 = i;
        int idx2 = nums[i] - 1;

        if (nums[idx1] == nums[idx2]) {
            i++;
            continue;
        }

        int temp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = temp;
    }

    for (int j = 0; j < n; j++) {
        if (nums[j] != j + 1) {
            return j + 1;
        }
    }

    return n + 1;
}

int main() {
    vector<int> nums = {3, 4, -1, 1};
    int result = firstMissingPositive(nums);
    cout << "First missing positive: " << result << endl;
    return 0;
}