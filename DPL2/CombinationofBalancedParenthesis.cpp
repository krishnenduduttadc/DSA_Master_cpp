#include <iostream>
using namespace std;

void bal(int n) {
    int dp[n + 1];

    dp[0] = 1;
    dp[1] = 1;

    for (int i = 2; i <= n; i++) {
        dp[i] = 0; // Initialize dp[i] to 0
        int inside = i - 1;
        int outside = 0;

        while (inside >= 0) {
            dp[i] += dp[inside] * dp[outside];
            inside--;
            outside++;
        }
    }
    cout << dp[n] << endl;
}

int main() {
    int n = 4;

    bal(n);

    return 0;
}
