#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    int t = 3;
    vector<vector<int>> test_cases = {
        {2, 1, 3, 5},
        {1},
        {1, 2}
    };

    for (int i = 0; i < t; ++i) {
        int n = test_cases[i].size();
        int ways = 1; 

        for (int j = 0; j < n; j++) {
            ways = (ways * 1ll * (test_cases[i][j] + 1)) % mod;
        }

        cout << ways << "\n";
    }

    return 0;
}
