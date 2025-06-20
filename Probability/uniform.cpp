#include <bits/stdc++.h>

using namespace std;

double uniformPDF(double x, double a, double b) {
    if (a >= b) return 0.0;
    return (x >= a && x <= b) ? (1 / (b - a)) : 0.0;
}

double uniformMGF(double a, double b, double t) {
    if (t == 0) return 1.0;
    return (exp(b * t) - exp(a * t)) / (t * (b - a));
}

int main() {
    double x = 2.5, a = 0.0, b = 5.0, t = 0.1;
    cout << "Uniform PDF f(x = " << x << ") = " << uniformPDF(x, a, b) << endl;
    cout << "Uniform MGF M_X(t = " << t << ") = " << uniformMGF(a, b, t) << endl;
    return 0;
}
