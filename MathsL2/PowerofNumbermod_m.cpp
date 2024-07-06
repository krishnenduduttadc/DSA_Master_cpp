#include <iostream>
using namespace std;

class PowerofNumbermod_m {
public:
    static void main() {
        int a = 10;
        int n = 5;
        long long ans = 1;
        int m = 1000000007;

        for (int i = 1; i <= n; i++) {
            ans = (ans * static_cast<long long>(a)) % m;
        }

        cout << ans << endl;
    }
};

int main() {
    PowerofNumbermod_m::main();
    return 0;
}