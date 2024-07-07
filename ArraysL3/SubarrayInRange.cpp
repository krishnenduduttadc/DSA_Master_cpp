#include <iostream>
using namespace std;

void printSubarrayInRange(int arr[], int si, int ei) {
    for (int i = si; i <= ei; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int si = 0;
    int ei = 2;

    printSubarrayInRange(arr, si, ei);

    return 0;
}
