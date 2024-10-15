#include <iostream>
using namespace std;

long long collatz_steps(long long n) {
    if (n == 1)
        return 0;
    else if (n % 2 == 0)
        return 1 + collatz_steps(n / 2);
    else
        return 1 + collatz_steps(3 * n + 1);
}

int main() {
    long long n;
    cin >> n;
    cout << collatz_steps(n) << endl;
    return 0;
}



/*
6
*/