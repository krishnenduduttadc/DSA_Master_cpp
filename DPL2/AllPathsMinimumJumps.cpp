#include <iostream>
#include <climits>
#include <queue>
#include <string>
using namespace std;

struct Pair {
    int i, s, j;
    string psf;

     Pair(int ii, int ss, int jj, string p) {
        i = ii;
        s = ss;
        j = jj;
        psf = p;
    }
};

void solution(const int arr[], int n) {
    int dp[n];
    fill_n(dp, n, INT_MAX);
    dp[n - 1] = 0;

    for (int i = n - 2; i >= 0; i--) {
        int steps = arr[i];
        int min_steps = INT_MAX;

        for (int j = 1; j <= steps && i + j < n; j++) {
            if (dp[i + j] != INT_MAX && dp[i + j] < min_steps) {
                min_steps = dp[i + j];
            }
        }

        if (min_steps != INT_MAX) {
            dp[i] = min_steps + 1;
        }
    }

    cout << dp[0] << endl;

    queue<Pair> q;
    q.emplace(Pair(0, arr[0], dp[0], "0"));

    while (!q.empty()) {
        Pair rem = q.front();
        q.pop();

        if (rem.j == 0) {
            cout << rem.psf << "." << endl;
        }

        for (int j = 1; j <= rem.s && rem.i + j < n; j++) {
            int ci = rem.i + j;
            if (dp[ci] != INT_MAX && dp[ci] == rem.j - 1) {
                q.emplace(Pair(ci, arr[ci], dp[ci], rem.psf + "->" + to_string(ci)));
            }
        }
    }
}

int main() {
    const int arr[] = {3, 3, 0, 2, 1, 2, 4, 2, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    solution(arr, n);
    return 0;
}
