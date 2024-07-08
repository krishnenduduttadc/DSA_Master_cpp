#include <iostream>
using namespace std;

int copySetBitsInRange(int a, int b, int left, int right) {
    int m = (1 << (right - left + 1)) - 1; // Creates a mask of 1s of the required length
    m = (m << (left - 1)); // Shifts the mask to the correct position

    m = (m & a); // Extracts the bits from 'a' that need to be copied
    b = b | m; // Copies the extracted bits to 'b'

    return b; // Returns the result
}

int main() {
    int a = 5;
    int b = 3;
    int left = 1;
    int right = 1;

    b = copySetBitsInRange(a, b, left, right);
    cout << b << endl;

    return 0;
}
