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
        
        // Find the largest power of 2 less than or equal to N
        int power = 1;
        while ((power << 1) <= N) {
            power <<= 1;
        }
        
        // Calculate the sizes of the two potential largest subarrays
        int length1 = N - power + 1;
        int length2 = power / 2;
        
        // The answer is the maximum of these two lengths
        cout << max(length1, length2) << "\n";
    }

    return 0;
}


/*
5
1
2
3
4
7

*/