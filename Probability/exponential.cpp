#include <bits/stdc++.h>

using namespace std;

// Function to evaluate the Exponential PDF
double exponentialPDF(double x, double lambda) {
    if (x < 0 || lambda <= 0) return 0.0;
    return (1 / lambda) * exp(-x / lambda);
}

// Moment Generating Function for Exponential
double exponentialMGF(double lambda, double t) {
    if (t >= 1 / lambda) return INFINITY; // MGF diverges for t >= 1/lambda
    return 1 / (1 - lambda * t);
}

// Test the Exponential PDF and MGF functions
int main() {
    double x = 1.0, lambda = 5.0, t = 0.1;
    cout << "Exponential PDF f(x = " << x << ") = " << exponentialPDF(x, lambda) << endl;
    cout << "Exponential MGF M_X(t = " << t << ") = " << exponentialMGF(lambda, t) << endl;
    return 0;
}
