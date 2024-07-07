#include <iostream>
using namespace std;

int consecutiveNumbersSum(int n) {
    int c = 0;
    for (int k = 1; n > (k * (k - 1) / 2); k++) {
        int n1 = n - (k * (k - 1) / 2);

        if (n1 % k == 0) {
            c++;
        }
    }

    return c;
}

int main() {
    int num = 5;
    int res = consecutiveNumbersSum(num);
    cout << res << endl;
    return 0;
}
