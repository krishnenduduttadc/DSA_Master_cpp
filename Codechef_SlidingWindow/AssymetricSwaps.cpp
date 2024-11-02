#include <bits/stdc++.h>

using namespace std;

int main() {
    int T = 3;
    vector<pair<vector<int>, vector<int>>> testCases = {
        {{2, 1, 3}, {1, 4, 1}},
        {{2, 1, 4, 3}, {3, 2, 6, 2}},
        {{2, 8, 4, 9, 7}, {7, 3, 6, 8, 4}}
    };

    for (const auto& testCase : testCases) {
        vector<int> A = testCase.first;
        vector<int> B = testCase.second;

        int N = A.size();
        vector<int> C(2 * N);
        for (int i = 0; i < N; ++i) {
            C[i] = A[i];
            C[i + N] = B[i];
        }

        sort(C.begin(), C.end());

        int min_diff = INT_MAX;
        for (int i = 0; i <= N; ++i) {
            int current_diff = C[i + N - 1] - C[i];
            min_diff = min(min_diff, current_diff);
        }

        cout << min_diff << endl;
    }

}
