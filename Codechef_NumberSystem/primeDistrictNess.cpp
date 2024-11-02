#include <iostream>
#include <unordered_set>
using namespace std;

int distinctPrimeFactors(int n) {
    unordered_set<int> primes;
    int x = n;
    for (int i = 2; i * i <= x; i++) {
        while (n % i == 0) {
            n /= i;
            primes.insert(i);
        }
    }
    
    if (n > 1) { // Corrected this line to check for n > 1
        primes.insert(n);
    }
    return primes.size();
}

int main() {
    // Hardcoded input
    int t = 2; // Number of test cases
    int testCases[] = {121, 26}; // The test cases

    for (int i = 0; i < t; i++) {
        int num = testCases[i]; // Get the current test case
        if (num <= 2) {
            cout << 1 << endl; // If num is 2 or less, output 1
            continue;
        }
        cout << distinctPrimeFactors(num) << endl; // Output the number of distinct prime factors
    }
    
    return 0;
}

/*
Hardcoded Input:
2
121
26
*/
