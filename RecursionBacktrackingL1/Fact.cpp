#include <iostream>

using namespace std;

int fact(int n) {
    if (n == 0) {
        return 1;
    } else {
        int prev = fact(n - 1);
        return n * prev;
    }
}

int main() {
    cout << fact(6) << endl;
    return 0;
}
