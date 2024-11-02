#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

long long computeSumOfSquares(vector<int>& arr) {
    long long sum = 0;
    for (int num : arr) {
        sum = (sum + (num * 1LL * num) % MOD) % MOD;
    }
    return sum;
}

int main() {
    // Hardcoded input
    int t = 2; // Number of test cases

    // Test case 1
    vector<vector<int>> testCases = {
        {2, 34, 4, 56, 76}, // First test case
        {23, 7, 21}         // Second test case
    };

    for (int i = 0; i < t; i++) {
        int n = testCases[i].size(); // Get the number of elements for the current test case
        vector<int> arr = testCases[i]; // Use the hardcoded values

        long long result = computeSumOfSquares(arr);
        cout << result << endl; // Output the result for the current test case
    }

    return 0;
}

/*
Hardcoded Input:
2
5
2 34 4 56 76
3
23 7 21
*/
