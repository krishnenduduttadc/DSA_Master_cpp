#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        int A, B, N;
        cin >> A >> B >> N;
        int X = A ^ B; // Calculate the XOR of A and B

        if (X == 0) {
            // Case 1: If A is already equal to B
            cout << 0 << '\n';
        } else if (X < N) {
            // Case 2: If X (A ^ B) is less than N, we can achieve it in one step
            cout << 1 << '\n';
        } else if (N != 1 && (1 << (int)log2(X)) < N) {
            // Case 3: If the most significant bit of X can be matched with N
            // (1 << (int)log2(X)) gives 2^floor(log2(X)), check if it's less than N
            cout << 2 << '\n';
        } else {
            // Case 4: Otherwise, it's not possible
            cout << -1 << '\n';
        }
    }
    return 0;
}


/*
3
5 5 2
3 7 8
8 11 1

*/