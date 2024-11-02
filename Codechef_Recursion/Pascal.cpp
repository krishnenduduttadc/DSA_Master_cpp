#include <iostream>
using namespace std;

// Recursive function to find the value at Nth row and Mth column
int findPascalsValue(int N, int M) {
    // Base cases
    if (M == 0 || M == N) {
        return 1; // Edge values are always 1
    }
    if (M > N) {
        cerr << "Error: Invalid Input" << endl; // Error handling for invalid indices
        exit(1);
    }
    // Recursive step: value is the sum of the values above it
    return findPascalsValue(N - 1, M - 1) + findPascalsValue(N - 1, M);
}

int main() {
    // Hardcoded input values for N and M
    int N = 4; // Example: 4th row
    int M = 2; // Example: 2nd column

    int result = findPascalsValue(N, M);
    cout << result << endl; // Output the result

    return 0;
}
