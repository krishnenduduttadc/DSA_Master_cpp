#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int R = a % b;
        a = b;
        b = R;
    }
    return a; // Return the GCD
}

int main() {
    // Hardcoded number of test cases
    int t = 3; // Number of test cases

    // Hardcoded test cases
    int test_cases[3][51] = {
        {2, 4, 4},        // First test case
        {3, 2, 3, 4},     // Second test case
        {4, 3, 15, 9, 6}  // Third test case
    };

    for (int k = 0; k < t; k++) {
        int n = test_cases[k][0]; // Number of elements in the current test case
        int A[51]; // Array to hold the elements
        for (int i = 0; i <= n; i++) {
            A[i] = test_cases[k][i]; // Fill the array with hardcoded values
        }

        int g = A[1]; // Initialize GCD with the first element
        for (int i = 2; i <= n; i++)
            g = gcd(g, A[i]); // Compute GCD for the array

        for (int i = 1; i <= n; i++)
            cout << A[i] / g << " "; // Output the array elements divided by GCD
        cout << endl; // New line after each test case
    }

    return 0;
}
