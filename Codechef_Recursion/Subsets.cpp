#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void allPossibleSubsets(vector<int>& arr, int curIndex, vector<int>& curSubset, vector<vector<int>>& allSubsets) {
    if (curIndex == arr.size()) {
        vector<int> newSet(curSubset.begin(), curSubset.end());
        allSubsets.push_back(newSet);
        return;
    }
    // Include the current element
    curSubset.push_back(arr[curIndex]);
    allPossibleSubsets(arr, curIndex + 1, curSubset, allSubsets);
    // Exclude the current element
    curSubset.pop_back();
    allPossibleSubsets(arr, curIndex + 1, curSubset, allSubsets);
}

int main() {
    // Hardcoded input
    int n = 3; // Size of the array
    vector<int> arr = {1, 2, 3}; // The array elements

    vector<int> curSubset;
    vector<vector<int>> allSubsets;
    allPossibleSubsets(arr, 0, curSubset, allSubsets);
    
    // Sort subsets lexicographically
    sort(allSubsets.begin(), allSubsets.end());
    
    // Output all subsets
    for (const auto& subset : allSubsets) {
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
