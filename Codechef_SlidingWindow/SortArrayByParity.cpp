#include <bits/stdc++.h>
using namespace std;

void sortArrayByParity(vector<int>& nums) {
    int odd_count = 0;
    for(auto num: nums) {
        if(num % 2 != 0) odd_count++;
    }
    int left = 0, right = odd_count;
    vector<int> result(nums.size());
    for(auto num: nums) {
        if(num % 2 == 0) {
            result[right] = num;
            right++;
        } else {
            result[left] = num;
            left++;
        }
    }
    nums = result;
}

int main() {
    vector<int> nums = {3, 1, 2, 4, 5}; // Hardcoded input

    sortArrayByParity(nums);

    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }

    return 0;
}
