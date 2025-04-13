#include <iostream>
using namespace std;

int p(int n) {
    int i = 1;
    while (i * 2 <= n) {
        i = i * 2;
    }
    return i;
}

int s(int n) {
    int h = p(n);
    int l = n - h;
    return 2 * l + 1;
}

int main() {
    int n = 5;
    cout << s(n) << endl;
    return 0;
}
