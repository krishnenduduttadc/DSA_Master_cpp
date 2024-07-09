#include <iostream>

using namespace std;

int toggleKthBit(int n, int k) {
    int ans = n ^ (1 << k);
    return ans;
}

int main() {
    int n = 7;
    int k = 2;

    int result = toggleKthBit(n, k);
    cout << result << endl; // Expected output: 3

    return 0;
}
