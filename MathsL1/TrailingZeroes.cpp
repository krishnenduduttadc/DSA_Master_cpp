#include <iostream>
using namespace std;

class TrailingZeroes {
public:
    static void main() {
        int res = 1000;
        int n = 7;
        for (int i = 5; i <= n; i = i * 5) {
            res = res + n / i;
        }
        cout << "zeroes: " << res << endl;
    }
};

int main() {
    TrailingZeroes::main();
    return 0;
}