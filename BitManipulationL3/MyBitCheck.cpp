#include <iostream>
using namespace std;

void bitChecker(int x, int k) {
    if ((x & (1 << k)) != 0) {
        cout << k << "th bit is 1" << endl;
    } else {
        cout << k << "th bit is 0" << endl;
    }
}

int main() {
    int x = 22; // Binary: 10110
    for (int k = 0; k <= 4; ++k) {
        bitChecker(x, k);
    }

    return 0;
}
