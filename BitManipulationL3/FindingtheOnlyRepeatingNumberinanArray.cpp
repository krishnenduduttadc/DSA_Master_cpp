#include <iostream>
#include <vector>
using namespace std;

int findRepeatingNumber(vector<int>& nums) {
    int xorSum = 0;
    int n = nums.size();

    // XOR all elements in nums
    for (int num : nums) {
        xorSum ^= num;
    }

    // XOR all numbers from 1 to n-1
    for (int i = 1; i <= n - 1; ++i) {
        xorSum ^= i;
    }

    return xorSum;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 2}; // One element (2) repeats
    int repeatingNumber = findRepeatingNumber(nums);
    cout << "Repeating number: " << repeatingNumber << endl; // Output: 2

    return 0;
}
