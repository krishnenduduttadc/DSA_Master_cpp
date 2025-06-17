#include <iostream>
using namespace std;


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


int main() {
    main();
    return 0;
}
