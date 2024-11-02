#include <iostream>
#include <stack>
using namespace std;

int main() {
    int t;
    cin >> t; // Read number of test cases

    while (t--) {
        int N;
        cin >> N; // Read number of bars in histogram
        long A[N]; // Array to hold the heights of the histogram bars
        for (int i = 0; i < N; i++)
            cin >> A[i]; // Read the heights

        stack<int> S; // Stack to keep track of bar indices
        S.push(-1); // Sentinel value to handle the case when stack is empty
        long res = 0; // Variable to store the maximum area

        for (int i = 0; i < N; i++) {
            int x = A[i];
            // Calculate area for bars in the stack that are taller than the current bar
            while (S.top() != -1 && A[S.top()] >= x) {
                int y = S.top(); // Index of the top bar
                S.pop();
                // Width is (current index - 1 - index of the new top of stack)
                res = max(res, A[y] * (i - 1 - S.top()));
            }
            S.push(i); // Push current bar index onto the stack
        }

        // Calculate area for remaining bars in the stack
        while (S.top() != -1) {
            int y = S.top();
            S.pop();
            // Width is (total bars - 1 - index of the new top of stack)
            res = max(res, A[y] * (N - 1 - S.top()));
        }

        cout << res << endl; // Print the maximum area for the current histogram
    }
    
    return 0;
}

/*
Hardcoded Input:
3
4
2 6 8 4
4
5 10 5 2
2
5 5

Expected Output:
16
50
10
*/
