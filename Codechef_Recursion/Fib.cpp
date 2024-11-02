#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 1) {
        return 0; // F(1) = 0
    }
    if (n == 2) {
        return 1; // F(2) = 1
    }
    return fib(n - 1) + fib(n - 2); // Recursive calculation for F(n)
}

int main() {
    int n = 5; // Hardcoded input
    cout << fib(n) << endl; // Output the Fibonacci number at position n
    return 0;
}
