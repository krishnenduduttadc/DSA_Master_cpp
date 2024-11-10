#include <bits/stdc++.h>

using namespace std;

// Function to evaluate the Poisson PMF
double poissonPMF(int k, double lambda) {
    if (k < 0 || lambda <= 0) return 0.0;
    return pow(lambda, k) * exp(-lambda) / tgamma(k + 1);
}

// Moment Generating Function for Poisson
double poissonMGF(double lambda, double t) {
    return exp(lambda * (exp(t) - 1));
}

// Test the Poisson PMF and MGF functions
int main() {
    int k = 3;
    double lambda = 5.0, t = 0.1;
    cout << "Poisson PMF P(X = " << k << ") = " << poissonPMF(k, lambda) << endl;
    cout << "Poisson MGF M_X(t = " << t << ") = " << poissonMGF(lambda, t) << endl;
    return 0;
}
