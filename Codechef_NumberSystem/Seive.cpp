#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> SieveOfEratosthenes(int n) {
    vector<bool> prime(n + 1, true);
    vector<int> primes;
    prime[1] = false;

    for (int p = 2; p * p <= n; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= n; i += p) {
                prime[i] = false;
            }
        }
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

int main() {
    int n = 30;
    vector<int> primes = SieveOfEratosthenes(n);
    
    cout << "Prime numbers up to " << n << " are: ";
    for (int p : primes) {
        cout << p << " ";
    }
    cout << endl;

    return 0;
}
