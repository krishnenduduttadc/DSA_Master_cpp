#include <iostream>

using namespace std;

bool checkBit(int n, int k) {
    return (n & (1 << k)) != 0;
}

int unsetKthBit(int n, int k) {
    if (checkBit(n, k)) {
        n ^= (1 << k); // Toggle the k-th bit
    }
    return n;
}

int main() {
    int n = 7;
    int k = 2;

    if (checkBit(n, k)) {
        int result = unsetKthBit(n, k);
        cout << result << endl; // Expected output: 3
    } else {
        cout << n << endl; // No change, output: 7
    }

    return 0;
}
