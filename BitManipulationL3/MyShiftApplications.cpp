#include <iostream>
using namespace std;

int main() {
    int x = 22; // Binary: 10110

    int k = 3;
    int res1 = x | (1 << k); // Set k-th bit of x to 1
    cout << res1 << endl;    // Output: 30 (binary: 11110)

    k = 2;
    int res2 = x & ~(1 << k); // Set k-th bit of x to 0
    cout << res2 << endl;     // Output: 18 (binary: 10010)

    k = 2;
    int res3 = x ^ (1 << k); // Invert k-th bit of x
    cout << res3 << endl;    // Output: 18 (binary: 10010)

    return 0;
}
