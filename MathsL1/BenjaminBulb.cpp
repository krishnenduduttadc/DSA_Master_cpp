#include <iostream>
using namespace std;

class BenjaminBulb {
public:
    static void main() {
        int n = 5;
        int i = 1;
        while (i * i <= n) {
            cout << i * i << endl;
            i++;
        }
    }
};

int main() {
    BenjaminBulb::main();
    return 0;
}
