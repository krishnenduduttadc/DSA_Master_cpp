#include <iostream>
using namespace std;

int main() {
    int x = 5;

    for(int i = 1; i <= 10; i++){
        int v = x * i;
        cout << x << " * " << i << " = " << v << endl;
    }

    return 0;
}
