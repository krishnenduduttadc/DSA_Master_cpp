#include <iostream>
using namespace std;


    static void start() {
        int a = 3;
        int b = 4;
        int c = 5;

        if (a > b && a > c) {
            if (a * a == b * b + c * c) {
                cout << true << endl;
            } else {
                cout << false << endl;
            }
        }

        if (b > c && b > a) {
            if (b * b == a * a + c * c) {
                cout << true << endl;
            } else {
                cout << false << endl;
            }
        }

        if (c > a && c > b) {
            if (c * c == b * b + a * a) {
                cout << true << endl;
            } else {
                cout << false << endl;
            }
        }
    }


int main() {
    start();
    return 0;
}
