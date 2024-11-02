#include <iostream>
#include <vector>
using namespace std;

// Function to return the prime factors of a number n
vector<int> factor(int n) {
    vector<int> ret;
    for (int i = 2; i * i <= n; i++) {
        while (n % i == 0) {
            ret.push_back(i); // Store the prime factor
            n /= i;           // Reduce n
        }
    }
    if (n > 1) {
        ret.push_back(n); // If n is still greater than 1, it's a prime factor
    }
    return ret;
}

int main() {
    int n = 20; // Hardcoded number to factor

    // Get the prime factors
    vector<int> factors = factor(n);

    // Display the factors
    cout << "Prime factors of " << n << " are: ";
    for (size_t i = 0; i < factors.size(); i++) {
        cout << factors[i];
        if (i != factors.size() - 1) {
            cout << " x "; // Formatting the output with 'x' between factors
        }
    }
    cout << endl;

    return 0;
}
