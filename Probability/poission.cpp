#include <bits/stdc++.h>

using namespace std;

double poissonPMF(int k, double lambda) {
    if (k < 0 || lambda <= 0) return 0.0;
    return pow(lambda, k) * exp(-lambda) / tgamma(k + 1);
}

double poissonMGF(double lambda, double t) {
    return exp(lambda * (exp(t) - 1));
}

int main() {
    int k = 3;
    double lambda = 5.0, t = 0.1;
    cout << "Poisson PMF P(X = " << k << ") = " << poissonPMF(k, lambda) << endl;
    cout << "Poisson MGF M_X(t = " << t << ") = " << poissonMGF(lambda, t) << endl;
    return 0;
}
