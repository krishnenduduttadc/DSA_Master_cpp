#include <iostream>
using namespace std;

string Binary(int n) {
    if (n == 0) {
        return "";
    }
    return Binary(n / 2) + to_string(n & 1);
}

int main() {
    int n = 27; // Hardcoded input
    // Special case for 0 since the recursive function won't return "0"
    if (n == 0) {
        cout << "0" << endl;
    } else {
        cout << Binary(n) << endl; // Output the binary representation of n
    }
    return 0;
}
