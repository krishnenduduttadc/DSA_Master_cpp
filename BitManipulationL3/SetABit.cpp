#include <iostream>
using namespace std;

int main() {
    int num = 5; // Binary: 0101
    int bitmask = 1 << 2; // Binary: 0100
    int result = num | bitmask; // Binary: 0101 (Decimal: 5)
    
    cout << result << endl; // Output: 5

    return 0;
}
