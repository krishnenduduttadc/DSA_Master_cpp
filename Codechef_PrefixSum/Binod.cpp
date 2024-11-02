#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 2;
    cout << T << endl;

    int N = 5, Q = 2;
    cout << N << " " << Q << endl;
    cout << "1 2 4 3 2" << endl;
    cout << "1 1 3 5 5" << endl;
    cout << "2 1 2 3 5" << endl;

    N = 6, Q = 2;
    cout << N << " " << Q << endl;
    cout << "3 5 6 13 12 20" << endl;
    cout << "1 1 4 5 6" << endl;
    cout << "3 2 3 4 6" << endl;

    vector<long long> A(7);
    A[1] = 1; A[2] = 2; A[3] = 4; A[4] = 3; A[5] = 2;
    vector<vector<int>> pref(60, vector<int>(6, 0));

    for (int i = 1; i <= 5; ++i) {
        for (int k = 0; k < 60; ++k) {
            pref[k][i] = pref[k][i - 1] + ((A[i] >> k) & 1);
        }
    }

    int k = 1, L1 = 1, R1 = 3, L2 = 5, R2 = 5;
    int S1 = pref[k][R1] - pref[k][L1 - 1];
    int S2 = pref[k][R2] - pref[k][L2 - 1];
    int U1 = (R1 - L1 + 1) - S1;
    int U2 = (R2 - L2 + 1) - S2;
    long long answer = (long long) S1 * U2 + (long long) U1 * S2;
    cout << answer << "\n";

    A[1] = 3; A[2] = 5; A[3] = 6; A[4] = 13; A[5] = 12; A[6] = 20;
    for (int i = 1; i <= 6; ++i) {
        for (int k = 0; k < 60; ++k) {
            pref[k][i] = pref[k][i - 1] + ((A[i] >> k) & 1);
        }
    }

    k = 1; L1 = 1; R1 = 4; L2 = 5; R2 = 6;
    S1 = pref[k][R1] - pref[k][L1 - 1];
    S2 = pref[k][R2] - pref[k][L2 - 1];
    U1 = (R1 - L1 + 1) - S1;
    U2 = (R2 - L2 + 1) - S2;
    answer = (long long) S1 * U2 + (long long) U1 * S2;
    cout << answer << "\n";

    k = 3; L1 = 2; R1 = 3; L2 = 4; R2 = 6;
    S1 = pref[k][R1] - pref[k][L1 - 1];
    S2 = pref[k][R2] - pref[k][L2 - 1];
    U1 = (R1 - L1 + 1) - S1;
    U2 = (R2 - L2 + 1) - S2;
    answer = (long long) 
