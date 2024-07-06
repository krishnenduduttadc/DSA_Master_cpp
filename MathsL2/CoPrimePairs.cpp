#include <iostream>
using namespace std;

class CoPrimePairs {
public:
    static void main() {
        int n = 10;

        for (int i = 0; i < n / 2; i++) {
            cout << 2 * i + 1 << " " << 2 * i + 2 << endl;
        }
    }
};

int main() {
    CoPrimePairs::main();
    return 0;
}
