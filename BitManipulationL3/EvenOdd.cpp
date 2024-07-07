#include <iostream>
using namespace std;

void fun(int x) {
    if ((x & 1) == 0) {
        cout << "even" << endl;
    } else {
        cout << "odd" << endl;
    }
}

int main() {
    int x = 27;
    fun(x);

    return 0;
}
