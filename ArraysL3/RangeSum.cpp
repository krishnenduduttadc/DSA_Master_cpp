#include <iostream>
#include <vector>
using namespace std;

vector<int> prefixSum;

void NumArray(vector<int>& nums) {
    prefixSum.resize(nums.size());
    prefixSum[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        prefixSum[i] = prefixSum[i - 1] + nums[i];
    }
}

int sumRange(int i, int j) {
    if (i == 0) {
        return prefixSum[j];
    }
    return prefixSum[j] - prefixSum[i - 1];
}

int main() {
    vector<int> arr = {1, 2, 3, 4};
    NumArray(arr);
    int res = sumRange(1, 2);
    cout << res << endl; // Output should be 5

    return 0;
}
