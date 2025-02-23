#include <iostream>
#include <vector>

using namespace std;

int singleNonDuplicate(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int middle = left + (right - left) / 2;

        if (middle % 2 == 0) {
            if (nums[middle] == nums[middle + 1]) {
                left = middle + 2;
            } else {
                right = middle;
            }
        } else {
            if (nums[middle] == nums[middle - 1]) {
                left = middle + 1;
            } else {
                right = middle;
            }
        }
    }

    return nums[left];
}

int main() {
    vector<int> arr = {0, 1, 1, 2, 2, 3, 3, 4, 4, 5, 5}; // Example array

    int result = singleNonDuplicate(arr);
    cout << "Single non-duplicate element: " << result << endl;

    return 0;
}
