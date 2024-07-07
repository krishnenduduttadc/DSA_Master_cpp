#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int b = 7;

    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    cout << a << endl; // Output: 7
    cout << b << endl; // Output: 5

    return 0;
}
