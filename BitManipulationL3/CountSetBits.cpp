#include <iostream>
using namespace std;

int countSetBits(int num) {
    int count = 0;
    while (num != 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

int main() {
    int num = 11; // Binary: 1011
    int count = countSetBits(num);
    cout << "Number of set bits: " << count << endl;

    return 0;
}
