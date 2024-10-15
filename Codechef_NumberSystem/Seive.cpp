#include <iostream>
#include <cstring> // for memset
using namespace std;

// Function to perform the Sieve of Eratosthenes
void SieveOfEratosthenes(int n) {
    // Create a boolean array to mark prime numbers
    bool prime[n + 1];
    memset(prime, true, sizeof(prime)); // Initialize all entries as true (prime)

    // 1 is not a prime number
    prime[1] = false;

    // Perform sieve algorithm
    for (int p = 2; p * p <= n; p++) {
        // If prime[p] is still true, it's a prime
        if (prime[p] == true) {
            // Mark all multiples of p as not prime
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    // Output all prime numbers
    cout << "Prime numbers up to " << n << " are: ";
    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            cout << p << " ";
        }
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the upper limit to find prime numbers: ";
    cin >> n;

    // Call the Sieve of Eratosthenes function
    SieveOfEratosthenes(n);

    return 0;
}
