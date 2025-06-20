#include <bits/stdc++.h>

using namespace std;

double normalPDF(double x, double mu, double sigma) {
    if (sigma <= 0) return 0.0;
    double coeff = 1 / (sqrt(2 * M_PI) * sigma);
    double exponent = -pow(x - mu, 2) / (2 * sigma * sigma);
    return coeff * exp(exponent);
}

double normalMGF(double mu, double sigma, double t) {
    return exp(mu * t + (sigma * sigma * t * t) / 2);
}

int main() {
    double x = 1.0, mu = 0.0, sigma = 1.0, t = 0.1;
    cout << "Normal PDF f(x = " << x << ") = " << normalPDF(x, mu, sigma) << endl;
    cout << "Normal MGF M_X(t = " << t << ") = " << normalMGF(mu, sigma, t) << endl;
    return 0;
}
