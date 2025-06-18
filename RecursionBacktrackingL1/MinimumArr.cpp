#include <iostream>
#include <climits> 
using namespace std;

int getMin(int arr[], int i, int n) {
    if (n == 1) {
        return arr[i];
    } else {
        return min(arr[i], getMin(arr, i + 1, n - 1));
    }
}

int getMax(int arr[], int i, int n) {
    if (n == 1) {
        return arr[i];
    } else {
        return max(arr[i], getMax(arr, i + 1, n - 1));
    }
}

int main() {
    int arr[] = {12, 8, 45, 67, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum element of array: " << getMin(arr, 0, n) << endl;
    cout << "Maximum element of array: " << getMax(arr, 0, n) << endl;
    return 0;
}
