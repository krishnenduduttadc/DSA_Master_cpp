#include <iostream>
using namespace std;

int countLeadingZeros(int num) {
    int leadingZeros = 0;
    while ((num & (1 << 31)) == 0) {
        leadingZeros++;
        num <<= 1;
    }
    return leadingZeros;
}

int main() {
    int num = 7; // Binary: 00000111
    int leadingZeros = countLeadingZeros(num);
    cout << "Leading zeros: " << leadingZeros << endl; // Output: 28

    return 0;
}
