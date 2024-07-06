#include <iostream>
using namespace std;

bool isPrime(int n, int i) {
    if (n <= 2) {
        return (n == 2) ? true : false;
    }
    if (n % i == 0) {
        return false;
    }
    if (i * i > n) {
        return true;
    }
    return isPrime(n, i + 1);
}

int main() {
    int n = 15;
    if (isPrime(n, 2)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
