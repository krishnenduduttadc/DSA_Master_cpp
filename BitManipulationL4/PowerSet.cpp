#include <iostream>
using namespace std;

void generatePowerSet(char set[], int n) {
    for (int i = 0; i < (1 << n); i++) {
        cout << "{ ";
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                cout << set[j] << " ";
            }
        }
        cout << "}" << endl;
    }
}

int main() {
    char set[] = {'a', 'b', 'c'};
    int n = sizeof(set) / sizeof(set[0]);
    generatePowerSet(set, n);
    
    return 0;
}
