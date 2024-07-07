#include <iostream>
using namespace std;

int nos(int arr[], int n) {
    long long ans = 0;
    int even = 0;
    int odd = 0;
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum % 2 == 0) {
            ans += odd;
            even++;
        } else {
            ans += 1 + even;
            odd++;
        }
    }
    return ans % 1000000007;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << nos(arr, n) << endl;

    return 0;
}
