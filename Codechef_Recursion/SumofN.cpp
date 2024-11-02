#include <iostream>
using namespace std;

int sum(int n) {
    cout << "Sum(" << n << ") is called" << endl; // Debug output
    if (n == 1) {
        cout << "Base Condition reached" << endl; // Base case debug output
        return 1;
    }
    int sumN1 = sum(n - 1); // Recursive call
    cout << "Sum(" << n << ") = " << n << " + Sum(" << n - 1 << ")" << endl; // Intermediate output
    int sumN = n + sumN1; // Calculate sum
    cout << "Sum(" << n << ") = " << n << " + " << sumN1 << endl; // Result of current sum
    cout << "Sum(" << n << ") is returning " << sumN << endl; // Returning output
    return sumN;
}

int main() {
    cout << "Sum of first 5 natural numbers is " << sum(5) << endl; // Call with n=5
    return 0;
}
