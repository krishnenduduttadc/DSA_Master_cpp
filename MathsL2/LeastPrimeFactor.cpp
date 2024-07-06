#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class LeastPrimeFactor {
public:
    vector<int> leastPrimeFactor(int n) {
        vector<int> spf(n + 1);

        // Initialize spf array with each number's smallest prime factor being itself
        for (int i = 1; i <= n; i++) {
            spf[i] = i;
        }

        // Sieve method to find smallest prime factors
        for (int i = 2; i * i <= n; i++) {
            if (spf[i] == i) { // i is a prime number
                for (int j = i * i; j <= n; j += i) {
                    if (spf[j] == j) { // Update spf[j] only if it is not updated yet
                        spf[j] = i;
                    }
                }
            }
        }

        return spf;
    }
};

int main() {
    LeastPrimeFactor lpf;

    // Hard-coded input
    int n = 10;

    vector<int> result = lpf.leastPrimeFactor(n);

    // Print the result
    cout << "Least Prime Factors from 1 to " << n << ": ";
    for (int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
