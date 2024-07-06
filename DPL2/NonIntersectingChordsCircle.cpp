#include <iostream>
#include <vector>
using namespace std;

long long noOfChords(int n) {
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
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
    int n = 6;
    cout << "Number of non-intersecting chords for " << n << " points: " << noOfChords(n) << endl;
    return 0;
}
