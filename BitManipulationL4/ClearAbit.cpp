#include <iostream>
using namespace std;

int main() {
    int num = 6; // Binary: 0110
    int bitmask = ~(1 << 1); // Binary: 1101
    int result = num & bitmask; // Binary: 0100 (Decimal: 4)

    cout << "Result: " << result << endl; // Output: 4

    return 0;
}
