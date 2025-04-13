#include <iostream>
using namespace std;

void powerOf2(int x) {
    if ((x & (x - 1)) == 0) {
        cout << x << " is Power of two" << endl;
    } else {
        cout << x << " is not Power of two" << endl;
    }
}

int main() {
    int x = 9;
    for (int i = 1; i <= 32; i++) {
        powerOf2(i);
    }

    return 0;
}
