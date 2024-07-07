#include <iostream>
using namespace std;

int findPowerOf2(int num) {
    int powerOf2 = 1;
    while (powerOf2 < num) {
        powerOf2 <<= 1;
    }
    return powerOf2;
}

int main() {
    int num = 15; // Find the smallest power of 2 >= 15
    int powerOf2 = findPowerOf2(num);
    cout << "Smallest power of 2 >= " << num << ": " << powerOf2 << endl; // Output: 16

    return 0;
}
