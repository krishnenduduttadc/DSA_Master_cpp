#include <iostream>
using namespace std;

int maxone(int arr[], int n) {
    int cnt = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            cnt = 0;
        } else {
            cnt++;
            res = max(res, cnt);
        }
    }
    return res;
}

int maxconone(int arr[], int n) {
    int res = 0, curr = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) {
            curr = 0;
        } else {
            curr++;
            res = max(res, curr);
        }
    }
    return res;
}

int main() {
    int arr[] = {0, 1, 1, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxone(arr, n) << endl;
    cout << maxconone(arr, n) << endl;

    return 0;
}
