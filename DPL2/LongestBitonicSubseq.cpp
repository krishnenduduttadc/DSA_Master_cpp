#include <iostream>
#include <vector>
using namespace std;

int LongestBitonicSubseq(int arr[], int n) {
    vector<int> lis(n, 1); // lis[i] will store the length of LIS ending at index i
    vector<int> lds(n, 1); // lds[i] will store the length of LDS starting at index i

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[j] <= arr[i]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (arr[j] <= arr[i]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    int omax = 0; 
    for (int i = 0; i < n; i++) {
        omax = max(omax, lis[i] + lds[i] - 1);
    }

    return omax;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << LongestBitonicSubseq(arr, n) << endl;

    return 0;
}
