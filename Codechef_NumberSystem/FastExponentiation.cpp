#include <iostream>
using namespace std;

// Function to compute a^b using fast exponentiation (iterative)
long long fastpow(long long a, long long b) {
    long long res = 1; // Initialize result
    while (b > 0) {
        if (b & 1) // If b is odd, multiply the result by a
            res = res * a;
        a = a * a;  // Square the base
        b >>= 1;    // Divide b by 2 (right shift)
    }
    return res;
}

int main() {
    long long a, b;
    cout << "Enter base and exponent: ";
    cin >> a >> b;

    // Calculate a^b using fast exponentiation
    long long result = fastpow(a, b);

    // Display the result
    cout << a << "^" << b << " = " << result << endl;

    return 0;
}
