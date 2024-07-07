#include <iostream>
using namespace std;

int pairSum(int arr[], int n, int num) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] + arr[j] == num) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int arr[] = {1, 3, 6, 2, 5, 4, 3, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << pairSum(arr, n, 9) << endl;
    return 0;
}
