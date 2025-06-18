#include <iostream>
using namespace std;

int findSum(int A[], int N) {
    if (N <= 0) {
        return 0;
    }
    return findSum(A, N - 1) + A[N - 1];
}

int main() {
    static int arr[] = { 1, 2, 3, 4, 5 };
    cout << findSum(arr, sizeof(arr) / sizeof(arr[0])) << endl;
    return 0;
}
