#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int sp = 0; sp < n; sp++) {
        for (int ep = sp; ep < n; ep++) {
            for (int i = sp; i <= ep; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
