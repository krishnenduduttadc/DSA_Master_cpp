#include <iostream>
#include <vector>

using namespace std;

bool checkBit(int n, int i) {
    return ((n & (1 << i)) != 0);
}

int singleNumber(vector<int>& nums) {
    int ans = 0;

    for (int i = 0; i < 32; i++) {
        int count = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (checkBit(nums[j], i)) {
                count++;
            }
        }

        if (count % 3 == 1) {
            ans = ans | (1 << i);
        }
    }

    return ans;
}

int main() {
    vector<int> nums = {2, 2, 3, 2};
    int result = singleNumber(nums);
    cout << "Single number in nums: " << result << endl; // Expected output: 3

    return 0;
}
