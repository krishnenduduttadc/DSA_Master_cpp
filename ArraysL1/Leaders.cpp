#include <iostream>
using namespace std;

void leaders(int arr[], int n) {
    int curr = arr[n - 1];
    cout << curr << " ";

    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > curr) {
            curr = arr[i];
            cout << curr << " ";
        }
    }
}

int main() {
    int arr[] = {7, 10, 4, 10, 6, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    leaders(arr, n);
    cout << endl;

    return 0;
}
