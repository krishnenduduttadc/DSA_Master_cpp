#include <bits/stdc++.h>

using namespace std;

// Helper function to calculate factorial
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

// Function to evaluate the Binomial PMF
double binomialPMF(int n, int k, double p) {
    if (k > n || k < 0 || p < 0 || p > 1) return 0.0;
    double binom_coeff = factorial(n) / (factorial(k) * factorial(n - k));
    return binom_coeff * pow(p, k) * pow(1 - p, n - k);
}

// Moment Generating Function for Binomial
double binomialMGF(int n, double p, double t) {
    return pow(1 - p + p * exp(t), n);
}

// Test the Binomial PMF and MGF functions
int main() {
    int n = 10, k = 3;
    double p = 0.5, t = 0.1;
    cout << "Binomial PMF P(X = " << k << ") = " << binomialPMF(n, k, p) << endl;
    cout << "Binomial MGF M_X(t = " << t << ") = " << binomialMGF(n, p, t) << endl;
    return 0;
}
