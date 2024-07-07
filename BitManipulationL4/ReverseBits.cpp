#include <iostream>
using namespace std;

int reverseBits(int num) {
    int reversed = 0;
    for (int i = 0; i < 32; i++) {
        reversed = (reversed << 1) | ((num >> i) & 1);
    }
    return reversed;
}

int main() {
    int num = 25; // Binary: 00011001
    int reversed = reverseBits(num);
    
    cout << reversed << endl; // Output: 147

    return 0;
}
