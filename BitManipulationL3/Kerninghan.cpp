#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int c = 0;

    while (n != 0) {
        int rs = n & -n; // rightmost set bit
        n = n - rs; // clear the rightmost set bit
        c++; // increment count
    }

    cout << c << endl;
    return 0;
}
