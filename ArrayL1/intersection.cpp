#include <iostream>
#include <unordered_set>
using namespace std;

void intersection(int arr1[], int n, int arr2[], int m) {
    unordered_set<int> s1, s2;

    for (int i = 0; i < n; i++) {
        s1.insert(arr1[i]);
    }
    for (int i = 0; i < m; i++) {
        s2.insert(arr2[i]);
    }

    unordered_set<int> intersect;
    for (int x : s1) {
        if (s2.find(x) != s2.end()) {
            intersect.insert(x);
        }
    }

    for (int x : intersect) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int arr1[] = {2, 6, 8, 5, 4, 3};
    int arr2[] = {2, 3, 4, 7};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    intersection(arr1, n, arr2, m);

    return 0;
}
