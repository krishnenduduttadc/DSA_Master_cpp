#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T = 3;
    vector<tuple<int, int, int>> test_cases = {
        {5, 5, 2},
        {3, 7, 8},
        {8, 11, 1}
    };

    for (const auto& test_case : test_cases) {
        int A = get<0>(test_case);
        int B = get<1>(test_case);
        int N = get<2>(test_case);
        
        int X = A ^ B;

        if (X == 0) {
            cout << 0 << '\n';
        } else if (X < N) {
            cout << 1 << '\n';
        } else if (N != 1 && (1 << (int)log2(X)) < N) {
            cout << 2 << '\n';
        } else {
            cout << -1 << '\n';
        }
    }
    return 0;
}
