#include <iostream>
using namespace std;

int flipBitsToConvert(int a, int b) {
    int c = a ^ b; // XOR to find differing bits
    
    int z = 0;
    while(c != 0) {
        int rsb = (c & -c); // Rightmost set bit
        c = c - rsb; // Clear the rightmost set bit
        z++; // Increment count of flipped bits
    }

    return z;
}

int main() {
    int a = 2;
    int b = 4;

    int flips = flipBitsToConvert(a, b);

    cout << flips << endl;

    return 0;
}
