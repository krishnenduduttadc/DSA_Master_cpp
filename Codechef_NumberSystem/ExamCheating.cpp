#include <iostream>
using namespace std;

int countDivisors(int n) {
    int divisors = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) {
                divisors++;
            } else {
                divisors += 2;
            }
        }
    }

    return divisors;
}

int main() {
    // Hardcoded number of test cases
    int t = 1; // Number of test cases

    // Hardcoded pairs of integers
    int test_cases[1][2] = {
        {2, 6} // First and only test case
    };

    for (int i = 0; i < t; i++) {
        int a = test_cases[i][0];
        int b = test_cases[i][1];

        if (a == b)
            cout << -1 << endl; // Output -1 if both numbers are equal
        else
            cout << countDivisors(abs(a - b)) << endl; // Count and output divisors of the absolute difference
    }

    return 0;
}
