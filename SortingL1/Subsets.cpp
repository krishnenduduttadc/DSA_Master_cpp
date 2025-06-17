#include <iostream>
#include <vector>
using namespace std;

// Helper function to check if the i-th bit in n is set
bool checkBit(int n, int i) {
    return (n & (1 << i)) != 0;
}

// Function to generate all subsets of a given vector
vector<vector<int>> generateSubsets(const vector<int>& nums) {
    int n = nums.size();
    int totalno = 1 << n; // 2^n subsets
    vector<vector<int>> ans;

    for (int i = 0; i < totalno; i++) {
        vector<int> temp;
        for (int j = 0; j < n; j++) {
            if (checkBit(i, j)) {
                temp.push_back(nums[j]);
            }
        }
        ans.push_back(temp);
    }

    return ans;
}

int main() {
    // Hardcoded input array
    vector<int> nums = {1, 2, 3};

    // Generate subsets
    vector<vector<int>> subsets = generateSubsets(nums);

    // Print subsets
    for (const auto& subset : subsets) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
