#include <iostream>
using namespace std;

int main() {
    int n = 4;
    for (int b = 0; b < (1 << n); b++) {
        cout << b << endl;
    }

    return 0;
}
