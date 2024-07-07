#include <iostream>
#include <vector>
using namespace std;

class MajorityElement {
public:
    int majorityElement(vector<int>& nums) {
        int val = nums[0];
        int count = 1;

        for (int i = 1; i < nums.size(); i++) {
            if (count == 0) {
                val = nums[i];
                count = 1;
            } else if (nums[i] == val) {
                count++;
            } else {
                count--;
            }
        }

        return val;
    }
};

int main() {
    MajorityElement solution;
    vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2, 3, 3, 3, 3, 3};
    int result2 = solution.majorityElement(nums2);
    cout << "Majority element: " << result2 << endl; // Expected output: 3
    return 0;
}
