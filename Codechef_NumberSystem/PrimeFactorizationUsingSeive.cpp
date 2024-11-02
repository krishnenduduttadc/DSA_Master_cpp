#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001; // Maximum number for sieve
int spf[MAXN + 1]; // Smallest prime factor for each number

void Sieve() {
    spf[1] = 1; // SPF for 1 is defined as 1
    for (int i = 2; i < MAXN; i++) {
        spf[i] = i; // Initially, each number is its own SPF
    }
  
    for (int i = 2; i * i < MAXN; i++) {
        if (spf[i] == i) { // i is prime
            for (int j = 2 * i; j < MAXN; j += i) {
                if (spf[j] == j) { // Marking SPF only if not marked yet
                    spf[j] = i;
                }
            }
        }
    }
}

vector<int> getFactorization(int x) {
    vector<int> ret;
    while (x != 1) {
        ret.push_back(spf[x]); // Store the smallest prime factor
        x = x / spf[x]; // Divide x by its SPF
    }
    return ret;
}

int main() {
    int n;
    cout << "Enter a number to factor: ";
    cin >> n; // User input for the number to factor

    // Ensure the number is within bounds
    if (n < 1 || n >= MAXN) {
        cout << "Please enter a number between 1 and " << MAXN - 1 << "." << endl;
        return 1;
    }

    Sieve(); // Compute the smallest prime factors
    vector<int> V = getFactorization(n); // Get the factors of n

    cout << "Prime factors of " << n << " are: ";
    for (int i = 0; i < V.size(); i++) {
        cout << V[i];
        if (i != V.size() - 1) {
            cout << " x "; // Format output with 'x' between factors
        }
    }
    cout << endl; // New line after output

    return 0;
}
