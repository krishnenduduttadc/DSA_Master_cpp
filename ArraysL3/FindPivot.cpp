#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    int totalSum = 0;
    for (int num : nums) {
        totalSum += num;
    }

    int idx = -1;
    int currSum = 0;

    for (int i = 0; i < n; i++) {
        if (currSum == totalSum - currSum - nums[i]) {
            idx = i;
            break;
        }
        currSum += nums[i];
    }
    return idx;
}

int main() {
    vector<int> arr = {2, 2, 3, 3, 4, 3};
    cout << pivotIndex(arr) << endl;
    return 0;
}
