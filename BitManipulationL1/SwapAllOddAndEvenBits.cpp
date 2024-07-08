#include <iostream>
using namespace std;

int main() {
    int n = 15;

    // Define masks for odd and even bits
    int om = 0x55555555; // 0101 0101 0101 0101 0101 0101 0101 0101 (in binary)
    int em = 0xAAAAAAAA; // 1010 1010 1010 1010 1010 1010 1010 1010 (in binary)

    // Extract odd and even bits from n
    int odds = (n & om);  // Extract odd bits
    int evens = (n & em); // Extract even bits

    // Shift odd bits left and even bits right to swap them
    odds <<= 1;
    evens >>= 1;

    // Combine swapped odd and even bits back into n
    n = odds | evens;

    cout << n << endl;

    return 0;
}
