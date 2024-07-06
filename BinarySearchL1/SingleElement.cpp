#include <iostream>
#include <vector>

using namespace std;

class SingleElement {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int middle = left + (right - left) / 2;

            // Check if middle is a single element
            if (middle % 2 == 0) {
                // If middle is even, the single element should be to its right
                if (nums[middle] == nums[middle + 1]) {
                    left = middle + 2; // Move to the right of middle
                } else {
                    right = middle; // Single element is to the left of middle
                }
            } else {
                // If middle is odd, the single element should be to its left
                if (nums[middle] == nums[middle - 1]) {
                    left = middle + 1; // Move to the right of middle
                } else {
                    right = middle; // Single element is to the left of middle
                }
            }
        }

        return nums[left];
    }
};

int main() {
    // Example usage
    vector<int> arr = {0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 5}; // Example array

    SingleElement solution;
    int result = solution.singleNonDuplicate(arr);

    cout << "Single non-duplicate element: " << result << endl;

    return 0;
}
