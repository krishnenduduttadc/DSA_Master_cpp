#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T; // Read number of test cases
    while (T--) {
        int N;
        cin >> N; // Read size of arrays A and B
        vector < int > A(N), B(N);

        for (int i = 0; i < N; ++i) {
            cin >> A[i]; // Read elements of array A
        }

        for (int i = 0; i < N; ++i) {
            cin >> B[i]; // Read elements of array B
        }

        // Combine arrays A and B into a single array C
        vector<int> C(2 * N);
        for (int i = 0; i < N; ++i) {
            C[i] = A[i];
            C[i + N] = B[i];
        }

        // Sort the combined array C
        sort(C.begin(), C.end());

        // Find the minimum difference in any subarray of length N
        int min_diff = INT_MAX;
        for (int i = 0; i <= N; ++i) {
            int current_diff = C[i + N - 1] - C[i];
            min_diff = min(min_diff, current_diff);
        }

        // Output the minimum difference found
        cout << min_diff << endl;
    }

}

/*
3
3
2 1 3
1 4 1
4
2 1 4 3
3 2 6 2
5
2 8 4 9 7
7 3 6 8 4


*/