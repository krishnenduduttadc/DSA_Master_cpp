#include <iostream>
#include <cmath>
using namespace std;


    static void start() {
        int n = 56789;
        int k = 2;

        int temp = n;
        int d = 0;
        while (temp > 0) {
            temp = temp / 10;
            d = d + 1;
        }

        k = k % d;
        if (k < 0) {
            k = k + d;
        }

        int od = n % static_cast<int>(pow(10, k));
        int a = od * static_cast<int>(pow(10, d - k));
        int g = n / static_cast<int>(pow(10, k));
        cout << a + g << endl;
    }


int main() {
    start();
    return 0;
}
