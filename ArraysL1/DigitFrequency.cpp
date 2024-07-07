#include <iostream>
using namespace std;

int getDigitFrequency(int n, int d) {
    int cnt = 0;
    while (n > 0) {
        if (n % 10 == d) {
            cnt++;
        }
        n = n / 10;
    }
    return cnt;
}

int main() {
    int n = 994543234;
    int d = 4;
    int f = getDigitFrequency(n, d);
    cout << f << endl;

    return 0;
}
