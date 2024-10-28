#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 2001;

int C[N][N];

int combinations(int n, int k) {
    if (n == k || k == 0) {
        return 1;
    }
    if (k > n) {
        return 0;
    }
    if (C[n][k] != -1) {
        return C[n][k];
    }

    C[n][k] = (combinations(n - 1, k - 1) + combinations(n - 1, k)) % mod;

    return C[n][k];
}

int main() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) C[i][j] = -1;

    int n = 7, k = 3;
    cout << n << "C" << k << " is: " << combinations(n, k) << "\n";

    return 0;
}
