#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Hardcoded number of test cases
    int t = 3;
    vector<vector<int>> testCases = {
        {2, 2, 100, 20, 40, 2, 1},  // Test case 1
        {1, 2, 10, 10, 20},         // Test case 2
        {3, 2, 1, 30, 30, 30, 40, 20} // Test case 3
    };

    for (int caseNum = 0; caseNum < t; caseNum++) {
        // Reading values from hardcoded input
        int n = testCases[caseNum][0];
        int m = testCases[caseNum][1];
        int h = testCases[caseNum][2];
        vector<int> a(testCases[caseNum].begin() + 3, testCases[caseNum].begin() + 3 + n);
        vector<int> b(testCases[caseNum].begin() + 3 + n, testCases[caseNum].begin() + 3 + n + m);
        
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        long long sum = 0;
        for (int i = 0; i < min(n, m); i++)
            sum += min(1ll * a[i], 1ll * b[i] * h);
        
        cout << sum << "\n"; // Output the sum for the current test case
    }

    return 0;
}

/*
Expected Output:
60
10
50
*/
