#include <iostream>
using namespace std;

void printBinary(int n) {
    if (n == 0) {
        cout << "0" << endl;
        return;
    }

    int bits = sizeof(int) * 8; // Number of bits in an int (typically 32 or 64)
    bool foundOne = false;

    for (int i = bits - 1; i >= 0; i--) {
        int mask = 1 << i;
        if (n & mask) {
            foundOne = true;
            cout << "1";
        } else if (foundOne) {
            cout << "0";
        }
    }
    cout << endl;
}

int main() {
    int n = 7;

    // Calculate rightmost set bit mask
    int rsbm = n & -n;

    // Print the binary representation of rsbm
    printBinary(rsbm);

    return 0;
}
