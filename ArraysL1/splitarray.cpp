#include <iostream>
using namespace std;

bool splitArray(int arr[], int start, int end, int lSum, int rSum) {
    if (start > end) {
        return lSum == rSum;
    }
    if (arr[start] % 5 == 0) {
        return splitArray(arr, start + 1, end, lSum + arr[start], rSum);
    } else if (arr[start] % 3 == 0) {
        return splitArray(arr, start + 1, end, lSum, rSum + arr[start]);
    } else {
        return splitArray(arr, start + 1, end, lSum + arr[start], rSum) || splitArray(arr, start + 1, end, lSum, rSum + arr[start]);
    }
}

bool splitArray(int arr[], int n) {
    return splitArray(arr, 0, n - 1, 0, 0);
}

int main() {
    int arr[] = {1, 4, 7, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << (splitArray(arr, n) ? "true" : "false") << endl;
    return 0;
}
