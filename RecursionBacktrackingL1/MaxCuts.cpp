#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxcuts(int n, int a, int b, int c) {
    if (n == 0) return 0;
    if (n < 0) return -1; 
    
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int maxCuts = -1;
        if (i >= a && dp[i - a] != -1) {
            maxCuts = max(maxCuts, dp[i - a] + 1);
        }
        if (i >= b && dp[i - b] != -1) {
            maxCuts = max(maxCuts, dp[i - b] + 1);
        }
        if (i >= c && dp[i - c] != -1) {
            maxCuts = max(maxCuts, dp[i - c] + 1);
        }
        dp[i] = maxCuts;
    }

    return dp[n];
}

int main() {
    cout << "Maximum cuts: " << maxcuts(27, 14, 13, 3) << endl;
    return 0;
}
