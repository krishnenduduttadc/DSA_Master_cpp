#include <iostream>
using namespace std;

int countBST(int n) {
    int dp[n + 1];
    
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = 0;  // Initialize dp[i] to 0
        int l = 0;
        int r = i - 1;
        while (l <= i - 1) {
            dp[i] += dp[l] * dp[r];
            l++;
            r--;
        }
    }

    return dp[n];
}

int main() {
    int n = 4;
    cout << countBST(n) << endl;
    return 0;
}
