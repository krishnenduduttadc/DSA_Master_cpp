#include <bits/stdc++.h>
using namespace std;

void uniqueCombinationsSum(vector<int> &arr, int sum, int n, set<vector<int>> &allCombinations, vector<int> &currentCombination) {
    if (sum == 0) {
        allCombinations.insert(currentCombination);
        return; // Exit if the sum is zero, to avoid further recursive calls
    }

    // Choose the current element if it's less than or equal to sum
    if (n < arr.size() && sum >= arr[n]) {
        currentCombination.push_back(arr[n]);
        uniqueCombinationsSum(arr, sum - arr[n], n, allCombinations, currentCombination);
        currentCombination.pop_back(); // Backtrack
    }
    
    // Move to the next element
    if (n + 1 < arr.size() && sum >= arr[n + 1]) {
        uniqueCombinationsSum(arr, sum, n + 1, allCombinations, currentCombination);
    }
}

int main() {
    // Hardcoded input
    int t = 3; // Number of test cases
    vector<pair<int, pair<int, vector<int>>>> testCases = {
        {2, {2, {2, 3}}},
        {3, {8, {2, 3, 5}}},
        {3, {7, {2, 3, 6}}}
    };

    for (const auto &test : testCases) {
        int n = test.first;
        int sum = test.second.first;
        vector<int> arr = test.second.second;
        
        vector<int> currentCombination;
        set<vector<int>> allCombinations;

        // Sort the array to handle duplicates
        sort(arr.begin(), arr.end());
        uniqueCombinationsSum(arr, sum, 0, allCombinations, currentCombination);
        
        // Output the number of unique combinations and the combinations themselves
        cout << allCombinations.size() << endl;
        for (const auto &combination : allCombinations) {
            for (int num : combination) {
                cout << num << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
