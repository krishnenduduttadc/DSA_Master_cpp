#include <iostream>
#include <climits>
using namespace std;

int main() {
    int arr[] = {15, 30, 40, 4, 11, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min = INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    int max = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    cout << max - min << endl;

    return 0;
}
