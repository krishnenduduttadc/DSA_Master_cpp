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
    curSubset.push_back(arr[curIndex]);
    allPossibleSubsets(arr, curIndex + 1, curSubset, allSubsets);
    curSubset.pop_back();
    allPossibleSubsets(arr, curIndex + 1, curSubset, allSubsets);
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    vector<int> curSubset;
    vector<vector<int>> allSubsets;
    allPossibleSubsets(arr, 0, curSubset, allSubsets);
    sort(allSubsets.begin(), allSubsets.end());
    for (auto subset : allSubsets) {
        for (auto num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}


/*
3
1 2 3
*/