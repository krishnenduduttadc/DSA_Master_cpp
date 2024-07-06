#include <iostream>
using namespace std;

class Palin {
public:
    static void main() {
        int n = 101;
        int temp = n;
        int rev = 0;

        while (temp != 0) {
            int ld = temp % 10;
            rev = rev * 10 + ld;
            temp = temp / 10;
        }

        cout << (rev == n) << endl;
    }
};

int main() {
    Palin::main();
    return 0;
}
