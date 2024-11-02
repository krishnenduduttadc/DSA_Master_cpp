#include <iostream>
using namespace std;

int countDivisors(int n) {
    int divisors = 0;

    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (i * i == n) {
                divisors++;
            } else {
                divisors += 2; // Count both i and n/i
            }
        }
    }

    return divisors;
}

int main() {
    // Hardcoded number of test cases
    int t = 3;
    
    // Hardcoded test cases
    int test_cases[] = {16, 17, 18};

    for (int i = 0; i < t; i++) {
        int num = test_cases[i];

        int result = countDivisors(num);
        cout << result << endl; // Output the number of divisors
    }

    return 0;
}
