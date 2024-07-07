#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void wiggleSort(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {
        if (i % 2 == 0) { // even index
            if (nums[i] > nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
        } else { // odd index
            if (nums[i] < nums[i + 1]) {
                swap(nums[i], nums[i + 1]);
            }
        }
    }
}

int main() {
    vector<int> nums = {10, 7, 6, 5, 9, 8};

    wiggleSort(nums);

    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
