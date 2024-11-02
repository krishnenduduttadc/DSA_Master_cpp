#include <bits/stdc++.h>
using namespace std;

int main() {
    // Hardcoded input for testing
    int t = 4;  // Number of test cases
    vector<pair<int, string>> testCases = {
        {2, "10"},
        {4, "0001"},
        {6, "010111"},
        {10, "1110000010"}
    };

    for (int i = 0; i < t; ++i) {
        int n = testCases[i].first;  // Length of the string
        string s = testCases[i].second;  // The binary string
        int L = 0, R = n - 1;
        deque<char> dq;  // Deque to store characters

        while (L <= R) {
            if (s[L] == '0') dq.push_front('0'); // Add '0' to front if found
            else dq.push_back('1');               // Add '1' to back if found
            
            if (L < R) {
                if (s[R] == '1') dq.push_front('1'); // Add '1' to front if found
                else dq.push_back('0');               // Add '0' to back if found
            }
            ++L; --R;  // Move inward
        }

        // Print the resulting deque
        for (auto c : dq) cout << c;
        cout << '\n';  // Newline after each test case output
    }

    return 0;
}

/*
Test cases:
4
2
10
4
0001
6
010111
10
1110000010
*/
