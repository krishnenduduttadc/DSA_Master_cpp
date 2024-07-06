#include <iostream>
using namespace std;

class FastPower {
public:
    static int fastpower(int a, int b) {
        int res = 1;
        while (b > 0) {
            if (b & 1) {
                res = res * a;
            }
            a = a * a;
            b = b >> 1;
        }
        return res;
    }

    static void main() {
        cout << fastpower(3, 5) << endl;
    }
};

int main() {
    FastPower::main();
    return 0;
}
