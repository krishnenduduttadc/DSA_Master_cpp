#include <iostream>
using namespace std;

void set(int x) {
    for (int i = 0; i < 32; ++i) {
        if (x & (1 << i)) {
            cout << i << endl;
        }
    }
}

int main() {
    int x = 282; // Binary representation: 100011010
    // int x = 7; // Binary representation: 111

    set(x);

    return 0;
}
