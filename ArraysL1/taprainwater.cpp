#include <iostream>
#include <algorithm>
using namespace std;

int getWater(int arr[], int n) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        int lmax = arr[i];
        for (int j = 0; j < i; j++) {
            lmax = max(arr[j], lmax);
        }
        int rmax = arr[i];
        for (int j = i + 1; j < n; j++) {
            rmax = max(arr[j], rmax);
        }

        res += min(lmax, rmax) - arr[i];
    }
    return res;
}

int main() {
    int arr[] = {3, 0, 1, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << getWater(arr, n) << endl;
    return 0;
}
