#include <iostream>
using namespace std;

class GCD {
public:
    static int gcd(int a, int b) {
        if (b == 0) {
            return a;
        } else {
            return gcd(b, a % b);
        }
    }

    static void main() {
        cout << gcd(30, 36) << endl;
    }
};

int main() {
    GCD::main();
    return 0;
}
