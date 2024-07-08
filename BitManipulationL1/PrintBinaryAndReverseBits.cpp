#include <iostream>
using namespace std;

void printBinaryAndReverseBits(int n) {
    bool flag = false;
    int rev = 0;
    int j = 0;

    for (int i = 31; i >= 0; i--) {
        int mask = (1 << i);

        if (flag) {
            if ((n & mask) != 0) {
                cout << 1;
                int smask = (1 << j);
                rev |= smask;
            } else {
                cout << 0;
            }
            j++;
        } else {
            if ((n & mask) != 0) {
                flag = true;
                cout << 1;
                int smask = (1 << j);
                rev |= smask;
                j++;
            } else {
                cout << 0;
            }
        }
    }

    cout << endl;
    cout << rev << endl;
}

int main() {
    int n = 7;
    printBinaryAndReverseBits(n);
    return 0;
}
