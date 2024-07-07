#include <iostream>
using namespace std;

int hammingDistance(int x, int y) {
    int xorResult = x ^ y;
    int count = 0;
    while (xorResult != 0) {
        count += xorResult & 1;
        xorResult >>= 1;
    }
    return count;
}

int main() {
    cout << hammingDistance(10, 12) << endl; // Output: 2

    return 0;
}
