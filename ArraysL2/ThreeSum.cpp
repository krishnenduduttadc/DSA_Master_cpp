#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> twoSum(vector<int>& nums, int target, int si) {
    int n = nums.size();
    vector<vector<int>> res;

    if (n - si < 2) return res;

    int left = si;
    int right = n - 1;

    while (left < right) {
        if (left != si && nums[left] == nums[left - 1]) {
            left++;
            continue;
        }

        int sum = nums[left] + nums[right];

        if (sum == target) {
            res.push_back({ nums[left], nums[right] });
            left++;
            right--;

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

vector<vector<int>> kSumHelper(vector<int>& nums, int target, int k, int si) {
    if (k == 2) {
        return twoSum(nums, target, si);
    }

    int n = nums.size();
    vector<vector<int>> res;

    if (n - si < k) return res;

    for (int i = si; i <= n - k; i++) {
        if (i != si && nums[i] == nums[i - 1]) {
            continue;
        }

        int val1 = nums[i];
        vector<vector<int>> subRes = kSumHelper(nums, target - val1, k - 1, i + 1);
        for (auto& list : subRes) {
            list.push_back(val1);
            res.push_back(list);
        }
    }

    return res;
}

vector<vector<int>> threeSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    return kSumHelper(nums, target, 3, 0);
}

int main() {
    vector<int> arr = {50, 30, 10, 60, 20, 40, 90, 80, 10, 20, 40};
    int target = 100;

    vector<vector<int>> res = threeSum(arr, target);

    // Sorting each triplet and then sorting all triplets lexicographically
    for (auto& list : res) {
        sort(list.begin(), list.end());
    }
    sort(res.begin(), res.end());

    // Printing the result
    for (auto& triplet : res) {
        for (int val : triplet) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
