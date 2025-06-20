#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeTwoSortedSubArray(vector<int>& a, int s, int m, int e) {
    vector<int> temp(e - s + 1);
    int p1 = s;
    int p2 = m + 1;
    int p3 = 0;

    while (p1 <= m && p2 <= e) {
        if (a[p1] < a[p2]) {
            temp[p3] = a[p1];
            p3++;
            p1++;
        } else {
            temp[p3] = a[p2];
            p3++;
            p2++;
        }
    }

    while (p1 <= m) {
        temp[p3] = a[p1];
        p3++;
        p1++;
    }

    while (p2 <= e) {
        temp[p3] = a[p2];
        p3++;
        p2++;
    }

    for (int i = 0; i < temp.size(); i++) {
        a[s + i] = temp[i];
    }

    return a;
}

int main() {
    vector<int> A = {1, 3, 5, 7, 2, 4, 6, 8};
    int s = 0;
    int m = 3; // Middle index of the first sorted subarray
    int e = 7; // End index of the second sorted subarray

    vector<int> result = mergeTwoSortedSubArray(A, s, m, e);

    cout << "Merged array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
