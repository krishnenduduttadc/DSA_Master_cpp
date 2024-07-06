#include <iostream>
#include <unordered_set>
using namespace std;

int pairWithSumX(int arr[], int n, int X) {
    unordered_set<int> us;
    for (int i = 0; i < n; i++) {
        if (us.find(X - arr[i]) != us.end()) {
            return 1;
        }
        us.insert(arr[i]);
    }
    return 0;
}

int main() {
    int arr[] = {3, 8, 4, 7, 6, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    int x = 14;
    cout << pairWithSumX(arr, len, x) << endl;
    return 0;
}
