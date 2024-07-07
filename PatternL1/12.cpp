#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int a = 0, b = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            int c = a + b;
            cout << a << "	";
            a = b;
            b = c;
        }

        cout << endl;
    }

    return 0;
}
