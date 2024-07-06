#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    vector<vector<int>> arr = {{1, 5, 7, 2, 3, 4}, 
                               {5, 8, 4, 3, 6, 1}, 
                               {3, 2, 9, 7, 2, 3}, 
                               {1, 2, 4, 9, 1, 7}};
    int n = arr.size();
    int c = arr[0].size();

    vector<vector<int>> dp(n, vector<int>(c, 0));

    for (int j = 0; j < c; ++j) {
        dp[0][j] = arr[0][j];
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < c; ++j) {
            int minVal = INT_MAX;
            for (int k = 0; k < c; ++k) {
                if (k != j) {
                    minVal = min(minVal, dp[i - 1][k]);
                }
            }
            dp[i][j] = arr[i][j] + minVal;
        }
    }

    int minCost = INT_MAX;
    for (int k = 0; k < c; ++k) {
        minCost = min(minCost, dp[n - 1][k]);
    }

    cout << minCost << endl;

    return 0;
}
