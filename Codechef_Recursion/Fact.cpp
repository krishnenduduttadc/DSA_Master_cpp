#include <iostream>
using namespace std;

int Factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * Factorial(n - 1);
}

int main() {
    int n = 5; // Hardcoded input
    cout << Factorial(n) << endl; // Output the factorial of n
    return 0;
}
