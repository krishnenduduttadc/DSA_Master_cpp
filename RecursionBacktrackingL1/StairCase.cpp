#include <iostream>
using namespace std;

int staircase(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    if (n == 2) {
        return 2;
    }
    return staircase(n-1) + staircase(n-2) + staircase(n-3);
}

int main() {
    int n = 7;
    cout << staircase(n) << endl;
    return 0;
}
