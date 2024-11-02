#include <bits/stdc++.h>
using namespace std;

// Function to count pretty numbers in the range [L, R]
int countPrettyNumbers(int L, int R) {
    int count = 0;
    for (int i = L; i <= R; ++i) {
        int lastDigit = i % 10;
        if (lastDigit == 2 || lastDigit == 3 || lastDigit == 9) {
            ++count;
        }
    }
    return count;
}

int main() {
    // Hardcoded input values
    int T = 2;  // Number of test cases
    vector<pair<int, int>> testCases = {{1, 10}, {11, 33}};  // Hardcoded ranges

    for (int t = 0; t < T; ++t) {
        int L = testCases[t].first;
        int R = testCases[t].second;
        cout << countPrettyNumbers(L, R) << endl;  // Output the count of pretty numbers
    }

    return 0;
}
