#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<long long> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        if (N == 1) {
            cout << 1 << endl;
            continue;
        }
        
        vector<long long> prefix(N + 1, 0), suffix(N + 1, 0);
        for (int i = 1; i <= N; ++i) {
            prefix[i] = __gcd(prefix[i - 1], A[i - 1]);
        }
        for (int i = N - 1; i >= 0; --i) {
            suffix[i] = __gcd(suffix[i + 1], A[i]);
        }

        long long totalSum = accumulate(A.begin(), A.end(), 0LL);
        long long minNotes = LLONG_MAX;

        for (int i = 0; i < N; ++i) {
            long long currentGCD = __gcd(prefix[i], suffix[i + 1]);
            long long currentSum = totalSum - A[i];
            long long notes = (currentSum / currentGCD) + 1;
            minNotes = min(minNotes, notes);
        }

        cout << minNotes << endl;
    }
    
    return 0;
}


/*

3
3
1 2 3
3
8 4 2
2
2 2 
*/