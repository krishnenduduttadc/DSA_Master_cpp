#include <bits/stdc++.h>
using namespace std;

int main() {
    // Hardcoded input for the number of test cases
    int t = 3;  // Number of test cases
    // Hardcoded test case values
    vector<vector<int>> testCases = {
        {3, 7, 6, 4},  // First test case
        {1, 4, 5, 4, 1}, // Second test case
        {1, 2, 3, 4, 5}  // Third test case
    };

    for (int i = 0; i < t; ++i) {
        int n = testCases[i].size(); // Get size of each test case
        deque<int> dq;
        
        // Enqueue the elements into the deque
        for (int j = 0; j < n; ++j) {
            dq.push_back(testCases[i][j]);
        }

        int ans = 0; // Counter for operations
        while (dq.size() > 1) {
            int x = dq.front(), y = dq.back(); // Get front and back elements
            dq.pop_front(); dq.pop_back(); // Remove them from deque
            
            if (x == y) continue; // If they are equal, continue without incrementing ans
            
            ++ans; // Increment operation counter
            
            // Determine which to push back into the deque
            if (x < y) dq.push_back(y - x); // If x < y, push back the difference
            else dq.push_front(x - y); // If x >= y, push front the difference
        }

        // Output the result for the current test case
        cout << ans << '\n'; 
    }

    return 0;
}
