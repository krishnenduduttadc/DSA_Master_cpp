#include <iostream>
using namespace std;

int arrayRotateCheck(int arr[], int n) {
    int minIndex = 0;
    int min = arr[0];
    
    // Finding the minimum element and its index
    for (int i = 1; i < n; i++) {
        if (arr[i] < min) {
            min = arr[i];
            minIndex = i;
        }
    }
    
    return minIndex;
}

int main() {
    int arr[] = {5, 6, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int p = arrayRotateCheck(arr, n);
    cout << p << endl;

    return 0;
}
