#include <iostream>
#include <limits>
using namespace std;

int main() {
    int a = numeric_limits<int>::max(); // 2147483647
    int b = 1;
    int sum = a + b;
    
    if (((a ^ sum) & (b ^ sum)) < 0) {
        cout << "Overflow detected in addition." << endl;
    }

    return 0;
}
