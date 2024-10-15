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
    
    if (n > 2) {
        primes.insert(n);
    }
    return primes.size();
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int num;
        cin >> num;
        if (num <= 2) {
            cout << 1 << endl;
            continue;
        }
        cout << distinctPrimeFactors(num) << endl;
    }
    
    return 0;
}

/*
2
121
26
*/