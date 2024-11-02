#include <iostream>

using namespace std;

int main() {
    int n = 2, m = 2;
    
    int totalSum = n * m;
    
    if (totalSum % 2 == 0) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << 1 << " ";
            }
            cout << endl;
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}
