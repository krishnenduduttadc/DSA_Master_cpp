#include <iostream>

using namespace std;

bool checkKthBit(int n, int k) {
    return (n & (1 << k)) != 0;
}

int main() {
    int n = 8;
    int k = 3;
    cout << boolalpha << checkKthBit(n, k) << endl;
    return 0;
}
