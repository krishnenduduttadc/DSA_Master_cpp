#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> twoSum(vector<int> nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end()); // Sorting the array
    
    int left = 0, right = n - 1;
    while (left < right) {
        if (left > 0 && nums[left] == nums[left - 1]) { // Skip duplicates for left pointer
            left++;
            continue;
        }
        
        int sum = nums[left] + nums[right];
        
        if (sum == target) {
            res.push_back({nums[left], nums[right]});
            left++;
            right--;
            
            // Skip duplicates for both left and right pointers
            while (left < right && nums[left] == nums[left - 1]) left++;
            while (left < right && nums[right] == nums[right + 1]) right--;
            
        } else if (sum > target) {
            right--;
        } else {
            left++;
        }
    }
    
    return res;
}

int main() {
    vector<int> nums = {2, 2, 4, 3, 1, 6, 6, 7, 5, 9, 1, 8, 9};
    int target = 10;
    
    vector<vector<int>> res = twoSum(nums, target);
    
    sort(res.begin(), res.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    });

    for (auto& pair : res) {
        for (int val : pair) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    return 0;
}
