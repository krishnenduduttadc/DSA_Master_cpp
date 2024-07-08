#include <iostream>
using namespace std;

int main() {
    int n = 14;

    // Calculate (7 * n) / 8 using bitwise operations
    int v = (((n << 3) - n) >> 3);

    cout << v << endl;

    return 0;
}
