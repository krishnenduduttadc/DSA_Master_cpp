#include <iostream>
using namespace std;

int removeDup(int arr[], int n) {
    int res = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[res - 1]) {
            arr[res] = arr[i];
            res++;
        }
    }
    return res;
}

int main() {
    int arr[] = {2, 2, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int p = removeDup(arr, n);

    cout << "After Removal" << endl;

    for (int i = 0; i < p; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
