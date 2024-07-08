#include <iostream>
using namespace std;

int solution(int arr[], int n) {
    int ans = 0;

    for (int i = 0; i < n; i++) {
        ans ^= (2 * arr[i]);
    }

    return ans;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << solution(arr, n) << endl;

    return 0;
}
