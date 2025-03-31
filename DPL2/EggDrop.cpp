#include <iostream>
#include <climits>
using namespace std;

int eggDrop(int n, int k) {
    // Initialize a 2D array for DP table
    int dp[n + 1][k + 1]; // Array with (n + 1) rows and (k + 1) columns
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill the DP table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i == 1) {
                dp[i][j] = j; // If only one egg is available, we need j trials
            } else if (j == 1) {
                dp[i][j] = 1; // If only one floor is there, one trial needed
            } else {
                int minDrops = INT_MAX;
                // Check all floors from 1 to j to find the minimum drops needed
                for (int floor = 1; floor <= j; floor++) {
                    int breaks = dp[i - 1][floor - 1]; // Egg breaks, check below floors
                    int survives = dp[i][j - floor]; // Egg survives, check above floors
                    int maxDrops = 1 + max(breaks, survives); // Maximum drops needed in worst case
                    minDrops = min(minDrops, maxDrops); // Minimum drops to find the critical floor
                }
                dp[i][j] = minDrops;
            }
        }
    }

    return dp[n][k]; // Return the minimum drops needed
}

int main() {
    int n = 4; // Number of eggs
    int k = 2; // Number of floors

    cout << eggDrop(n, k) << endl; // Output the minimum drops required
    return 0;
}
