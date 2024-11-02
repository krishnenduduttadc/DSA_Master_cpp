#include <bits/stdc++.h>
using namespace std;

int main() {
    int T = 3;
    vector<tuple<vector<int>, vector<int>, vector<int>>> testCases = {
        {{2, 5, 10, 15}, {10, 15}, {5}},
        {{4, 8, 10, 15, 15, 20}, {6, 15, 25, 28, 28, 45}, {10, 15}}
    };
    
    for (const auto& testCase : testCases) {
        vector<int> A = get<0>(testCase);
        vector<int> B = get<1>(testCase);
        vector<int> C = get<2>(testCase);

        int N_A = A.size(), N_B = B.size(), N_C = C.size();
        int i = 0, j = 0, k = 0;
        int min_value = INT_MAX;

        while (i < N_A && j < N_B && k < N_C) {
            int current_max = max({abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])});
            min_value = min(min_value, current_max);

            if (A[i] <= B[j] && A[i] <= C[k]) {
                i++;
            } else if (B[j] <= A[i] && B[j] <= C[k]) {
                j++;
            } else {
                k++;
            }
        }

        cout << min_value << '\n';
    }
}
