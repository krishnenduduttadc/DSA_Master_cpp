#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
    cin >> T;
    while (T--) {
        int N_A, N_B, N_C;
        cin >> N_A >> N_B >> N_C;
        
        vector<int> A(N_A), B(N_B), C(N_C);
        for (int i = 0; i < N_A; ++i) cin >> A[i];
        for (int i = 0; i < N_B; ++i) cin >> B[i];
        for (int i = 0; i < N_C; ++i) cin >> C[i];
        
        int i = 0, j = 0, k = 0;
        int min_value = INT_MAX;

        // Use the two pointers technique
        while (i < N_A && j < N_B && k < N_C) {
            int current_max = max({abs(A[i] - B[j]), abs(B[j] - C[k]), abs(C[k] - A[i])});
            min_value = min(min_value, current_max);

            // Move the pointer which will potentially minimize the max difference
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


/*
3
4 2 2
2 5 10 15
4 4
10 15
1 1 1
5 
10
25
6 6 2
4 8 10 15 15 20
6 15 25 28 28 45 
10 15


*/