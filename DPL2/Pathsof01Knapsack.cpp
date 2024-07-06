#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct Pair {
    int i;
    int j;
    string psf;

    Pair(int i, int j, string psf) : i(i), j(j), psf(psf) {}
};

void printPaths(vector<vector<int>>& dp, vector<int>& vals, vector<int>& wts, int i, int j, string psf, deque<Pair>& que) {
    while (!que.empty()) {
        Pair rem = que.front();
        que.pop_front();

        if (rem.i == 0 || rem.j == 0) {
            cout << rem.psf << endl;
        } else {
            int exc = dp[rem.i - 1][rem.j];

            if (rem.j >= wts[rem.i - 1]) {
                int inc = dp[rem.i - 1][rem.j - wts[rem.i - 1]] + vals[rem.i - 1];

                if (dp[rem.i][rem.j] == inc) {
                    que.push_back(Pair(rem.i - 1, rem.j - wts[rem.i - 1], to_string(rem.i - 1) + " " + rem.psf));
                }
            }

            if (dp[rem.i][rem.j] == exc) {
                que.push_back(Pair(rem.i - 1, rem.j, rem.psf));
            }
        }
    }
}

void knapsackPaths(vector<int>& vals, vector<int>& wts, int cap) {
    int n = vals.size();
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= cap; j++) {
            dp[i][j] = dp[i - 1][j];

            if (j >= wts[i - 1]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - wts[i - 1]] + vals[i - 1]);
            }
        }
    }

    int ans = dp[n][cap];
    cout << "Maximum value: " << ans << endl;

    deque<Pair> que;
    que.push_back(Pair(n, cap, ""));

    printPaths(dp, vals, wts, n, cap, "", que);
}

int main() {
    vector<int> vals = {15, 14, 10, 45, 30};
    vector<int> wts = {2, 5, 1, 3, 4};
    int cap = 7;

    knapsackPaths(vals, wts, cap);

    return 0;
}
