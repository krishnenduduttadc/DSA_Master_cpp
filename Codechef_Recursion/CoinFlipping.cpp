#include <bits/stdc++.h>
using namespace std;

int countWays(int S) {
    if (S < 0) return 0;
    if (S == 0) return 1;
    return countWays(S - 1) + countWays(S - 2);
}

int main() {
    int S = 3; // Hardcoded input
    cout << countWays(S) << endl; // Output the number of ways to reach sum S
    return 0;
}
