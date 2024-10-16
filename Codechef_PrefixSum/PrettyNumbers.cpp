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
    int T;
    cin >> T;  // Read the number of test cases
    while (T--) {
        int L, R;
        cin >> L >> R;  // Read the range L to R for each test case
        cout << countPrettyNumbers(L, R) << endl;  // Output the count of pretty numbers
    }
    return 0;
}



/*
2
1 10
11 33
*/