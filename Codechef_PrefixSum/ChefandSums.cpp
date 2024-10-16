#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; // Number of test cases
    cin >> T;
    
    while (T--) {
        int N; // Size of the array
        cin >> N;
        
        vector<int> A(N);
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }
        
        // Find the index of the first occurrence of the minimum element
        int minElement = A[0];
        int minIndex = 0;
        
        for (int i = 1; i < N; ++i) {
            if (A[i] < minElement) {
                minElement = A[i];
                minIndex = i;
            }
        }
        
        // Output the 1-based index of the minimum element
        cout << minIndex + 1 << "\n";
    }
    
    return 0;
}


/*
2
3
1 2 3
4
2 1 3 1
*/