#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> twoSum(vector<int>& arr, int si, int ei, int target) {
    int left = si;
    int right = ei;
    vector<vector<int>> res;
    while (left < right) {
        if (left != si && arr[left] == arr[left - 1]) {
            left++;
            continue;
        }
        int sum = arr[left] + arr[right];

        if (sum == target) {
            res.push_back({arr[left], arr[right]});
            left++;
            right--;
        } else if (sum > target) {
            right--;
        } else {
            left++;
        }
    }
    return res;
}

vector<vector<int>> threeSum(vector<int>& arr, int target, int si) {
    vector<vector<int>> res;
    int n = arr.size();
    if (n - si < 3) return res;

    sort(arr.begin() + si, arr.end());

    for (int i = si; i <= n - 3; i++) {
        if (i != si && arr[i] == arr[i - 1]) continue;

        int val1 = arr[i];
        int targ = target - val1;
        vector<vector<int>> subRes = twoSum(arr, i + 1, n - 1, targ);
        for (auto& list : subRes) {
            list.push_back(val1);
            res.push_back(list);
        }
    }
    return res;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    if (n < 4) return res;

    sort(nums.begin(), nums.end());

    for (int i = 0; i <= n - 4; i++) {
        if (i != 0 && nums[i] == nums[i - 1]) continue;

        int val1 = nums[i];
        vector<vector<int>> subRes = threeSum(nums, target - val1, i + 1);
        for (auto& list : subRes) {
            list.push_back(val1);
            res.push_back(list);
        }
    }
    return res;
}

int main() {
    vector<int> arr = {10, 10, 5, 15, 6, 4, 20};
    int target = 40;
    vector<vector<int>> res = fourSum(arr, target);

    // Sorting each quadruplet and final result for consistency with Java output
    for (auto& list : res) {
        sort(list.begin(), list.end());
    }
    sort(res.begin(), res.end(), [](const vector<int>& a, const vector<int>& b) {
        return a < b;
    });

    for (auto& list : res) {
        for (int val : list) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
