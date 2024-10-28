#include <bits/stdc++.h>
using namespace std;

int firstOccurrence(int arr[], int n, int target) {
    int l = -1;
    int r = n;
    while (r - l > 1) {
        int middle = (l + r) / 2;
        if (arr[middle] >= target) {
            r = middle;
        } else {
            l = middle;
        }
    }
    return r;
}

int main() {
    int n = 7;
    int binaryArray[] = {0, 0, 1, 1, 1, 1, 1};

    int first_one_index = firstOccurrence(binaryArray, n, 1);
    int total_ones = n - first_one_index;
    cout << total_ones << endl;

    return 0;
}
