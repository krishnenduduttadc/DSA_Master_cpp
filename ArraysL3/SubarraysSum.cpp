#include <iostream>
using namespace std;

int subarraysSum(int arr[], int n) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        int occ = (i + 1) * (n - i);
        sum = sum + occ * arr[i];
    }

    return sum;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = subarraysSum(arr, n);

    cout << result << endl;

    return 0;
}
