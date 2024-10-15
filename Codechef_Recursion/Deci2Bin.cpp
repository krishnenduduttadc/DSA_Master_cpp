#include <iostream>
using namespace std;

string Binary(int n) {
    if (n == 0) {
        return "";
    }
    return Binary(n / 2) + to_string(n & 1);
}

int main() {
    int n;
    cin >> n;
    cout << Binary(n) << endl;
    return 0;
}


/*
27

*/