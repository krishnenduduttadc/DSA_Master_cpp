#include <iostream>
using namespace std;

class Fact {
public:
    static void main() {
        int n = 10;
        int res = 1;
        for (int i = 2; i <= n; i++) {
            res = res * i;
        }
        cout << res << endl;
    }
};

int main() {
    Fact::main();
    return 0;
}
