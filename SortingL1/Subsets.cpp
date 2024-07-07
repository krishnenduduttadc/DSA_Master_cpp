#include <iostream>
#include <vector>
using namespace std;

class Subsets {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int totalno = (1 << n);
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

private:
    // Helper function to check if the i-th bit in n is set
    bool checkBit(int n, int i) {
        return (n & (1 << i)) != 0;
    }
};

int main() {
    // Create an instance of the Subsets class
    Subsets solution;

    // Hardcoded input array
    vector<int> nums = {1, 2, 3}; // Example input

    // Calling subsets to generate all subsets of the array
    vector<vector<int>> subsets = solution.subsets(nums);

    // Printing all subsets
    for (auto& subset : subsets) {
        cout << "[";
        for (size_t i = 0; i < subset.size(); i++) {
            cout << subset[i];
            if (i < subset.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    return 0;
}
