#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map; // Hash map to store number and its index
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];

        if (map.find(complement) != map.end()) {
            result.push_back(map[complement]);
            result.push_back(i);
            return result;
        }

        map[nums[i]] = i;
    }

    throw invalid_argument("No two sum solution");
}

int main() {
    vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;

    vector<int> nums2 = {3, 2, 4};
    int target2 = 6;

    vector<int> result1 = twoSum(nums1, target1);
    vector<int> result2 = twoSum(nums2, target2);

    cout << "Output for nums1: [" << result1[0] << ", " << result1[1] << "]" << endl;
    cout << "Output for nums2: [" << result2[0] << ", " << result2[1] << "]" << endl;

    return 0;
}
