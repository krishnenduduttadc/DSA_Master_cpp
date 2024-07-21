#include <iostream>
using namespace std;

long long noOfChords(int n) {
    long long* dp = new long long[n + 1]; // Dynamically allocate the dp array
    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = 0; // Initialize dp[i] to 0
        int l = 0;
        int r = i - 1;
        while (l <= i - 1) {
            dp[i] += dp[l] * dp[r];
            l++;
            r--;
        }
    }

    long long result = dp[n]; // Store the result before deallocating memory
    delete[] dp; // Deallocate memory to prevent memory leaks
    return result;
}

int main() {
    int n = 6;
    cout << "Number of non-intersecting chords for " << n << " points: " << noOfChords(n) << endl;
    return 0;
}
