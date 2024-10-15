#include <iostream>
using namespace std;

void print_pattern(int n) {
    if (n == 0) {
        return;
    }
    for (int i = 0; i < n; ++i) {
        cout << "*";
    }
    cout << endl;
    print_pattern(n - 1);
}

int main() {
    int n;
    cin >> n;
    print_pattern(n);
    return 0;
}



/*
4

*/